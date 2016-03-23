#include "bst.h"
using namespace std;

/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
and location. This is a great program for people who wants to create a plan for their summer
break.
*/


table::table()	//constructure to initialize the root
{
	root = NULL;
}

table::~table()	//deallocate the memory
{
	remove_all(root);
}

/* ====================================WRAPPER FUNCTION================================================*/
int table::insert(journal_entry & to_add) //insert the journal entry information into tree structure
{
	return insert(root, to_add);
}
int table::remove_all()	//remove all data items in the tree stucture
{
	return remove_all(root);
}

int table::display_all()	//display all information in the tree structure
{
	return display_all(root);
}

int table::display_location(char * loc)	//display the matched data from the tree structure
{
	return display_location(root,loc);
}

int table::remove(char * loc)	//remove the matched data from the tree structure
{
	return remove(root, loc);
}

int table::count_location(char * loc)	//count how many data items in the tree that matched to arguement
{
	return count_location(root, loc);
}
int table::retrieve_location(char * loc, journal_entry * & found, int count)	//find the matched location in the tree structure and retrieve by passing by reference
{
	found = new journal_entry[count];
	int i = 0;
	return retrieve_location(root, loc, found, i);
}
/*=======================================================================================================*/
int table::load()	//read in the external file
{
        ifstream file_in;
        journal_entry to_add;
        char nam[SIZE], act[SIZE], des[SIZE], loc[SIZE], req[SIZE];
        int rat;

        file_in.open("plan.txt");
	file_in.get(nam, SIZE, ';');		file_in.ignore(SIZE, ';');
	while(!file_in.eof())
	{
                file_in.get(act, SIZE, ';');    file_in.ignore(SIZE, ';');
                file_in.get(des, SIZE, ';');    file_in.ignore(SIZE, ';');
                file_in.get(loc, SIZE, ';');    file_in.ignore(SIZE, ';');
                file_in >> rat; file_in.ignore(SIZE, ';');
                file_in.get(req, SIZE, '\n');   file_in.ignore(SIZE, '\n');
                to_add.create_entry(nam, act, des, loc, rat, req);	//create an tempory journal entry class
		insert(to_add);	//call the insert function to store it into the tree data structure
		file_in.get(nam, SIZE, ';');	file_in.ignore(SIZE, ';');
	}
	return 1;	
}
// RECURSIVELY

int table::insert(node * & root, journal_entry & to_add)	//this function will insert the data into the treee structure
{
	if(!root)	//check to see if root is empty
	{
		root = new node;	
		root -> entry.copy_entry(to_add);
		root -> left = NULL;
		root -> right = NULL;
	}
	else if (to_add.compare(root -> entry) <= 0)	//if the data is less than current root, then traverse left
		insert(root -> left, to_add);
	else	//otherwise traverse right
		insert(root -> right, to_add);
	return 1;
}

int table::remove_all(node * & root)	//this function will remove all data in the tree structure
{
	if(!root)	//if empty, then return false
		return 0;
	remove_all(root -> right);	//traverse right and left to check every root
	remove_all(root -> left);	//this will delete data at the end first
	delete root;	//delete and set it into NULL
	root = NULL;
	return 1;
}

int table::display_all(node * root)	//this function will display all the root inside the tree structure
{
	if(!root)	//if empty then return false
		return 0;
	root -> entry.display();	//display and then traverse to the right and then left
	display_all(root -> right);
	display_all(root -> left);
	return 1;	//return true if the data exist
}

int table::display_location(node * root, char * loc)
{
	if(!root)	//check to see if its empty
		return 0;
	if(root -> entry.compare_location(loc) == 0)	//if the location match
		root -> entry.display();		//display the location
	if(root -> entry.compare_location(loc) >= 0)	//if not then traverse to the right or left
		display_location(root -> left, loc);
	else
		display_location(root -> right, loc);
	return 1;
}

int table::remove(node * & root, char * loc)	//this function will remove the location if the arguement of the location matched
{
	if(!root)	//check to see if it's empty
		return 0;
        if(root -> entry.compare_location(loc) != 0)	//if the data doesnt match then traverse left or right
        {
        	if(root -> entry.compare_location(loc) >= 0)
			remove(root -> left, loc);
		else
			remove(root -> right, loc);
	}
	if(root -> entry.compare_location(loc) == 0)	//if the data is found
	{
		if(root && root -> left == NULL && root -> right == NULL)	//if the data is at the leaf then delete and set to null
		{
			delete root;
			root = NULL;
		}
		if(root && root -> left != NULL && root -> right == NULL)	//if internal node with only 1 child at the left
		{
			node * temp = root -> left;
			delete root;
			root = temp;
		}
		if(root && root -> left == NULL && root -> right != NULL)	//if internal node with only 1 child at the right
		{
			node * temp = root -> right;
			delete root;
			root = temp;
		}
		if((root && root -> left != NULL && root -> right != NULL) && root -> right -> left == NULL)	//if internal node with 2 children but right chiled has no left children
		{
			node * temp = root -> right;
			root -> entry.copy_entry(temp -> entry);
			root -> right = root -> right -> right;
		}
		if(root && root -> left != NULL && root -> right != NULL)	//if internal node with 2 children
		{
			node * previous;
			node * temp = root -> right;
			while(temp -> left != NULL)
			{
				previous = temp;
				temp = temp -> left;
			} 
			root -> entry.copy_entry(temp -> entry);	//copy the root from the succesor
			previous -> left = temp -> right;
			delete temp;	//delete and set temp to NULL
			temp = NULL;
		}
		remove(root, loc);
	}
}

int table::count_location(node * root, char * loc)	//this function will count how many data items that matched the argument location
{
	int num = 0;
	if(!root)
		return 0;
	num += count_location(root -> left, loc);
	num += count_location(root -> right, loc);
	if(root -> entry.compare_location(loc) == 0)	//if it matched then plus one
		return num + 1;
	return num;
}
int table::retrieve_location(node * root, char * loc, journal_entry * & found, int & index)	//this function will find the matched data
{												//and pass it by reference
	if(!root)
		return 0;
	if(root -> entry.compare_location(loc) == 0)
	{
		root -> entry.retrieve(loc, found[index]);	//if tt matched then retrieve the item and pass by reference to found
		++index;	//increment the index
	}
	if(root -> entry.compare_location(loc) >= 0)	//if the location is less than the root, then traverse to the left
		retrieve_location(root -> left, loc, found, index);
	else
		retrieve_location(root -> right, loc, found, index);	//otherwise traverse to the right
}

