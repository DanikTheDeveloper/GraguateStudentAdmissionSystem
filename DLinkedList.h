//							Linked List .h 
/*
This is a linked list class. We will be using a linked list template to connect and maintain a sorted, linked list of
Dnodes containing data from the student class.
A merged linked list can contain any number of Dnodes containing data from any child class



*/

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H


#include "Student.h"
#include "DomesticStudent.h"
#include <iostream>
using namespace std;

//////////////// Dnode CLASS
class Dnode {

public:
	DomesticStudent data; //will hold DomesticStudent or Istudent objects, for this program
	Dnode* link; //points to the next Dnode in the linked list


};


/////////////////// LINKED LIST CLASS
class DLinkedList
{
private:

	Dnode  *head, *tail; // astericks says that head AND tail point to a Dnode<T>

// COPY FUNCTION 
	void copy(const DLinkedList& inLL);


public:

	//DEFAULT CONSTRUCTOR
	DLinkedList();

	//SINGLE VALUE CONSTRUCTOR 
	DLinkedList(const DomesticStudent& in);

	//COPY CONSTRUCTOR 
	DLinkedList(const DLinkedList& inList);

	//OVERLOADED ASSIGNMENT OPERATOR
	void operator =(const DLinkedList& rightSide);

	//DESTRUCTOR
	~DLinkedList();

	/////////////////////////////////////////////////////// MUTATOR FUNCTIONS

	//POP TOP
	DomesticStudent popTop();

	// POP BOTTOM
	DomesticStudent popBot();

	//PUSH
	void push(const DomesticStudent& Gary);


	// DELETE Dnode
	void delete_Dnode(const string& first, const string& last);


	///////////////////////////////////////////////////// ACCESSOR FUNCTIONS
	// IS EMPTY?  
	bool isEmpty() const;

	//PRINT LINKED LIST
	void print() const;

	//GET Dnode
	Dnode* get_Dnode(string category) const;

	void SearchResearchScore(const int& RScore);
	void SearchCGPA(const float& CGPAScore);
	void SearchID(const int& IDVal);
	void SearchName(const string& firstName, const string& lastName);

	//OVERLOADED OUTPUT OPERATOR
	//friend ostream& operator<< (ostream& outs, const DLinkedList& inList);
	/*
		friend const int compareCGPA(const float thisCGPA, const float CGPA);
		friend const int compareResearchScore(const int thisScore, const int score);
		friend const int compareEverything(const DomesticStudent& s1, const DomesticStudent& s2);
	*/
	void deleteTopBot();
};


#endif
