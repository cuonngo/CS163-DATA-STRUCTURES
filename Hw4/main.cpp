#include "bst.h"

/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
and location. This is a great program for people who wants to create a plan for their summer
break.
*/


int main()
{
	journal_entry * myJournal; //declare a journal entry member
	table BST;	//declare a table member
	int num;	//num variable will be use to read in the user
	int count;	//count will be use to count how many items
	char * location;	//read in the location from the user
	BST.load();
	do
	{
		num = read("\n\n\nChoose one of the following number\n");	//prompt the opetion to the user
		if(num == 1)	//if user pick option 1 then display all
			BST.display_all();
		else if(num == 2)	//if the user pick the option 2 display the location
		{
			read_location("Location: ", SIZE, location);	//read in the location
			BST.display_location(location);	//find the matching location and display
		}
		else if(num == 3)	//if the user pick the option 3 then remove the location
		{
			read_location("Location: ", SIZE, location);	//read in the location
			BST.remove(location);	//remove all the location that matched the arguement
		}
		else if(num == 4)	//if the user pick the option 4 then read in the location and retrieve
		{
			read_location("Location: ", SIZE, location);	//read in the location
			count = BST.count_location(location);	//count how many item that matched
			BST.retrieve_location(location, myJournal, count);	//find the matching and pass the data by reference
		}
		else if(num == 5)	//if the user pick option 5 then display the retreved item
		{
			for(int i = 0; i < count; ++i)
				myJournal[i].display();
		}
		else if(num == 6)	//if the user pick the option 5 then remove all items in the data structure
			BST.remove_all();
	}while(num != 7);	//if the user pick option 7 then exit the program
	return 0;
}
