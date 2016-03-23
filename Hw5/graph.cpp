#include "graph.h"
using namespace std;

/*
Cuong Ngo, Assignment 5, Karla Fant, June 3, 2013.
The purpose of this assignment is to get a direction from Gresham to
portland downtown. This program will ask the user if they want to display
the ruote or display by adjacent from an intersection. The user can also
remove all of the route from the data structure. */

table::table(int size)	//take an integer arguement and create a array of linear linked list
{
	list_size = size;	//catch the size integer
	adjacency_list = new vertex[size];	//allocate a vertex list
	for(int i = 0; i < size; ++i)	//initialize every node and entry
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].entry = NULL;
	}
}

table::~table()
{
        for(int i = 0; i < list_size; ++i) //Deallocate all of the node in the has table
        {
                node * current = adjacency_list[i].head;
		node * previous = current;
                while(current)
                {
			current = current -> next;
			delete previous;
			previous = current;
                }
        }
        delete [] adjacency_list;   //deallocate the arrays of the hash table
}

int table::load()	//this funcion will load in the vertex and insert it into the graph structure
{
	char temp[100];	//create a temporary array
	ifstream file_in;
	journal_entry to_add;
	file_in.open("vertex.txt");	//open up the file
	file_in.get(temp,SIZE,'\n');
	file_in.ignore(SIZE,'\n');
	while(!file_in.eof())	//while not empty
	{
		to_add.create_entry(temp);	//create an entry
		insert_vertex(to_add);	//insert it into the data structure
		file_in.get(temp, SIZE, '\n');
		file_in.ignore(SIZE, '\n');
	}
	return 1;
}

int table::load_edges()	//this function will load in the edges andinsert it into the graph structure
{
	int num1, num2;
	char temp[100];	//create a temporary array
	ifstream file_in;
	journal_entry to_add;	//create a temporary object of journal entry
	file_in.open("edges.txt");	//open up the file
	file_in >> num1;	//read in
	file_in.ignore(SIZE, ';');
	while(!file_in.eof())
	{
		file_in >> num2;
		file_in.ignore(SIZE, ';');
		file_in.get(temp, SIZE, '\n');
		file_in.ignore(SIZE,'\n');
		insert_edge(num1, num2, temp);	//insert into the array of linear linked list
		file_in >> num1;
		file_in.ignore(SIZE, ';');
	}
	return 1;
}


int table::insert_vertex(const journal_entry & to_add)	//this function will take an arguement and insert it into the data structure
{
	for(int i = 0; i < list_size; ++i)
	{
		if(!adjacency_list[i].entry)	//check if its empty
		{
			adjacency_list[i].entry = new journal_entry;	//allocate journal entry
			adjacency_list[i].entry -> copy_entry(to_add);	//copy it in the data structure
			return 1;
		}
	}
	return 0;
}

int table::insert_edge(int num1, int num2, char * loc)	//this function will take interger and location arguement and insert it into the data structure
{
	int index = num1;
	int index2 = num2;
	node * temp = new node;	//create new node
	temp -> adjacent = &adjacency_list[index2];	//copy it in
	temp -> road_name = new char[strlen(loc) + 1];	//allocate
	strcpy(temp -> road_name, loc);	//copy it in
	temp -> next = adjacency_list[index].head;	//connect it in first node
	adjacency_list[index].head = temp;	//set head
	return 1;
}

int table::find_location(char * key_value)	//this function will find the location and return the index
{
	for(int i = 0; i < list_size; ++i)
	{
		if(adjacency_list[i].entry -> compare(key_value))	//if it matched, return the index
			return i;
	}
	return -1;
}

int table::display_adjacent(char * key_value)	//this function will display the adjacent of the vertex
{
	int i = find_location(key_value);	//get the index by using the key value
	node * current = adjacency_list[i].head;
	if(i >= 0)
		return display_adjacent(current/*adjacency_list[i].head*/);	//calling the recursive function
	return 0;
}

int table::display_adjacent(node * head)	//recursive function that will display the adjacent
{
	if(!head)
		return 0;
	head -> adjacent -> entry -> display();
	display_adjacent(head -> next);
	return 1;
}

int table::unset_flag()	//this function will mark down the street that visted
{
	for(int i = 0; i < list_size; ++i)
		adjacency_list[i].flag = 0;	//set all to false
	return 0;
}

int table::display_all(char * key_value)	//this function will display all of the route to portland downtown
{
	int i = find_location(key_value);	//get the index using the key value
	if(i >= 0)
		display_all(adjacency_list[i].head); //call the recursive function
	unset_flag();	//set flag to false
	return 1;
}
int table::display_all(node * head)	//recursive function that will display all of the route to Portland downtown
{
	if(!head)	//if empty 
		return 0;
	if(head -> adjacent -> flag == false)	//if the flag is unmark
	{
		head ->adjacent -> flag = true;	//mark
		cout << "Take: "<< head -> road_name << " " << "to: ";	//display the street name
		head -> adjacent -> entry -> display();	//display the vertex
		display_all(head ->adjacent -> head);
	}
	return 1;
}/*
int table::display_adjacent(char * key_value)
{
	int i = find_location(key_value);
	node * current = adjacency_list[i].head;
	while(current)
	{
		current -> adjacent -> entry -> display();
		current = current -> next;
	}
	return 1;
}*/
