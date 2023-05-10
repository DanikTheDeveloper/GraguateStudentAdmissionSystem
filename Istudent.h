//INTERNATIONAL STUDENTS .hpp
//Jacob Tong
// the reason we have another set of get/set functions in International Student class is because we need to access toeflscore's (private member variable) data from the international class. We never instantiate a ToeflScore variable, only IStudent variables. Therefore, Istudent has get/set functions to change its toeflscore. These get/set funcions invoke ToeflScore class functions to do so.    

#ifndef ISTUDENT_H
#define ISTUDENT_H

#include <iostream>
#include <string>
#include "Student.h" //Parent class Student included
#include "ToeflScore.h" //Includes ToeflScore class

using namespace std;
class Istudent : public Student // the semicolon denotes the second statement is the parent class 
{

public:

	//CONSTRUCTOR FUNCTIONS
	//USER-INPUT CONSTRUCTOR
	Istudent();
	Istudent(const string name1, const string name2, const int in_CGPA, const int in_Rscore, const int in_stuID, const string in_country, const int reading, const int listening, const int speaking, const int writing);

	//ACCESSOR FUNCTIONS
	string getCountry() const;

	ToeflScore getToeflScore() const;
	int getReadingScore() const;
	int getListeningScore() const;
	int getWritingScore() const;
	int getSpeakingScore() const;
	int getTotalScore();



	//MUTATOR FUNCTIONS
	void setCountry(const string in_country);

	//can set ToeflScore stuff via International Student class
	void setReadingScore(const int& reading);
	void setListeningScore(const int& listening);
	void setSpeakingScore(const int& speaking);
	void setWritingScore(const int& writing);

	string printType();

	//Friend function for comparing country name strings
	friend const int compareCountry(const string thisCountry, const string country);
	//Friend function to overload << operator
	friend ostream& operator<<(ostream &out, Istudent international);
	const bool checkEverithing() const;


private:
	//inherits float CGPA; int research; first name, last name,  
	string country;
	ToeflScore toeflscore;

};

/*
const int compareEverything(const Istudent d1, const Istudent d2)
{
	if (compareResearchScore(d1.getScore(), d2.getScore()) != 0)
		return compareResearchScore(d1.getScore(), d2.getScore());
	else if (compareCGPA(d1.getCGPA(), d2.getCGPA()) != 0)
		return compareCGPA(d1.getCGPA(), d2.getCGPA());

}
*/


#endif
