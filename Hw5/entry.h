#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
/*
Cuong Ngo, Assignment 5, Karla Fant, June 3, 2013.
The purpose of this assignment is to get a direction from Gresham to
portland downtown. This program will ask the user if they want to display
the ruote or display by adjacent from an intersection. The user can also
remove all of the route from the data structure. */

const int SIZE = 100; //const variable
class journal_entry
{
	public:
		journal_entry(); //constructure
		~journal_entry();	//destructure
		int create_entry(char * loc);	//take in an arguement and create an entry
		int copy_entry(const journal_entry & copy_from);	//take in an object member and copy it
		bool compare(char * is_it_a_match);	//compare the arguement with the location variable
		int display();	//display the variable
	private:
		char * location;	//private variable
};

int read(const char prompt[]);	//read in the intersection
void read_vertex(const char prompt[], int size, char result[]);	//read in the intersection
void intersection();	//display all of the intersections
