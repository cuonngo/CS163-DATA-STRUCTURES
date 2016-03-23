#include "stack.h"
using namespace std;

/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this header file is to add the trivial question
and answer to the circle linear linked list. If the user
answer the question correctly, the question will be dequeue and then
enqueue so the trivial question will return to the bottom of the deck.
Else if the question are answered incorrectly, then the trivial question
will be move to another stack of the card.
*/

//setting up the circle linear linked list with journal entry.
struct q_node
{
	journal_entry entry;
	q_node * next;
};

class queue
{
	public:
		queue();	//constructure
		~queue();	//destructure
//		int display_all() const;
//		int display(char * & answer);
		int enqueue(const journal_entry & to_add);	//insert the trivial question to the circle linked list
		int dequeue(journal_entry & to_move);	//remove the trivial question and return it into a journal entry arguement
	private:
		q_node * rear;	//node pointing to the rear

};
