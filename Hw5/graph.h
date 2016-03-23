#include "entry.h"

/*
Cuong Ngo, Assignment 5, Karla Fant, June 3, 2013.
The purpose of this assignment is to get a direction from Gresham to
portland downtown. This program will ask the user if they want to display
the ruote or display by adjacent from an intersection. The user can also
remove all of the route from the data structure. */

struct vertex	//create a structure for vertex
{
	journal_entry * entry;
	bool flag;	//flag the visited street
	struct node * head;

};

struct node	//create a node structure
{
	vertex * adjacent;	//declare an vertex structure object name
	node * next;
	char * road_name;	//get the edges road
};

class table
{
	public:
		table(int size = 9);	//constructure declare the statically array size
		~table();	//destructure
		int load();	//load in the vertex
		int load_edges();	//load in the edges
		int insert_vertex(const journal_entry & to_add);	//insert the vertex into the data structure
		int insert_edge(int num1, int num2, char * loc);	//insert edges into the data structure
		int find_location(char * key_value);	//find the location and return the index
		int display_adjacent(char * key_value);	//display the adjacent of vertex
		int unset_flag();	//set flag if the street are visited
		int display_all(char * key_value);	//display the route to portland downtown
	private:
		int display_all(node * head);	//recursive ofdisplaying the route
		int display_adjacent(node * head);	//recursive of dispalying adjacent
		vertex * adjacency_list;	//create a vertex list
		int list_size;	//declare a size variable
};
