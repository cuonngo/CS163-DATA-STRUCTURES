#include "student.h"
using namespace std;
/*
Cuong Ngo, CS163, Assignment 1, 4/22/14
This program will read in students' information and stores into a linear linked list.
The user will be able to display, update, and evaluate the students' information.
There will be two display function. The user can display the students' information
by last name or by the proficency demo score.
*/

const int SIZE = 100;

student::student()//constructure for initalizing the data members
{
	last = NULL;
	prof = NULL;
	grade = 0;
	lab = 0;
}

student::~student()//deallocate the array of last name and proficiency demo
{
	delete [] last;
	delete [] prof;
}

int student::create_student() //read in the student's information
{
	char temp[SIZE]; //tempory array to hold the information
	cout << "Last Name: ";
	cin.get(temp,SIZE,'\n');	cin.ignore(SIZE,'\n'); 
	last = new char[strlen(temp)+1];	strcpy(last,temp); //allocate the data members and copy it in
	cout << "Proficiency Demo: ";
	cin.get(temp,SIZE,'\n');	cin.ignore(SIZE,'\n');
	prof = new char[strlen(temp)+1];	strcpy(prof,temp);
	cout << "Grade(%): ";
	cin >> grade;	cin.ignore(SIZE,'\n');
	cout << "Lab(%): ";
	cin >> lab;	cin.ignore(lab,'\n');
	return 1;
}

int student::display() //display function which will be called from the list class
{
	cout << "Last Name: " << last << '\t'
		<< "Proficiency Demo: " << prof << '\t'
		<< "Grade(%): " << grade << '\t'
		<< "Lab(%): " << lab << endl;
	return 1;
}

int student::copy_student(const student & copy_from) //copy student into a linear linked list
{
	if(!copy_from.last)
		return 0;
	if(!copy_from.prof)
		return 0;
	if(last)
		delete [] last;  //deallocate if the information already existed
	last = new char[strlen(copy_from.last)+1];    //adding new information in
	strcpy(last,copy_from.last);

	if(prof)
		delete [] prof;
	prof = new char[strlen(copy_from.prof)+1];
	strcpy(prof,copy_from.prof);

	grade = copy_from.grade;
	lab = copy_from.lab;
	return 1;
}

int student::compare(student * name) //this funtion will compare the student last name and return an interger.
{
	return strcmp(last,name -> last);
}

bool student::number(student * num) //return true or false by comparing the student grades
{
	if(grade >= num -> grade)
		return true;
	return false;
}

char * student::profDemo() //return  an proficiency pointer to char
{
	return prof;
}

int student::score() //return grade by interger
{
	return grade;
}

char * search() //this function will ask the user for the last name to search for
{
	char temp[SIZE];
	char * search_for;
	cout << "Search by last name: ";
	cin.get(temp,SIZE,'\n');	cin.ignore(SIZE,'\n');
	search_for = new char[strlen(temp)+1];
	strcpy(search_for, temp);
	return search_for;

}
int student::update() //update student's information 
{
	char temp[SIZE];
	cout << "Proficiency Demo: ";
	cin.get(temp, SIZE, '\n');	cin.ignore(SIZE,'\n');
	prof = new char[strlen(temp)+1];	strcpy(prof,temp);
	cout << "Grade: ";
	cin >> grade;	cin.ignore(SIZE,'\n');
	cout << "Lab: ";
	cin >> lab;	cin.ignore(lab,'\n');
	return 1;

}
int option() //options that will display for the user to pick
{
	int num;
	cout << "\n\n\nPick one of the following. "
		<< "\n1) Insert new information."
		<< "\n2) Update."
		<< "\n3) Display by Last Name. "
		<< "\n4) Display by Profiency Demo."
		<< "\n5) Calculate overall performance. "
		<< "\n6) Quit.\nNumber: ";
	cin >> num;	cin.ignore(SIZE,'\n');
	return num;
}

int read(const char prompt[]) //a short code that will be use to decide which array of linear linked list 
{
	int num;
	char temp[SIZE];
	char * pdemo;
	cout << prompt;
	cin.get(temp,SIZE,'\n');	cin.ignore(SIZE,'\n');
	pdemo = new char[strlen(temp)+1];
	strcpy(pdemo,temp);
	if(strcmp(pdemo,"E")== 0)
		return 0;
	if(strcmp(pdemo,"P") == 0)
		return 1;
	if(strcmp(pdemo,"IP") == 0)
		return 2;
	if(strcmp(pdemo,"U") == 0)
		return 3;
}

char * student::lastName() //return student's last name by pointer to char
{
	return last;
}

