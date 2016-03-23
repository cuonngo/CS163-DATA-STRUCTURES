#include "list.h"
using namespace std;
/*
Cuong Ngo, CS163, Assignment 1, 4/22/14
This program will read in students' information and stores into a linear linked list.
The user will be able to display, update, and evaluate the students' information.
There will be two display function. The user can display the students' information
by last name or by the proficency demo score.
*/

int main()
{
	student myStudent; //declare class variables name
	list myList;
	int num; int profd;	
	do
	{
		switch (option()) //option() is a list of menu
		{
			case 1: //insert
			{
				myStudent.create_student(); //store student's information into data members
				myList.insert(myStudent); //insert into linear linked list and array of linear linked list
				break;
			}
			case 2: //update
			{
				myList.update(); //update the proficiency, lab, and grade percentage
				break;
			}
			case 3: //display all
			{
				myList.display(); //display students' information ordered by last name
				break;
			}
			case 4: //display profiency
			{
				profd = read("What proficiency demo score(E/P/IP/U): "); 
				myList.profDisplay(profd);
				break;
			}
			case 5: //Evulate
				myList.evaluate();	break;
			case 6: //Quit
				num = 6;
		}
	}while(num != 6); //exit the program if user pick option 6.
	return 0;
	
}
