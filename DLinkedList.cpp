//							Linked List .cpp 
/*
This is a linked list class. We will be using a linked list template to connect and maintain a sorted, linked list of
Dnodes containing data from the DomesticStudent class.
A merged linked list can contain any number of Dnodes containing data from any child class



*/

#include "DLinkedList.h"



//DEFAULT CONSTRUCTOR
DLinkedList::DLinkedList()
{
	head = NULL;
	tail = NULL;
}

//SINGLE VALUE CONSTRUCTOR
// Will accept one value 
DLinkedList::DLinkedList(const DomesticStudent& in)
{
	push(in);
}

//COPY CONSTRUCTOR
// copy function copies inList to THIS linked list. 
// copy automatically reads inList fully and the information per inList's Dnode is pushed into THIS linked list. 
DLinkedList::DLinkedList(const DLinkedList& inList)
{
	if (inList.isEmpty());
	else
		copy(inList);

}

//OVERLOADED ASSIGNMENT OPERATOR
// copy automatically reads rightSide linked list and pushes the data within each Dnode (in rightSide) into THIS 
// linked list's Dnodes. Head and tail are assigned by push automatically and copy runs push until the rightSide is copied.
void DLinkedList::operator =(const DLinkedList& rightSide)
{

	copy(rightSide);

}

//DESTRUCTOR
// pop will keep running until the linked list is empty
DLinkedList::~DLinkedList()
{
	while (isEmpty() == false)
	{
		popTop();
	}

}

/////////////////////////////////////////////////////// MUTATOR FUNCTIONS

//POP TOP
// no arguments to pass in
// the most recent Dnode is deleted and its value is returned. We delete the top Dnode and return its value.
DomesticStudent DLinkedList::popTop()
{
	DomesticStudent hold;
	// If the list is empty, do nothing
	if (isEmpty() == true)
		cout << "List is empty. Nothing to pop" << endl;
	// If there's only one Dnode
	else if (head->link == NULL)
	{
		hold = head->data;
		delete head;
		head = NULL;
		tail = NULL;
		return hold;
	}
	// aka If there's >1 Dnode and (isEmpty() == false) 
	else
	{
		Dnode* temp = head->link;
		hold = head->data;
		delete head;
		head = temp;
		return hold;

	}
	return hold;
}
// POP BOTTOM
// no arguments to pass in
// temp1 and temp2 are Dnode pointers. temp1 is always above temp2. They descend from the top of the list to the bottom.
// Once at the bottom, the bottom Dnode is popped and tail is reassigned. Return value is the value of the Dnode you popped.
DomesticStudent DLinkedList::popBot()
{
	DomesticStudent hold;
	// If the list is empty
	if (isEmpty() == true);
	// if there's only one Dnode in the list
	else if (head == tail)
	{
		hold = tail->data;
		delete tail;
		head = NULL;
		tail = NULL;
		return hold;
	}
	// if there's >1 Dnode in the list
	else
	{
		Dnode* temp1, *temp2;
		temp1 = head;
		temp2 = head->link;
		while (temp2->link != NULL)
		{
			temp1 = temp2;
			temp2 = temp2->link;

		}
		hold = temp2->data;
		delete temp2;
		tail = temp1;
		return hold;
	}
	return hold;
}

//PUSH
// this takes a DomesticStudent object to put into the linked list. DomesticStudent passed is called "Gary" within the function 
//This function maintains the sorted-characteristic
// of DomesticStudents by prioritizing Research Score, then CGPA.
// Here, we check if: a) linked list is empty	b) if Gary is bigger than head	c) if Gary is smaller than tail
// d)if Gary is none of the above		then we insert the DomesticStudent into the list
void DLinkedList::push(const DomesticStudent& Gary)
{
	try {

		//CASE 0: Linked List is empty. Just pop it in
		if (isEmpty() == true) {
			head = new Dnode;
			head->data = Gary;
			tail = head;
		}

		//CASE 1: Gary is bigger than the first Dnode
		else if (compareEverything(Gary, head->data) == 1)
		{
			Dnode* created = new Dnode;
			created->data = Gary;
			Dnode* temp = head;
			head = created;
			created->link = temp;
			temp = NULL;
		}
		// CASE 2: Gary is smaller than the last Dnode
		else if (compareEverything(Gary, tail->data) == -1)
		{
			Dnode* created = new Dnode;
			created->data = Gary;
			Dnode* temp = tail;
			tail = created;
			temp->link = created;
			temp = NULL;
		}
		// CASE 3: Gary is in-between a Dnode within the linked list
		// we set temp1 and temp2 where temp1 is always above temp2. We move each down the list and compare Gary
		// with temp2. If Gary is smaller than (compareEverything == -1) temp2, we keep moving down. This
		// happens until Gary is equal to temp2->data (which holds a DomesticStudent class object).
		// **Note: if temp1 = head, temp2 = head->link initially, we need to compare Gary to the first Dnode
		// in the linked list. Afterwards, we compare Gary to temp2 in a loop. 
		else
		{
			Dnode *temp1 = head;
			Dnode *temp2 = temp1->link;

			// Compare Gary to the top Dnode
			if (compareEverything(Gary, temp1->data) == 0)
			{
				Dnode* temporary = head;
				head = new Dnode;
				head->data = Gary;
				head->link = temporary;
				temporary = NULL;

			}
			else {
				// Loop to see where Gary fits into the linked list
				bool flag = true;
				do {
					// aka if Gary is smaller than temp2 then temp1 and temp2 goes down the list
					if (compareEverything(Gary, temp2->data) == -1)
					{
						temp1 = temp1->link;
						temp2 = temp2->link;
					}
					// aka if Gary is equal to temp's data, insert it into the list
					else if ((compareEverything(Gary, temp2->data) == 0) || (compareEverything(Gary, temp2->data) == 1))
					{
						Dnode* temporary = new Dnode;
						temporary->data = Gary;
						temp1->link = temporary;
						temporary->link = temp2;
						temporary = NULL;
						flag = false;
					}
					// aka if temp1 becomes the tail/bottom Dnode
					else if (temp1->link == NULL)
					{
						std::cout << "\nError adding Dnode\n";
						flag = false;
					}

				} while (flag == true);

			}
		}//outer else

	} // catch function
	catch (bad_alloc)
	{
		cout << "Not enough memory to allocate. " << endl;
	}

}


// DELETE Dnode
// we create Dnode pointers temp1 and temp2 where temp1 is always above temp2 in the linked list
// If temp2 matches the name, we delete the Dnode.
// We keep deleting all Dnodes with the same input name until we reach the end of the linked list.
void DLinkedList::delete_Dnode(const string& first, const string& last)
{
	Dnode *temp1, *temp2;
	temp1 = head;
	temp2 = head->link;


	while (temp1->link != NULL) // when temp1->link == NULL, temp2 is NULL and so we end the algorithm
	{
		//EXCEPTION CASE:
		//Since our intialization of temp1 = head, we compare head->data to name. Once
		// our name no longer matches temp1 = head, we move on to the regular cases.
		if ((temp1 == head) && ((temp1->data).compareFullName(first, last) == true))
		{
			head = temp2;
			delete temp1;
			temp1 = temp2;
			temp2 = temp2->link;
			continue;
		}

		//REGULAR CASES
		// if temp2's DomesticStudent object's name is the same as our inputname, delete
		// otherwise, keep moving down the linked list.
		if ((temp2->data).compareFullName(first, last) == true)
		{
			//Dnode<T>* temporary = temp2;
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
bool DLinkedList::isEmpty() const
{
	if (head == NULL || tail == NULL)
		return true;
	else
		return false;
}

//GET Dnode
// basically, we return tail or head Dnode pointers. If someone specifies "tail", we return the tail Dnode. Otherwise, if
//someone spelled it wrong or specifies "head", we return the head of the linked list.
Dnode* DLinkedList::get_Dnode(string category) const
{
	if (category == "tail")
		return tail;
	else
		return head;

}


//OVERLOADED OUTPUT OPERATOR
// calls in DomesticStudent overloaded operator. Since data in the Dnodes are of DomesticStudent data type, we print it out.  
ostream& operator<< (ostream& outs, const DLinkedList& inList)
{

	Dnode* temp = inList.get_Dnode("head");
	DomesticStudent hold;
		while(true)
		{
			hold = temp->data;
			cout << hold;
			if(temp->link == NULL)
			break;

			temp = temp->link;
		}
		outs << endl;
	return outs;

}

//PRINT FUNCTION
void DLinkedList::print() const
{
	Dnode* temp = head;
	DomesticStudent hold;
	while (true)
	{
		hold = temp->data;
		cout << hold;
		if (temp->link == NULL) break;
		temp = temp->link;
	}
}

/////////////////////////////////////////////////// HELPER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// COPY FUNCTION
// this function will be used in the copy constructor and overloaded assignment operator
// we require another Linked List object to be input
// from the input, we duplicate that linked list and associate it to this linked list - a deep copy
//Algorithm: temp is inLL's head. Then, we push temp->data into THIS linked list until temp becomes NULL. 
// Notice that push function already creates a new Dnode, thus we don't need to duplicate a linked list. We merely read the
// input linked list's DomesticStudent objects and push that data into THIS linked list as new Dnodes. 
void DLinkedList::copy(const DLinkedList& inLL)
{
	Dnode* temp = inLL.get_Dnode("head"); //temp points to inLL's head pointer

	//ERROR CHECKING
	if (inLL.isEmpty())
	{
		std::cout << "\nList input cannot be duplicated because it is empty.\n";
		return;
	}

	while (temp != NULL)
	{
		push(temp->data);
		temp = temp->link;
	}
}


void DLinkedList::SearchDomesticResearchScore(const int& RScore)
{
	if (RScore < 0 || RScore > 100)
	{
		cout << "\nInvalid research score. Should be between 0-100!\n";
		return;
	}
	Dnode* temp = head;
	int numFound = 0;
	if (head == NULL)
	{
		std::cout << "\nDomestic Student List is Empty.\n";
		return;
	}
	while (temp != NULL)
	{
		DomesticStudent currentDStduent = temp->data;
		if (currentDStduent.getScore() == RScore)
		{
			cout << currentDStduent;
			numFound++;
		}
		temp = temp->link;
	}
	if (numFound == 0)
		cout << "\nNo domestic student in the list has a research score of " << RScore << "!" << endl;
}

void DLinkedList::SearchDomesticCGPA(const float& CGPAScore)
{
	Dnode* temp = head;
	int numFound = 0;
	if (CGPAScore < 0.00 || CGPAScore > 4.30)
	{
		cout << "\nInvalid CGPA score. Should be between 0.00-4.30!\n";
		return;
	}
	if (head == NULL)
	{
		std::cout << "\nDomestic Student List is Empty. \n";
		return;
	}
	while (temp != NULL)
	{
		DomesticStudent currentDStduent = temp->data;
		if (currentDStduent.getCGPA() == CGPAScore)
		{
			cout << currentDStduent;
			numFound++;
		}
		temp = temp->link;
	}
	if (numFound == 0)
		cout << "\nNo domestic student in the list has a CGPA of " << CGPAScore << "!" << endl;
}

void DLinkedList::SearchDomesticID(const int& IDVal)
{
	Dnode* temp = head;
	int numFound = 0;
	if (IDVal < 20200000 || IDVal > 20210000)
	{
		cout << "\nInvalid application ID. Valid IDs are between 20200000-20210000!\n";
		return;
	}
	if (head == NULL)
	{
		std::cout << "\nDomestic Student List is Empty. \n";
		return;
	}
	while (temp != NULL)
	{
		DomesticStudent currentDStduent = temp->data;
		if (currentDStduent.getID() == IDVal)
		{
			cout << currentDStduent;
			numFound++;
		}
		temp = temp->link;
	}
	if (numFound == 0)
		cout << "\nNo domestic student in the list has an application ID of " << IDVal << "!" << endl;
}

void DLinkedList::SearchDomesticName(const string& firstName, const string& lastName)
{
	Dnode* temp = head;
	int numFound = 0;
	if (head == NULL)
	{
		std::cout << "\nDomestic Student List is Empty. \n";
		return;
	}
	while (temp != NULL)
	{
		DomesticStudent currentDStduent = temp->data;

		if (currentDStduent.getFirstName() == firstName && currentDStduent.getLastName() == lastName)
		{
			cout << currentDStduent;
			numFound++;
		}
		temp = temp->link;
	}
	if (numFound == 0)
		cout << "\nNo domestic student with the name " << firstName << " " << lastName << " found!" << endl;
}

void DLinkedList::deleteTopBot() {
	popTop();
	popBot();
}
