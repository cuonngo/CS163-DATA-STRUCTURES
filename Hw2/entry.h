#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
const int SIZE = 100;

/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this journal class is to hold the trivial question and answer. The question and answer
is store in the private. The question and answer will be insert into a circle linked list.
*/


class journal_entry
{
	public:
		journal_entry(void); //constructure
		~journal_entry(void);	//destructure
		int create_entry(char * question, char * answer);	//dynamically stores the question and answer into the class
		int copy_entry(const journal_entry & copy_from);	//copy the question and answer 
		char * display();	//display the question and return the answer pointing to character
	private:
		char * ques;	//hidden pointer variables
		char * answ;
};
bool again(const char prompt[], int num);	//ask user for again
void compare(char ans[], char * ans2, int & num);	//compare the user answer and the trivial answer
void end_game(int num);	//print out the total score and determine wether the user win or lose

