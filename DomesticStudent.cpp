//Domestic Student class definition cpp file

#include "DomesticStudent.h" //Header file included
#include <iomanip>			 //iomanip used for setw function

//Default constructor (Student is parent class)
DomesticStudent::DomesticStudent() : Student()
{
	province = "NO ENTRY";
}
//User input constructor (Student is parent class). Uses setAll member function
DomesticStudent::DomesticStudent(const string firstName, const string lastName, const float CGPA, const int score, const int numOfStudents, const string &province) : Student(firstName, lastName, CGPA, score, numOfStudents)
{
	setAll(firstName, lastName, CGPA, score, numOfStudents, province);
}
//Mutator function setProvince
void DomesticStudent::setProvince(const string &Nprovince)
{
	province = Nprovince;
}
//setAll Mutator function sets the values of member variables to what the user provides
void DomesticStudent::setAll(const string firstName, const string lastName, const float CGPA, const int score, const int numOfStudents, const string &province)
{
	setProvince(province);
	setFirstName(firstName);
	setLastName(lastName);
	setCGPA(CGPA);
	setScore(score);
	generateID(numOfStudents);
}
//getProvince accessor function
string DomesticStudent::getProvince() const
{
	return province;
}



// Overloaded operator friend function to print out domestic student data
ostream &operator<<(ostream &out, DomesticStudent domestic)
{

	out << left << setw(20) << domestic.getFirstName();
	out << setw(20) << domestic.getLastName();
	out << setw(14) << left << domestic.getID();
	out << setw(12) << domestic.getProvince();
	out << setw(10) << left << setprecision(4) << domestic.getCGPA();
	out << left << setw(18) << domestic.getScore();
	out << endl;
	return out;
}
const bool DomesticStudent::checkEverithing() const
{

	const string PROVINCES[13] = { "BC", "AB", "ON", "YT", "NT", "NU", "MB", "SK", "NS", "NB", "PE", "QC", "NL" };

	bool flag = false;
	for (int i = 0; i < 13; i++)
		if (PROVINCES[i] == this->getProvince())
			flag = true;
	if (!flag)
		return false;
	if (this->getCGPA() < 0 || this->getCGPA() > 4.33)
		return false;
	if (this->getScore() < 0 || this->getScore() > 100)
		return false;
	if (this->getID() / 100000 != 202)
		return false;

	return true;
}

//compareProvince friend function compares two province strings letter by letter and returns different values.
const int compareProvince(const string thisProvince, const string province)
{
	for (int i(0);; i++)
		if (thisProvince[i] == ' ' && province[i] != ' ')
			return -1;
		else if (province[i] == ' ' && thisProvince[i] != ' ')
			return 1;
		else if (thisProvince[i] > province[i])
			return 1;
		else if (thisProvince[i] < province[i])
			return -1;
	return 0;
}


