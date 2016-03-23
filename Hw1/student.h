#include <iostream>
#include <cstring>
#include <cctype>

/*
Cuong Ngo, CS163, Assignment 1, 4/22/14
This program will read in students' information and stores into a linear linked list.
The user will be able to display, update, and evaluate the students' information.
There will be two display function. The user can display the students' information
by last name or by the proficency demo score.
*/


class student
{
	public:
		student();
		~student();
		int create_student();
		int display(); //display student's information
		int copy_student(const student & copy_from); //copy student informaiton into a linear linked list
		int compare(student * name); //compare the student's last name
		char * profDemo(); //return proficiency demo
		char * lastName(); //return last name
		bool number(student *);
		int score(); //return score
		int update();
		char * search();  //return last name
	private: //data members that will be use to hold student's information
		char * last;
		char * prof;
		int grade;
		int lab;
};
bool again();  //ask user to try again
int option(); //options for user to pick
int read(const char prompt[]); //return an int value 
char * search(); //search for student's last name
