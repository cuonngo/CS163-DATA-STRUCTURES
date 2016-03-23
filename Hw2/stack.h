#include "entry.h"

const int MAX = 5;


/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this header file is to add the trivial question
and answer to the stack by linear linked list of arrays. If the user
answer the question correctly or incorrectly, then the trivial question
will be discard.
*/

struct node
{
	journal_entry * entries;
	node * next;
};

class stack
{
	public:
		stack();	//constructure
		~stack();	//destructure
		int push(const journal_entry & topush);	//push the trivial question into linear linked list of array
		int peek(journal_entry & found_at_top) const;	//look at the top questionand return by reference
		int pop();	//remove the top trivial question
		int display_all(char * answer);	//display the question and return answer by reference
	private:
		node * head;
		int top_index;	//keep track of the array in linear linked list
};
