#include "entry.h"
using namespace std;

/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this journal class is to hold the trivial question and answer. The question and answer
is store in the private. The question and answer will be insert into a circle linked list. The data will be
store in a dynamically array.
*/


journal_entry::journal_entry()	//construcutre to initilize the variables
{
	ques = NULL;
	answ = NULL;
}

journal_entry::~journal_entry()	//destructure to dellacate the memory
{
	delete [] ques;
	delete [] answ;
}

int journal_entry::create_entry(char * question,char * answer) //store the question and answer into a dynamically array
{
	ques = new char[strlen(question)+1];
	strcpy(ques,question);
	answ = new char[strlen(answer)+1];
	strcpy(answ,answer);
	return 1;
}

int journal_entry::copy_entry(const journal_entry & copy_from)	//copy the question and answer into an arguement
{
	if(!copy_from.ques)	//if its empty then return false
		return 0;
	if(ques)	//deallocate question if it existed
		delete [] ques;
	ques = new char[strlen(copy_from.ques) + 1];	//dynamically allocate
	strcpy(ques, copy_from.ques);	//copy the question from other the argument

	if(!copy_from.answ)
		return 0;
	if(answ)
		delete [] answ;
	answ = new char[strlen(copy_from.answ)+1];
	strcpy(answ,copy_from.answ);
	return 1;
}

char * journal_entry::display()	//display the question and return the answer as pointer
{
	cout << ques << endl;
	cout << "(Capitalize first letter)Answer: ";
	return answ;
}
bool again(const char prompt[], int num)	//ask the user if they want to try again and keep track the score
{
	if(num == 5)	return false;
	char response;
	cout << prompt;
	cin >> response;	cin.ignore(100,'\n');
	if(toupper(response) == 'Y')
		return true;
	return false;
}

void compare(char ans[], char * ans2, int & num)	//compare the user's answer and the actually answer
{
	if(strcmp(ans, ans2) == 0)	//if matched, give the user 1 point
	{
		cout << "Correct! You gained 1 point!" << endl;
		++num;
	}
	else
		cout << "Wrong answer!" << endl;
}

void end_game(int num)	//determine the result of the user wether they win or lose/
{
	if(num >= 5)
		cout << "You Win! Total: " << num << endl;
	else
		cout <<"You Lose! Total: " << num << endl;
}

