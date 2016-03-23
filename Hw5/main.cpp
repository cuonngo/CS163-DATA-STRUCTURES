#include "graph.h"

/*
Cuong Ngo, Assignment 5, Karla Fant, June 3, 2013.
The purpose of this assignment is to get a direction from Gresham to
portland downtown. This program will ask the user if they want to display
the ruote or display by adjacent from an intersection. The user can also
remove all of the route from the data structure. */

int main()
{
	table my_journal; //declares object members
	journal_entry to_add;
	my_journal.load();
	my_journal.load_edges();
	int num;	//read in user
	char temp[100]; //temporary to hold vertex
	do
	{
		num = read("\n\nPick one of the following: \n");	//ask user and read out a list of options
		if(num == 1)	//if user pick display adjacent
		{
			intersection();	//display all the intersections for the user to pick
			read_vertex("\nWhat intersection: ", SIZE, temp);	//read in the intersection
			my_journal.display_adjacent(temp);	//display the adjacency of the intersection
		}
		else if(num == 2)	//if the user pick display route
		{
			intersection();	//display all the intersectitons for the user to pick
			read_vertex("\nWhat intersection: ", SIZE, temp);	//read in the intersection
			my_journal.display_all(temp);	//display a route to Portland Downtown
		}
	}while(num != 3);	//if the user wants to quit
}
