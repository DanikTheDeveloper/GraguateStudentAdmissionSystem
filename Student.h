//							Student Header File
//Author Daniyar Umuraliyev



#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;


class Student {
public:
	Student();//DEFAULT CONSTRUCTOR
	Student(const string firstName, const string lastName, const float CGPA, const int score, int numOfStudents);//NON-DEFAULT CONSTRUCTOR

	string printType();

	void generateID(int numOfStudents);//this function takes a number of students and assignes the value according to it

	//Accessor functions
	const string getFirstName() const;
	const string getLastName() const;
	const float getCGPA() const;
	const int getScore() const;
	const int getID() const;

	//Mutator functions
	void setFirstName(const string firstName);
	void setLastName(const string lastName);
	void setCGPA(const float CGPA);
	void setScore(const int score);
	void setID(const int id);


	//Friend functions to make comparisons which are used for sorting later. (GPA, ResearchScore,FirstName, LastName)
	friend const int compareCGPA(const float thisCGPA, const float CGPA);
	friend const int compareResearchScore(const int thisScore, const int score);
	friend const int compareFirstName(const string thisFirstName, const string firstName);
	friend const int compareLastName(const string thisLastName, const string lastName);
	friend const int compareEverything(const Student& s1, const Student& s2);
	const bool compareFullName(const string first, const string last);

private:
	//member variables
	string firstName, lastName;
	float CGPA;
	int score, ID;
};





#endif
