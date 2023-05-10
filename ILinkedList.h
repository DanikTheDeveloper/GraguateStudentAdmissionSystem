//							Linked List .h 
/*
This is a linked list class. We will be using a linked list template to connect and maintain a sorted, linked list of
Inodes containing data from the student class.
A merged linked list can contain any number of Inodes containing data from any child class



*/

#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H


#include "Student.h"
#include "Istudent.h"
#include <iostream>
using namespace std;

//////////////// Inode CLASS
class Inode {

public:
	Istudent data; //will hold Istudent or Istudent objects, for this program
	Inode* link; //points to the next Inode in the linked list


};


/////////////////// LINKED LIST CLASS
class ILinkedList
{
private:

	Inode  *head, *tail; // astericks says that head AND tail point to a Inode<T>

// COPY FUNCTION 
	void copy(const ILinkedList& inLL);


public:

	//DEFAULT CONSTRUCTOR
	ILinkedList();

	//SINGLE VALUE CONSTRUCTOR 
	ILinkedList(const Istudent& in);

	//COPY CONSTRUCTOR 
	ILinkedList(const ILinkedList& inList);

	//OVERLOADED ASSIGNMENT OPERATOR
	void operator =(const ILinkedList& rightSide);

	//DESTRUCTOR
	~ILinkedList();

	/////////////////////////////////////////////////////// MUTATOR FUNCTIONS

	//POP TOP
	Istudent popTop();

	// POP BOTTOM
	Istudent popBot();

	//PUSH
	void push(const Istudent& Gary);


	// DELETE Inode
	void delete_Inode(const string& first, const string& last);


	///////////////////////////////////////////////////// ACCESSOR FUNCTIONS
	// IS EMPTY?  
	bool isEmpty() const;

	//PRINT LINKED LIST
	void print() const;

	//GET Inode
	Inode* get_Inode(string category) const;

	void SearchResearchScore(const int& RScore);
	void SearchCGPA(const float& CGPAScore);
	void SearchID(const int& IDVal);
	void SearchName(const string& firstName, const string& lastName);

	//OVERLOADED OUTPUT OPERATOR
	friend ostream& operator<< (ostream& outs, const ILinkedList& inList);
	/*
		friend const int compareCGPA(const float thisCGPA, const float CGPA);
		friend const int compareResearchScore(const int thisScore, const int score);
		friend const int compareEverything(const Istudent& s1, const Istudent& s2);
	*/
	void deleteTopBot();
};


#endif
