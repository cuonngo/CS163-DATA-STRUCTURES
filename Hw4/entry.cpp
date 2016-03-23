#include "entry.h"
using namespace std;


/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
and location. This is a great program for people who wants to create a plan for their summer
break.
*/

//constructure to initialize the data members
journal_entry::journal_entry()
{
	name = NULL;
	activity = NULL;
	description = NULL;
	location = NULL;
	rating = 0;
	require = NULL;
}

//destructure to deallocate the memory of data members
journal_entry::~journal_entry()
{
	if (name)
	{ 
		delete [] name;
		delete [] activity;
		delete [] description;
		delete [] location;
		delete [] require;
	}
}

//Take arguments and use it to create an entry for the data members
int journal_entry::create_entry(char * nam, char * act, char * des, char * loc, int rat, char * req)
{
	name = new char[strlen(nam) + 1];	//allocate
	strcpy(name, nam);	//copy it in
	activity = new char[strlen(act) + 1];	//same as above
	strcpy(activity, act);
	description = new char[strlen(des) + 1];
	strcpy(description, des);
	location = new char[strlen(loc) + 1];
	strcpy(location, loc);
	rating = rat;
	require = new char[strlen(req) + 1];
	strcpy(require, req);
	return 1;
}

//take an journal_entry arguement and copy it into the data members.
int journal_entry::copy_entry(const journal_entry & copy_from)
{
	if(!copy_from.activity)	//check to see if its empty
		return 0;
	if(activity)	//if activity existed, then delete all of information
	{
		delete [] activity;
		delete [] require;
		delete [] location;
		delete [] description;
	}
	name = new char[strlen(copy_from.name) + 1];	//allocate the variable name
	strcpy(name, copy_from.name);	//copy it into name
	activity = new char[strlen(copy_from.activity) + 1];	//allocate the variable activity
	strcpy(activity, copy_from.activity);	//copy it into activity
	description = new char[strlen(copy_from.description) + 1];	//allocate the description
	strcpy(description, copy_from.description);	//copy it into description
	location = new char[strlen(copy_from.location) + 1];	//allocate the location
	strcpy(location, copy_from.location);	//copy it into location private variable
	rating = copy_from.rating;	//copy the integer value
	require = new char[strlen(copy_from.require) + 1];	//allocate the require private variable
	strcpy(require, copy_from.require);	//copy it into private variable
	return 1;
}
//This function will take an characters pointer and search for the matching.
//If it is found, then pass by referencet the journal_entry variable.
int journal_entry::retrieve(char * matching_location, journal_entry & found)	
{
	if(strcmp(matching_location, location) == 0)
	{
		found.name = new char[strlen(name) + 1];	//allocate the class member for found
        	strcpy(found.name, name);	//copy it into journal_entry member
		found.activity = new char[strlen(activity) + 1];	//allocate the class member for found
		strcpy(found.activity, activity);	//copy it into journal_entry member
       		found.location = new char[strlen(location) + 1]; //same as above 
        	strcpy(found.location, location);
        	found.description = new char[strlen(description) + 1];
      		strcpy(found.description, description);
		found.require = new char[strlen(require) + 1];
		strcpy(found.require, require);
		found.rating = rating;
		return 1;
	}
	else
		return 0;
}

int journal_entry::display()	//display the private members
{
	cout << location << '\t' << activity << '\t' << description << '\t'
		<< rating << '\t' << require << endl;
	return 1;
}

int read(const char prompt[])	//print out the options for the user to choose
{
	int num;
	cout << prompt;
	cout << "1. Display All\n"
		<< "2. Display by Location\n"
		<< "3. Remove by Location\n"
		<< "4. Retrieve Location\n"
		<< "5. Display Retrieved\n"
		<< "6. Remove All\n"
		<< "7. Quit\n"
		<< "Number: ";
	cin >> num;	cin.ignore(SIZE,'\n');	//get in the number that the user chose
	return num;	//return the number from the user
}

void read_location(const char prompt[], int size, char * & result)	//this function will prompt the user and read in
{
	char temp[100];
	cout << prompt;	//print out prompt
	cin.get(temp,size,'\n');
	cin.ignore(size,'\n');
	result = new char[strlen(temp) + 1];
	strcpy(result, temp);	//get the user's input
}

//compare the root location with the argument location
int journal_entry::compare_location(char * loc)
{
	return strcmp(location, loc);
}
int journal_entry::compare(journal_entry & loc) // compare the root location with the journal entry class location
{
	return strcmp(location, loc.location);
}
