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
class node {

public:
	DomesticStudent domestic;
	Istudent international;//will hold DomesticStudent or Istudent objects, for this program
	node* link; //points to the next node in the linked list


};


/////////////////// LINKED LIST CLASS
class LinkedList
{
private:

	node  *head, *tail; // astericks says that head AND tail point to a node<T>


public:

	//DEFAULT CONSTRUCTOR
	LinkedList();

	//SINGLE VALUE CONSTRUCTOR 
	LinkedList(const Istudent& ist, const DomesticStudent& dom);

	//DESTRUCTOR
	~LinkedList();

	/////////////////////////////////////////////////////// MUTATOR FUNCTIONS

	
	//PUSH
	void pushDom(const DomesticStudent& dom);
	void pushIstudent(const Istudent& dom);


	///////////////////////////////////////////////////// ACCESSOR FUNCTIONS
	// IS EMPTY?  
	bool isEmpty() const;

	//GET NODE
	node* get_node(string category) const;

	//this function compares the values of the cgpa and the reaserch score given by the user within the link,
	//and returns the values above or equal to it
	void searchThreshold(float Tcgpa, int Trscore);
};


#endif
