//							Linked List .cpp 
/*
This is a linked list class. We will be using a linked list template to connect and maintain a sorted, linked list of 
nodes containing data from the student class.
A merged linked list can contain any number of nodes containing data from any child class



*/

#include "LinkedList.h"



//DEFAULT CONSTRUCTOR
    LinkedList::LinkedList()
    {
        this->head = NULL;
	this->tail = NULL;
    }

//SINGLE VALUE CONSTRUCTOR
// Will accept one value 
    LinkedList::LinkedList(const Student& in) 
    {
        push(in);
    }

//COPY CONSTRUCTOR
// copy function copies inList to THIS linked list. 
// copy automatically reads inList fully and the information per inList's node is pushed into THIS linked list. 
LinkedList::LinkedList(const LinkedList& inList)
{
	if(inList.isEmpty());
	else
	copy(inList);	

}

//OVERLOADED ASSIGNMENT OPERATOR
// copy automatically reads rightSide linked list and pushes the data within each node (in rightSide) into THIS 
// linked list's nodes. Head and tail are assigned by push automatically and copy runs push until the rightSide is copied.
void LinkedList::operator =(const LinkedList& rightSide)
{	
	
	copy(rightSide);

}

//DESTRUCTOR
// pop will keep running until the linked list is empty
LinkedList::~LinkedList()
{
	while(isEmpty() == false)
	{
		popTop();	
	}
	cout << "\nLinked List destructor working.\n";
} 

/////////////////////////////////////////////////////// MUTATOR FUNCTIONS

//POP TOP
// no arguments to pass in
// the most recent node is deleted and its value is returned. We delete the top node and return its value.
Student LinkedList::popTop()
{
	// If the list is empty, do nothing
	if(isEmpty() == true)
	cout << "List is empty. Nothing to pop"<<endl;
	// If there's only one node
	else if(head->link == NULL)
	{
		Student hold = head->data;
		delete head;
		head = NULL;
		tail = NULL;
	cout << "popTop() called and executed.\n";
		return hold;
	}
	// aka If there's >1 node and (isEmpty() == false) 
	else
	{
		node* temp = head->link;
		Student hold = head->data;
		delete head;
		head = temp;
	cout << "popTop() called and executed.\n";
		return hold;

	}
	
}
// POP BOTTOM
// no arguments to pass in
// temp1 and temp2 are node pointers. temp1 is always above temp2. They descend from the top of the list to the bottom.
// Once at the bottom, the bottom node is popped and tail is reassigned. Return value is the value of the node you popped.
Student LinkedList::popBot()
{
	// If the list is empty
	if(isEmpty() == true);
	// if there's only one node in the list
	else if( head == tail)
	{
		Student hold = tail->data;
		delete tail;
		head = NULL;
		tail = NULL;
		return hold;
	}
	// if there's >1 node in the list
	else
	{
		node* temp1, *temp2;
		temp1 =  head;
		temp2 = head->link;
		while(temp2->link != NULL)
		{
			temp1 = temp2;
			temp2 = temp2->link;
	
		}
		Student hold = temp2->data;
		delete temp2;
		tail = temp1;
		return hold;
	}

}

//PUSH
// this takes a student object to put into the linked list. Student passed is called "Gary" within the function 
//This function maintains the sorted-characteristic
// of students by prioritizing Research Score, then CGPA.
// Here, we check if: a) linked list is empty	b) if Gary is bigger than head	c) if Gary is smaller than tail
// d)if Gary is none of the above		then we insert the student into the list
void LinkedList::push(const Student& Gary)
{
	try{

	//CASE 0: Linked List is empty. Just pop it in
	if(isEmpty() == true){
	head = new node;
	head->data = Gary;
	tail = head;	
	cout << "Push function case 0 success.\n";
	}

	//CASE 1: Gary is bigger than the first node
	else if(compareEverything(Gary, head->data) == 1)
	{
		node* created = new node;
		created->data = Gary;
		node* temp = head;
		head = created;
		created->link = temp;
		temp = NULL;
	cout << "Push function case 1 success.\n";
	}	
	// CASE 2: Gary is smaller than the last node
	else if(compareEverything(Gary, tail->data) == -1)
	{
		node* created = new node;
		created->data = Gary;
		node* temp = tail;
		tail = created;
		temp->link = created;
		temp = NULL;
	cout << "Push function case 2 success.\n";
	}
	// CASE 3: Gary is in-between a node within the linked list
	// we set temp1 and temp2 where temp1 is always above temp2. We move each down the list and compare Gary
	// with temp2. If Gary is smaller than (compareEverything == -1) temp2, we keep moving down. This
	// happens until Gary is equal to temp2->data (which holds a student class object).
	// **Note: if temp1 = head, temp2 = head->link initially, we need to compare Gary to the first node
	// in the linked list. Afterwards, we compare Gary to temp2 in a loop. 
	else
	{
		node *temp1 = head;
		node *temp2 = temp1->link;
		
		// Compare Gary to the top node
		if(compareEverything(Gary, temp1->data) == 0)
		{
			node* temporary = head;
			head = new node;
			head->data = Gary;
			head->link = temporary;
			temporary = NULL;
			cout << "Push function default.0 case success.\n";
					
		}
   	   else{
			// Loop to see where Gary fits into the linked list
			bool flag = true;
		   do{
			// aka if Gary is smaller than temp2 then temp1 and temp2 goes down the list
			if(compareEverything(Gary, temp2->data) == -1) 
			{
				temp1 = temp1->link;
				temp2 = temp2->link;
			} 
			// aka if Gary is equal to temp's data, insert it into the list
			else if( (compareEverything(Gary, temp2->data) == 0) || (compareEverything(Gary, temp2->data) == 1) )
			{
				node* temporary = new node;
				temporary->data = Gary;
				temp1->link = temporary;
				temporary->link = temp2;
				temporary = NULL;
				flag = false;	
				cout << "Push function default case success.\n";
			}
			// aka if temp1 becomes the tail/bottom node
			else if(temp1->link == NULL)
			{
				std::cout << "\nError adding node\n";
				flag = false;
			}

    	   	     }while(flag == true); 
		
		}
	}//outer else

	} // catch function
	catch(bad_alloc)
	{
		cout << "Not enough memory to allocate. " << endl;
	}	

}


// DELETE NODE
// we create node pointers temp1 and temp2 where temp1 is always above temp2 in the linked list
// If temp2 matches the name, we delete the node.
// We keep deleting all nodes with the same input name until we reach the end of the linked list.
void LinkedList::delete_node(const string& first, const string& last)
{
	node *temp1, *temp2;
	temp1 = head;
	temp2 = head->link;


	while(temp1->link != NULL) // when temp1->link == NULL, temp2 is NULL and so we end the algorithm
	{
		//EXCEPTION CASE:
		//Since our intialization of temp1 = head, we compare head->data to name. Once
		// our name no longer matches temp1 = head, we move on to the regular cases.
		if( (temp1 == head) && ((temp1->data).compareFullName(first, last) == true) )	
		{
			head = temp2;
			delete temp1;
			temp1 = temp2;
			temp2 = temp2->link;
			continue;
		}
		
		//REGULAR CASES
		// if temp2's student object's name is the same as our inputname, delete
		// otherwise, keep moving down the linked list.
		if( (temp2->data).compareFullName(first, last) == true)
		{
			//node<T>* temporary = temp2;
			temp1->link = temp2->link;
			delete temp2;
			temp2 = temp1->link;

		}
		else 
		{
			temp1 = temp1->link;
			temp2 = temp2->link;
		}

	}	

}


///////////////////////////////////////////////////// ACCESSOR FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// IS EMPTY?
// no arguments to pass in
// checks if top pointer is null or not OR tail is null. 
// returns true if head OR tail pointers are null.  
bool LinkedList::isEmpty() const
{
	if(head == NULL || tail == NULL)
	return true;
	else
	return false;
}

//GET NODE
// basically, we return tail or head node pointers. If someone specifies "tail", we return the tail node. Otherwise, if
//someone spelled it wrong or specifies "head", we return the head of the linked list.
node* LinkedList::get_node( string category) const
{
	if(category == "tail")
	return tail;
	else 
	return head;

}


//OVERLOADED OUTPUT OPERATOR
// calls in Student overloaded operator. Since data in the nodes are of Student data type, we print it out.  
ostream& operator<< (ostream& outs, const LinkedList& inList)
{
	//node* temp = inList.get_node("head");
	node* temp = inList.head;
	Student hold;
/*	while(true)
	{
		hold = temp->data;
		cout << hold;
		if(temp->link == NULL)
		break;
		
		temp = temp->link;
	}	
*/	outs << endl;	
	return outs;

/*		outs << temp->data;
		if(temp->link == NULL)
		break;

		temp = temp->link;
	
	}	
*/

}

//PRINT FUNCTION
void LinkedList::print() const
{
	node* temp = head;
	Student hold;
	while(true)
	{
		hold = temp->data;
		cout << hold;
		if(temp->link == NULL) break;
		temp = temp->link;
	}
}	

/////////////////////////////////////////////////// HELPER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// COPY FUNCTION
// this function will be used in the copy constructor and overloaded assignment operator
// we require another Linked List object to be input
// from the input, we duplicate that linked list and associate it to this linked list - a deep copy
//Algorithm: temp is inLL's head. Then, we push temp->data into THIS linked list until temp becomes NULL. 
// Notice that push function already creates a new node, thus we don't need to duplicate a linked list. We merely read the
// input linked list's student objects and push that data into THIS linked list as new nodes. 
node* LinkedList::copy(const LinkedList& inLL)
{
	node* temp = inLL.get_node("head"); //temp points to inLL's head pointer

	//ERROR CHECKING
	if(inLL.isEmpty())
	{
		std::cout << "\n List input cannot be duplicated because it is empty.\n";

	}
	else
	{
		while(temp != NULL)
		{
			push(temp->data);	
			temp = temp->link;	
		} 
		
	}

}


