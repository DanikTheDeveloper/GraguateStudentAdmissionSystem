//							Linked List .h 
/*
This is a linked list class. We will be using a linked list template to connect and maintain a sorted, linked list of 
nodes containing data from the student class.
A merged linked list can contain any number of nodes containing data from any child class



*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Student.h"
#include "DomesticStudent.h"
#include "Istudent.h"
#include <iostream>
using namespace std;

//////////////// NODE CLASS
class node{

public:
Student data; //will hold DomesticStudent or Istudent objects, for this program
node* link; //points to the next node in the linked list


};


/////////////////// LINKED LIST CLASS
class LinkedList
{
private:

	node  *head, *tail; // astericks says that head AND tail point to a node<T>
    
// COPY FUNCTION 
node* copy(const LinkedList& inLL);


public:

//DEFAULT CONSTRUCTOR
    LinkedList();

//SINGLE VALUE CONSTRUCTOR 
	LinkedList(const Student& in);

//COPY CONSTRUCTOR 
LinkedList(const LinkedList& inList);

//OVERLOADED ASSIGNMENT OPERATOR
void operator =(const LinkedList& rightSide);

//DESTRUCTOR
~LinkedList();

/////////////////////////////////////////////////////// MUTATOR FUNCTIONS

//POP TOP
Student popTop();

// POP BOTTOM
Student popBot();

//PUSH
void push(const Student& Gary);


// DELETE NODE
void delete_node(const string& first, const string& last);


///////////////////////////////////////////////////// ACCESSOR FUNCTIONS
// IS EMPTY?  
bool isEmpty() const;

//PRINT LINKED LIST
void print() const;

//GET NODE
node* get_node( string category) const;

//OVERLOADED OUTPUT OPERATOR
friend ostream& operator<< (ostream& outs, const LinkedList& inList);
/*
	friend const int compareCGPA(const float thisCGPA, const float CGPA);
	friend const int compareResearchScore(const int thisScore, const int score); 
	friend const int compareEverything(const Student& s1, const Student& s2);
*/

};


#endif
