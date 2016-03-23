#include "stack.h"


/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this header file is to add the trivial question
and answer to the stack by linear linked list of arrays. If the user
answer the question correctly or incorrectly, then the trivial question
will be discard.
*/


stack::stack()	//initialize the variables and pointer
{
	head = NULL;
	top_index = 0;
}

stack::~stack()	//deallocate trivial question from the stack.
{
	node * current = head;
	while(current)
	{
		head = head -> next;
		delete [] current -> entries;
		delete current;
		current = head;
	}
	head = NULL;

}

int stack::push(const journal_entry & to_add)	//take the arguement and insert it into the linear linked list of array
{
	if(!head)	//check to see if list is empty
	{
		head = new node;
		head -> entries = new journal_entry[MAX];	//creat a node with arrays
		head -> entries[top_index].copy_entry(to_add);	//put the information in
		head -> next = NULL;
		++top_index;	//increment the array
		return 1;
	}
	if(top_index < MAX)	//check to see if there is room for array
	{
		head -> entries[top_index].copy_entry(to_add);	//insert it into array
		++top_index;	//increment to next array
		return 1;
	}
	top_index = 0;
	node * temp = new node;
	temp -> entries = new journal_entry[MAX];	//else create a new node and 
	temp -> entries[top_index].copy_entry(to_add);  //insert the trivial question in
	temp -> next = head;				//connect it up with other questions
	head = temp;
	return 1;
}

int stack::display_all(char * answer)	//display the question and pass the answer by referencce
{
	node * current = head;
	answer = current -> entries -> display();
	return 1;
}

int stack::pop()	//remove the data from the top of the linear linked list
{
	if(!head)
		return 0;
	//if there is 1 item left
	if(top_index == 1)
	{
		node * temp = head -> next;
		delete [] head -> entries;
		delete head;
		head = temp;
		if(head)
			top_index = MAX;
		return 1;
	}
	--top_index;
	return 1;
}

int stack::peek(journal_entry & found_at_top) const	//peek at the top of the stack and return the 
{							//trivial question and answer by reference.
	if(!head)
		return 0;
	found_at_top.copy_entry(head->entries[top_index-1]);
	return 1;
}
