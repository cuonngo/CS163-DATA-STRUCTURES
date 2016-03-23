#include "entry.h"

/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
abd location. This is a great program for people who wants to create a plan for their summer
break.
*/

//create a struct node pointer for the data structure
struct node
{
	journal_entry entry;
	node * next;
};

class table
{
	public:
		table(int size = 5);	//allocate and set the size of the hash table
		~table();	//deallocate
		int load();	//read in from an external file
		int hash_function(char key_value[]);	//hash function which will take pointer charater and turn it into keys
		int insert(const journal_entry & to_add);	//insert the information into the hash table
		int retrieve(char * find_location, journal_entry * & found);	//find the matching and return the whole information
		int display_location(char * find_location);	//display everything if the location matches the argument
		int display_activity(char * find_activity);	//display everything if the activity matches the argument
		int remove(char * find_location);	//remove if the location matches the arguement
		int display_all();	//display everything in the hash table

	private:
		node ** hash_table;	//create a hash table
		node ** hash_table2;	//create another hash table for extra credits
		int hash_table_size;	//set the variable size as integer
};

