#include "table.h"
using namespace std;


/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
abd location. This is a great program for people who wants to create a plan for their summer
break.
*/

//constructure initilize the hash tables
table::table(int size)
{
	hash_table_size = size;
	hash_table = new node * [size];		//create the first hash table
	hash_table2 = new node * [size];	//create the second hash table
	for(int i = 0; i < size; ++i)	//initialize it into NULL
	{
		hash_table[i] = NULL;
		hash_table2[i] = NULL;
	}
}

//deallocate both of the hash table
table::~table()
{
	for(int i = 0; i < hash_table_size; ++i) //Deallocate all of the node in the has table
	{
		node * current = hash_table[i];
		while(current)
		{
			hash_table[i] = hash_table[i] -> next;
			delete current;
			current = hash_table[i];
		}
		node * current2 = hash_table2[i];
		while(current2)
		{
			hash_table2[i] = hash_table2[i] -> next;
			delete current2;
			current2 = hash_table2[i];
		}
	}
	delete [] hash_table;	//deallocate the arrays of the hash table
	delete [] hash_table2;	//deallocate the arrays of the hash table
}

//take an arguement and return an key value integer
int table::hash_function(char key_value[])
{
	int count = strlen(key_value) - 1;	//count how manyt characters
	return ((key_value[0] + key_value[count]) % 5);	//return an integer of key value
}

int table::load()	//this function will read in the information from the external file.
{			//it will take the information and insert it into the hash table.
	ifstream file_in;
	journal_entry to_add;
	char nam[SIZE], act[SIZE], des[SIZE], loc[SIZE], req[SIZE];
	int rat;

	file_in.open("plan.txt");	//open file
	file_in.get(nam, SIZE, ';');	file_in.ignore(SIZE, ';');
	while(!file_in.eof())	//start reading in
	{
		file_in.get(act, SIZE, ';');	file_in.ignore(SIZE, ';');
		file_in.get(des, SIZE, ';');	file_in.ignore(SIZE, ';');
		file_in.get(loc, SIZE, ';');	file_in.ignore(SIZE, ';');
		file_in >> rat;	file_in.ignore(SIZE, ';');
		file_in.get(req, SIZE, '\n');	file_in.ignore(SIZE, '\n');
		to_add.create_entry(nam, act, des, loc, rat, req);	//create the entry and save it into the journal_entry member
		insert(to_add);	//take the journal_entry member and insert it into the hash table
		file_in.get(nam, SIZE, ';');	file_in.ignore(SIZE, ';');
	}
	return 1;
}

int table::insert(const journal_entry & to_add)	//this function will take an arguement and insert it into hash table
{
	int index = hash_function(to_add.location);	//get the key of location
	int index2 = hash_function(to_add.activity);	//get the key of activity
	node * temp = new node;
	node * temp2 = new node;
	temp -> entry.copy_entry(to_add);	//copy it into a tempory pointer
	temp2 -> entry.copy_entry(to_add);
	temp -> next = hash_table[index];	//connect it into a hash table linear linked list
	temp2 -> next = hash_table2[index2];
	hash_table[index] = temp;	//set it equal to head
	hash_table2[index2] = temp2;
	return 1;
}

//this function will find the matches of an arguement and return by reference to the journal_entry member
int table::retrieve(char * find_location, journal_entry * & found)
{
	int index = hash_function(find_location);
	int success = 0;
	journal_entry temp;

	if(!hash_table[index])	//if the table is empty then return false
		return 0;
	node * current = hash_table[index];	//set current pointing the head
	while(current)
	{
		success += current -> entry.retrieve(find_location, temp);	//count how many items there are
		current = current -> next;
	}
	found = new journal_entry[success];
	int i = 0;
	current = hash_table[index];	//set current back to pointing head
	while(current)
	{
		current -> entry.retrieve(find_location, found[i]);	//find the location and pass by reference to an arguemnt
		current = current -> next;
		++i;	//increment i
	}
	return success;	//return the number of how many items
}

int table::display_location(char * find_location)	//this function will dislay any information that matches the argument location
{
	int index = hash_function(find_location);	//convert into key
	if(!hash_table[index])	//check too see if its empty
		return 0;
	node * current = hash_table[index];	//current pointing to the head
	while(current)
	{
		current -> entry.display();	//print out the information
		current = current -> next;
	}
	return 1;
}

int table::display_activity(char * find_activity)	//this function will display any information that matches the arguement activity
{
	char * act;
	int index = hash_function(find_activity);	//convert into key value
	if(!hash_table2[index])	//check to see if its empty
		return 0;
	node * current = hash_table2[index];
	while(current)
	{
		current -> entry.get_activity(act);	//grab the activity variable in private
		if(strcmp(act, find_activity) == 0)	//compare if the activity and the arguement matches
		{
			current -> entry.display();	//display iof it matched
		}
		current = current -> next;
	}
	return 1;
}

int table::remove(char * find_location)	//remove the location that matches the arguement
{
	int index = hash_function(find_location);	//convert into key value
	node * current = hash_table[index];	//set current pointing to head
	while(current)
	{
		hash_table[index] = hash_table[index] -> next;	//start deleting if the location matched the argument
		delete current;
		current = hash_table[index];
	}
	return 1;
}

int table::display_all()	//this function will display all information
{
        for(int i = 0; i < hash_table_size; ++i)
        {
                node * current = hash_table[i];	//set current pointing to head
                while(current)
                {
			current -> entry.display();	//print out the information
                        current = current -> next;
                }
        }
	return 1;
}

