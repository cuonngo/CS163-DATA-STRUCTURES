#include "queue.h"
using namespace std;

/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this file is to add the trivial question
and answer to the circle linear linked list. If the user
answer the question correctly, the question will be dequeue and then
enqueue so the trivial question will return to the bottom of the deck.
Else if the question are answered incorrectly, then the trivial question
will be move to another stack of the card. 
*/

//Constructure to initilize variables
queue::queue()
{
	rear = NULL;
}

//Deallocate cicrcle linear linked list
queue::~queue()
{
	q_node * current = rear -> next;
	rear -> next = NULL;	//cut the circle linear linked list
	rear = current;
	while(current)
	{
		current = current -> next;
		delete rear;
		rear = current;
	}	
}

int queue::enqueue(const journal_entry & to_add) //Add the question and answer to a circle linear linked list
{
	q_node * temp = new q_node;
	temp -> entry.copy_entry(to_add);	//copy the question and answer to a temp node

	if(!rear)	//if the list is empty
	{
		rear = temp;
		rear -> next = rear;
		return 1;
	}
	if(rear == rear -> next) //if there is only one node in the circle linear linked list
	{
		temp -> next = rear;
		rear -> next = temp;
		rear = temp;
		return 1;
	}
	temp -> next = rear -> next;	//connect the temp nide into acircle linear linked list
	rear -> next = temp;	//connect the temp node into a circle linear linked list
	rear = temp;	//set rear to the last node
	return 1;
}

int queue::dequeue(journal_entry & to_move)	//return a pass by refrence agrument and
						//remove a question and answer from the circle linked list
{
	if(!rear)	//return false if circle linear linked list is empty
		return 0;
	if(rear->next != rear)	//check to see if rear is pointing to the last node of circle linked list
	{
		q_node * temp = rear -> next;
		to_move.copy_entry(temp -> entry); //copy the node into a journy entry class
		rear -> next = temp -> next;	//remove 
		delete temp;	//deallocate
		return 1;
	}
	to_move.copy_entry(rear -> entry);	//else if none of the condition above are met, copy into temp and remove 
	delete rear;				//node from the Circle linked list
	rear = NULL;
	return 1;
}
/*
int queue::display_all() const
{
	q_node * current = rear -> next;
	while(current -> next != rear -> next)
	{
		current -> entry.display();
		current = current -> next;
	}
	return 1;
}

int queue::display(char * & answer)
{
	if(!rear)
		return 0;
	q_node * current = rear -> next;
	answer = current -> entry.display();
	return 1;
}*/
