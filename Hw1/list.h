#include "student.h"

/*
Cuong Ngo, CS163, Assignment 1, 4/22/14
This program will read in students' information and stores into a linear linked list.
The user will be able to display, update, and evaluate the students' information.
There will be two display function. The user can display the students' information
by last name or by the proficency demo score.
*/


struct node
{
	student * myStudent; // a pointer that will be use for array of linear linked list
	node * next;
};

class list
{
	public:
		list();
		~list();
		int insert(student & to_add); //insert students' information function
		int insertName(student * to_add); //insert students' information into linear linked list
		int insertScore(student * score, node * & profhead); //insert students' information into array of linear linked list
		int display(); //display by the ordered of last name
		int profDisplay(int); //display by the proficiency demo and ordered by grade percentage
		int update(); //update student's information
		int evaluate(); //determine if the student passed or failed the class
	private:
		node * head;
		node * profHeads[4]; //set up array of four linear linked list
};
