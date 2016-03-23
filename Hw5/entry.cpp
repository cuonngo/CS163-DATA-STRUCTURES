#include "entry.h"
using namespace std;


/*
Cuong Ngo, Assignment 5, Karla Fant, June 3, 2013.
The purpose of this assignment is to get a direction from Gresham to
portland downtown. This program will ask the user if they want to display
the ruote or display by adjacent from an intersection. The user can also
remove all of the route from the data structure. */

journal_entry::journal_entry()	//constructure
{
	location = NULL;
}

journal_entry::~journal_entry()	//destructure
{
	if(location)	//if exist
		delete [] location;
}

int journal_entry::create_entry(char * loc)	//take an arguement and create an entry
{
	location = new char[strlen(loc) + 1];	//allocate
	strcpy(location, loc);	//copy
	return 1;
}

int journal_entry::copy_entry(const journal_entry & copy_from)	//take the arguement and copy it
{
	if(!copy_from.location)	//if it doesnt exist, then return false
		return 0;
	if(location)	//if existed then delete
		delete [] location;
	location = new char[strlen(copy_from.location) + 1];	//allocate
	strcpy(location, copy_from.location);	//copy it in
	return 1;
}

int journal_entry::display()	//display the private variable member
{
	cout << location << endl;
}
bool journal_entry::compare(char * is_it_a_match)	//compare the location with the arguement
{
	if(strcmp(location, is_it_a_match) == 0)	//if it match return true
		return true;	
	return false;
}

int read(const char prompt[])   //print out the options for the user to choose
{
        int num;
        cout << prompt;
        cout << "1. Display adjacent\n"
                << "2. Display Route\n"
                << "3. Quit\n"
                << "Number: ";
        cin >> num;     cin.ignore(SIZE,'\n');  //get in the number that the user chose
        return num;     //return the number from the user
}

void intersection()	//this function will display all of the intersection so the user can choose
{
	cout << "Enter one of the following intersection: \n"
		<< "SE 174th Ave at SE Division St\n"
		<< "SE Division at I-205 N\n"
		<< "SE Stark St at I-205 N\n"
		<< "I-205 N at I-84 W\n"
		<< "I-84 W at I-5 S\n"
		<< "I-5 S at SE Morrision Bridge\n"
		<< "SE Morrision Bridge merge onto SW Washington St\n"
		<< "SE 174th Ave at SE Stark St\n"
		<< "SE Stark St at SE Morrision Bridge" << endl;
}
void read_vertex(const char prompt[], int size, char result[])	//this function will prompt and read in the user input
{
	cout << prompt;
	cin.get(result, size, '\n');
	cin.ignore(size, '\n');
}
