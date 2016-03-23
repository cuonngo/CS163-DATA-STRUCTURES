#include "entry.h"


/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
and location. This is a great program for people who wants to create a plan for their summer
break.
*/

//create a tree data structure with left and right pointing the the node
struct node
{
	journal_entry entry;
	node * left;
	node * right;
};

//create a tree data strucutre class
class table
{
	public:
		table();	//constructure
		~table();	//destructure
		int load();	//read in the external file
		//wrapper function
		int remove_all();	//remove all data item in the tree data structure
		int insert(journal_entry & to_add);	//take an journal entry member and insert it into ytrr data structure
		int display_all();	//display all data items in the data structure
		int display_location(char * loc);	//display all item that matched the location from the argument
		int remove(char * loc);	//remove all data item that matched the argument
		int retrieve_location(char * loc, journal_entry * & found, int count);	//find the matched location and pass by reference
		int count_location(char * loc);	//count how many data items inside the data strucutre that match the argument
	private:
		node * root;	//declare root pointing to node
		int remove_all(node * & root);	//same as above but these are the recursive function and the aboce is the wrapper function
		int insert(node * & root, journal_entry & );    //take an journal entry member and insert it into ytrr data structure
		int display_all(node * root);       //display all data items in the data structure
		int display_location(node * root, char * loc);      //display all item that matched the location from the argument
		int remove(node * & root, char * loc);//remove all data item that matched the argument
		int count_location(node * root, char * loc);//find the matched location and pass by reference
		int retrieve_location(node * root, char * loc, journal_entry * & found, int & index);//count how many data items inside the data strucutre that match the argument

};
