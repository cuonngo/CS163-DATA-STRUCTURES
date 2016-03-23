#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
and location. This is a great program for people who wants to create a plan for their summer
break.
*/

const int SIZE = 100;
class journal_entry
{
	public:
		journal_entry();
		~journal_entry();
		int create_entry(char * nam, char * act, char * des, char * loc,	//take an arguement and copy it into the private
				 int rat, char * req);					//data members
		int copy_entry(const journal_entry & a_new_entry);	//copy information from the private variables
		int retrieve(char * matching_location, journal_entry & found);	//retrieve and pass by reference
		int display();	//display all of the data members in private
//		int get_location(char * & loc);	//return activity by reference which will be use for display_activity function
		int compare(journal_entry & loc); //compare the current location with the root location
		int compare_location(char * loc); // compare the current location with the arguement location
	public:
		char * name;	//variables of student information
		char * activity;
		char * description;
		char * location;
		int rating;
		char * require;
};
int read(const char prompt[]);	//print out the option that are avaliable for the user and read in the number
void read_location(const char prompt[], int size, char * & result);	//prompt and read in the location or activity
