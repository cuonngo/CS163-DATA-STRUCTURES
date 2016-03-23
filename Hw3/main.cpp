#include "table.h"
using namespace std;

/*
Cuong Ngo, CS163, Assignment 3, 5/13/14
The purpose of this assignment is to read in an external file and display it to the user.
The information will be display to the user to see. The user can delete any information
they want base on the location. The user can display any information base on the activity
abd location. This is a great program for people who wants to create a plan for their summer
break.
*/

int main()
{
	int count = 0, num;
	char * location;
	char * activity;
	table my_journal;
	journal_entry * found_location;
	my_journal.load();	//this line will call the function load and
	do			//read in the information from the external file.
	{
		num = read("\n\nPick one of the following: \n");	//Ask the user what option
		if(num == 1)	//if user entered 1, then display all information
			my_journal.display_all();
		else if(num == 2)	//if user entered 2, then display by the location
		{
			read_location("location: ", SIZE, location);//read in the location from user
			my_journal.remove(location);	//display by location
		}
		else if(num == 3)	//if user entered 3, then retrieve the information
		{
                        read_location("location: ", SIZE, location);	//ask user for the location
			count = my_journal.retrieve(location, found_location);	//find the location and retrieve into a journal_entry member
		}
		else if(num == 4)	//if the user entered 4, then display the retrieved location
		{
			for(int i = 0; i < count; ++i)
				found_location[i].display();	//display the retrieved information
		}
		else if(num == 5)	//if the user entered 5, then display all of the information base on the location
		{
			read_location("Location: ", SIZE, location);	//read in the location
			my_journal.display_location(location);	//display the location from the user
		}
		else if(num == 6)	//if the user entered 6, then display all of the information base on the activity
		{
			read_location("Activity: ", SIZE, activity);	//read in the activity
			my_journal.display_activity(activity);	//display by the activity that was read in
		}
	}while(num != 7);	//Exit if the user entered 7

	return 0;
}
