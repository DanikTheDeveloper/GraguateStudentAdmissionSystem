//								Student.cpp
#include "Student.h" //Header file included



//DEFAULT CONSTRUCTOR
Student::Student() {
	setFirstName("NO NAME");
	setLastName("NO NAME");
	setCGPA(0.0);
	setScore(0);
	setID(20200000);
}
//NON-DEFAULT CONSTRUCTOR
Student::Student(const string firstName, const string lastName, const float CGPA, const int score, int numOfStudents) {
	setFirstName(firstName);
	setLastName(lastName);
	setCGPA(CGPA);
	setScore(score);
	generateID(numOfStudents);
}

//prints the type
string Student::printType() {
	return "Student";
}

//this function takes a number if students and assignes the value according to it
void Student::generateID(int numOfStudents) {
	int id = 20200000 + numOfStudents;
	this->setID(id);
}

//Accessor functions
const string Student::getFirstName() const {
	return firstName;
}
const string Student::getLastName() const {
	return lastName;
}
const float Student::getCGPA() const {
	return CGPA;
}
const int Student::getScore() const {
	return score;
}
const int Student::getID() const {
	return ID;
}

//Mutator functions
void Student::setFirstName(const string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(const string lastName) {
	this->lastName = lastName;
}
void Student::setCGPA(const float CGPA) {
	this->CGPA = CGPA;
}
void Student::setScore(const int score) {
	this->score = score;
}
void Student::setID(const int id) {
	this->ID = id;
}

const bool Student::compareFullName(const string first, const string last)
{
	if ((first == firstName) && (last == lastName))
		return true;
	else
		return false;
}


//Friend functions for comparisons
//compareCGPA compares two CGPAs and returns different values depending on comparison
const int compareCGPA(const float thisCGPA, const float CGPA) {
	if (thisCGPA > CGPA)
		return 1;
	else if (thisCGPA < CGPA)
		return -1;
	else return 0;
}
//comapreResearchScore compares two research scores and returns different values depending on comparison
const int compareResearchScore(const int thisScore, const int score) {
	if (thisScore > score)
		return 1;
	else if (thisScore < score)
		return -1;
	else return 0;
}
//compareFirstName compares two strings letter by letter and returns different values depending on comparison
const int compareFirstName(const string thisFirstName, const string firstName) {
	for (int i(0); ; i++)
		if (thisFirstName[i] == ' ' && firstName[i] != ' ')
			return -1;
		else if (firstName[i] == ' ' && thisFirstName[i] != ' ')
			return 1;
		else if (thisFirstName[i] > firstName[i])
			return 1;
		else if (thisFirstName[i] < firstName[i])
			return -1;
	return 0;
}
//compareLastName compares two strings letter by letter and returns different values depending on comparison
const int compareLastName(const string thisLastName, const string lastName) {
	for (int i(0); ; i++)
		if (thisLastName[i] == ' ' && lastName[i] != ' ')
			return -1;
		else if (lastName[i] == ' ' && thisLastName[i] != ' ')
			return 1;
		else if (thisLastName[i] > lastName[i])
			return 1;
		else if (thisLastName[i] < lastName[i])
			return -1;
	return 0;
}

const int compareEverything(const Student& s1, const Student& s2)
{
	if (compareResearchScore(s1.getScore(), s2.getScore()) != 0)
		return compareResearchScore(s1.getScore(), s2.getScore());
	else if (compareCGPA(s1.getCGPA(), s2.getCGPA()) != 0)
		return compareCGPA(s1.getCGPA(), s2.getCGPA());

}




