#include "list.h"
using namespace std;
/*
Cuong Ngo, CS163, Assignment 1, 4/22/14
This program will read in students' information and stores into a linear linked list.
The user will be able to display, update, and evaluate the students' information.
There will be two display function. The user can display the students' information
by last name or by the proficency demo score.
*/
//Constructure that will initilize the pointers and data members
list::list()
{
	head = NULL;
	profHeads[0] = NULL;
	profHeads[1] = NULL;
	profHeads[2] = NULL;
	profHeads[3] = NULL;
}
//Destructure that will deallacote the memory for the data members
list::~list()
{
	node * current = head;
	while(current)	//traverse and deallocate the memory until current is null. 
	{
		head = head -> next;
		delete current;
		current = head;
	}
	head = NULL;

	for(int i =0; i < 4; ++i) //deallocate array of four linear linked list.
	{
		node * current = profHeads[i];
		while(current)
		{
			profHeads[i] = profHeads[i]->next;
			delete current;
			current = profHeads[i];
		}
		profHeads[i] = NULL;
	}
}
//This function will insert the students information into a linear linked list and array of linear linked list.
//It will ordered the students' information by last name and proficiency demo. 
int list::insert(student & to_add)
{
	student * temp = new student;
	temp -> copy_student(to_add);
	insertName(temp); //This function will insert the student information into a linear linekd list and ordered by last name.
	if(strcmp(temp -> profDemo(),"E") == 0) //check to see which proficiency demo scores 
		insertScore(temp, profHeads[0]); //add into the array of linear linked list
	else if(strcmp(temp -> profDemo(), "P") == 0) //same as above
		insertScore(temp, profHeads[1]);
	else if(strcmp(temp -> profDemo(), "IP") == 0)
		insertScore(temp, profHeads[2]);
	else  if(strcmp(temp -> profDemo(),"U") == 0)
		insertScore(temp, profHeads[3]);
}

//This function will insert students' information in a certain array of proficiency score.
//For each of the array, it will ordered by the student's grade
int list::insertScore(student * to_add, node * & profhead)
{
	node * previous;
	node * current = profhead;
	node * temp = new node;
	temp -> myStudent = to_add;
	if(!profhead || to_add -> number(profhead -> myStudent))  //Check to see if head is NULL or if the current value is less than head
	{
		temp -> next = profhead;
		profhead = temp;
		return 1;
	}
	while(current && !(to_add -> number(current -> myStudent))) //Traverse until the condition are met
	{
		previous = current;
		current = current -> next;
	}
	previous -> next = temp;
	temp -> next = current;
	return 1;
}
int list::insertName(student * to_add) //This function will insert the students' information into a linear linked list and ordered it by last name.
{
	node * previous;
	node * current = head;
	node * temp = new node;
	temp -> myStudent = to_add;
	if(!head || to_add -> compare(head -> myStudent) <= 0) //Check to see if head is NULL or if the current value isless than head
        {
		temp -> next = head;
		head = temp;
		return 1;
        }
	while(current && to_add -> compare(current -> myStudent) >= 0) //Traverse until the condition are met.
	{								//This function will insert the students' information between the nodes.
		previous = current;
		current = current -> next;
	}
	previous -> next = temp;
	temp -> next = current;
	return 1;

}
//This function will display only the linear linked list ordered by last name
int list::display()
{
	node * current = head;
	while(current != NULL)
	{
		current -> myStudent -> display();
		current = current -> next;
	}
	return 1;
}

//This function will display the array of four linear linked list ordered by student's grade
int list::profDisplay(int i)
{
	node * current = profHeads[i];
	while(current != NULL)
	{
		current -> myStudent -> display();
		current = current -> next;
	}
	return 1;
}
//This function will allow the user to change the student's grade, proficiency, and lab score.
int list::update()
{
	char * studentName;
	studentName = search(); //this variable will stores the student last name
	node * current = head;
	while(current)
	{
		if(strcmp(current->myStudent->lastName(), studentName) == 0) //if the student last name match
		{
			current -> myStudent -> update(); //update the student's information
		        if(strcmp(current -> myStudent -> profDemo(),"E") == 0) //stores it into array of linear linked list
		                insertScore(current -> myStudent, profHeads[0]); //and ordered by grade percentage
        		else if(strcmp(current -> myStudent -> profDemo(), "P") == 0)
                		insertScore(current -> myStudent, profHeads[1]);
        		else if(strcmp(current -> myStudent -> profDemo(), "IP") == 0)
                		insertScore(current -> myStudent, profHeads[2]);
        		else  if(strcmp(current -> myStudent -> profDemo(),"U") == 0)
                		insertScore(current -> myStudent, profHeads[3]);
		}
		current = current -> next;	
	}
	return 1;
}
//This function will evaluate the student's information.
//It will read out if the student failed or passed the class
//base on the proficiency demo and grade percentage.
int list::evaluate()
{
	char * studentName;
	studentName = search();
	node * current = head;
	while(current)
	{
		if(strcmp(studentName, current -> myStudent -> lastName()) == 0)//search student's last name
		{
			if(((strcmp(current -> myStudent -> profDemo(), "E") == 0) || //check to see if student met the requirement
			 strcmp(current -> myStudent -> profDemo(), "P") == 0) && (current -> myStudent -> score() >= 65))
			{
				cout << "Proficency demo:  " << current -> myStudent -> profDemo() << ". Grade(%): "
					<< current -> myStudent -> score() << ". You passed the class.";
			}
			else //student failed if the requirement does not met.
			{
                                cout << "Proficency demo:  " << current -> myStudent -> profDemo() << ". Grade(%): "
                                        << current -> myStudent -> score() << ". You failed the class.";
			}
		}
		current = current -> next;
	}
	return 1;
}
