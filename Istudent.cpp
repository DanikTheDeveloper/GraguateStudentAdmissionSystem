//							INTERNATIONAL STUDENT .cpp

#include "Istudent.h" //Header file included
#include <iomanip>
#include <sstream>
#include <cstdlib>

//CONSTRUCTOR FUNCTIONS
//Default constructor
Istudent::Istudent()
{
	country = "Atlantis";
}

//User-defined constructor
Istudent::Istudent(const string name1, const string name2, const int in_CGPA, const int in_Rscore, const int in_stuID, const string in_country, const int reading, const int listening, const int speaking, const int writing)
{

	Student(name1, name2, in_CGPA, in_Rscore, in_stuID);
	country = in_country;
	toeflscore.setReadingScore(reading);
	toeflscore.setListeningScore(listening);
	toeflscore.setSpeakingScore(speaking);
	toeflscore.setWritingScore(writing);
}

//ACCESSOR FUNCTIONS
string Istudent::getCountry() const
{
	return country;
}

ToeflScore Istudent::getToeflScore() const
{
	return toeflscore;
}

string Istudent::printType()
{
	return "International";
}

int Istudent::getTotalScore()
{
	int temp = toeflscore.getTotalScore();
	return temp;
}

int Istudent::getReadingScore() const
{
	return toeflscore.getReadingScore();
}

int Istudent::getListeningScore() const
{
	return toeflscore.getListeningScore();
}

int Istudent::getWritingScore() const
{
	return toeflscore.getWritingScore();
}

int Istudent::getSpeakingScore() const
{
	return toeflscore.getSpeakingScore();
}

//MUTATOR FUNCTIONS
void Istudent::setCountry(const string in_country)
{
	country = in_country;
}

void Istudent::setReadingScore(const int &reading)
{

	toeflscore.setReadingScore(reading);
}

void Istudent::setListeningScore(const int &listening)
{

	toeflscore.setListeningScore(listening);
}

void Istudent::setSpeakingScore(const int &speaking)
{

	toeflscore.setSpeakingScore(speaking);
}

void Istudent::setWritingScore(const int &writing)
{

	toeflscore.setWritingScore(writing);
}

// Overloaded operator to print out international student data
ostream &operator<<(ostream &out, Istudent international)
{

	out << left << setw(20) << international.getFirstName();
	out << setw(20) << international.getLastName();
	out << setw(14) << international.getID();
	out << setw(10) << international.getCountry();
	out << setw(10) << left << setprecision(4) << international.getCGPA();
	out << left << setw(18) << international.getScore();

	out << setw(15) << left << international.getTotalScore();
	out << setw(12) << left << international.getReadingScore();
	out << setw(12) << left << international.getListeningScore();
	out << setw(12) << left << international.getSpeakingScore();
	out << setw(12) << left << international.getWritingScore();
	out << endl;
	return out;
}


const bool Istudent::checkEverithing() const
{

	const string COUNTRIES[7] = { "India", "China", "Korea", "Iran", "Mexico", "Afghanistan", "Vietnam" };

	bool flag = false;

	for (int i = 0; i < 7; i++)
		if (COUNTRIES[i] == country)
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


const int compareCountry(const string thisCountry, const string country)
{
	for (int i(0);; i++)
		if (thisCountry[i] == ' ' && country[i] != ' ')
			return -1;
		else if (country[i] == ' ' && thisCountry[i] != ' ')
			return 1;
		else if (thisCountry[i] > country[i])
			return 1;
		else if (thisCountry[i] < country[i])
			return -1;
	return 0;
}



