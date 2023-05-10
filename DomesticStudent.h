//							Domestic Student .h


#ifndef DOMESTIC_STUDENT_H
#define DOMESTIC_STUDENT_H


#include <iostream> //iostream library included
#include <string> //string library included
#include "Student.h" //Parent class header file included

using namespace std; //Standard namespace used
//DomesticStudent class


class DomesticStudent :public Student //This class is a child class of Student class
{
public:
	//Default constructor
	DomesticStudent();
	//User-input constructor
	DomesticStudent(const string firstName, const string lastName, const float CGPA, const int score, const int numOfStudents, const string& province);
	//Mutator functions
	void setProvince(const string& Nprovince);
	void setAll(const string firstName, const string lastName, const float CGPA, const int score, const int numOfStudents, const string& province);
	//Accessor function
	string getProvince() const;
	//Friend function to overload << operator
	friend ostream& operator<<(ostream &out, DomesticStudent domestic);
	//Friend function to compare two strings (provinces)
	friend const int compareProvince(const string thisProvince, const string province);
	const bool checkEverithing() const;


private:
	//Private member variable province.
	string province;
};

/*
const int compareEverything(const DomesticStudent d1, const DomesticStudent d2)
{
	if (compareResearchScore(d1.getScore(), d2.getScore()) != 0)
		return compareResearchScore(d1.getScore(), d2.getScore());
	else if(compareCGPA(d1.getCGPA(), d2.getCGPA()) != 0)
		return compareCGPA(d1.getCGPA(), d2.getCGPA());
	//else return compareProvince(d1.getProvince(), d2.getProvince());
}
*/


#endif
