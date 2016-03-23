#include "queue.h"
using namespace std;

/*
Cuong Ngo, CS163, Assignment 2, 5/2/14
The purpose of this assignment is ask the user to pick trivial card from a deck.
If the user answered correctly, the user will gain a point and then the card will be place on the
bottom. However, if the user answered incorrectly, the card will be discard into another pile of deck.
The user can pick card from the other deck if user desired. If the user answered correctly or incorrectly on the other deck,
then the card will be discard and user will gain a point. The user will win if he earned 5 points.
*/

//a function that i used to minimize the length of the main function
//this function will ask the user to pick a card from the second deck.
//It will also ask for the answer and if the user answered correctly
//then they will gain a point and the card will be discard.
void output(journal_entry & to_move, stack & single, int & score, char * answer2, char answer[])
{
        if(single.peek(to_move))	//peek a card on the deck and return the answer as agruments
        {
                 answer2 = to_move.display();	//print out the question and catch the answer
                 single.pop();	//remove the card from the deck
                 cin.get(answer,SIZE,'\n');      cin.ignore(SIZE,'\n');	//ask the user for the answer
                 compare(answer, answer2, score);	//check to see if the user answered correctly
        }
        else
        {
                 cout << "Deck 2 is empty!" << endl;	//else if the deck is empty
		 return;
        }

}

int main()
{
	journal_entry to_add, to_move;	//member of journal entry class
	queue firstDeck;	//a circular linked list for first deck
	stack secondDeck;	//a linear linked list of array for second deck
	ifstream file_in;
	int score = 0;	//initialize score
	char question[SIZE], answer[SIZE];
	char * answer2;

	file_in.open("trivial.txt");	//open the file
        file_in.get(question, SIZE, ';');  file_in.ignore(SIZE, ';');	//check to see if there are questions and answers
	while(!file_in.eof())	//while its not empty
	{
		file_in.get(answer, SIZE, '\n');	file_in.ignore(SIZE, '\n');	//read in the answer and question
		to_add.create_entry(question,answer);	//copy it into journal entry class
		firstDeck.enqueue(to_add);	//place it into a first deck
                file_in.get(question, SIZE, ';');  file_in.ignore(SIZE, ';');
	}
	while(again("Do you want to pick from Deck 1(Y/N): ", score))	//Ask user if they want to pick the card from first deck
	{
		if(firstDeck.dequeue(to_move))	//dequeue and return the card as an arguement
		{
			answer2 = to_move.display();	//display the question and save the actual answer
			cin.get(answer, SIZE, '\n');	cin.ignore(SIZE, '\n');	//read in user answer
			if(strcmp(answer,answer2) == 0) 	//compare to see if the user answered it right
			{
				firstDeck.enqueue(to_move);	++score;	//move the card to bottom of the first deck and give the user a point
				cout << "Correct! you gained 1 point\t total: " << score << endl;
			}
			else
			{
				cout << "Incorrect!" << endl;	//read out incorrectly if the card is answered wrong
				secondDeck.push(to_move);	//move the card into second deck
			}
		}
		else
			cout << "Deck 1 is empty!" << endl;
	}
	while(again("Do you want to pick from Deck 2(Y/N): ", score))	//ask user if they want to pick card from deck 2
		output(to_move, secondDeck, score, answer2, answer);	//display and check the user answer function
	end_game(score);	//print out the user's result
	return 0;
}

