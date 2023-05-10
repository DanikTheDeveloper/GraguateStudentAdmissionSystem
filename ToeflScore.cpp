//ToeflScore class definition
//Author: Amirali Eghbal

#include <iostream>
#include "ToeflScore.h"

using namespace std;

//Default constructor initializing the member variables
ToeflScore::ToeflScore()
{
	readingScore = 0;
	listeningScore = 0;
	speakingScore = 0;
	writingScore = 0;
	totalScore = 0;
}

//Constructor to set the parameters, check for validity and calculate total score
ToeflScore::ToeflScore(const int &reading, const int &listening, const int &speaking, const int &writing)
{
	if (isValid(reading, listening, speaking, writing))
	{
		readingScore = reading;
		listeningScore = listening;
		speakingScore = speaking;
		writingScore = writing;
		totalScore = readingScore + listeningScore + speakingScore + writingScore;
	}
}

//Accessor for reading score
int ToeflScore::getReadingScore() const
{
	return readingScore;
}

//Accessor for listening score
int ToeflScore::getListeningScore() const
{
	return listeningScore;
}

//Acessor for speaking score
int ToeflScore::getSpeakingScore() const
{
	return speakingScore;
}

//Accessor for writing score
int ToeflScore::getWritingScore() const
{
	return writingScore;
}

//Acessor for total score which uses member function calcTotalScore
int ToeflScore::getTotalScore()
{
	calcTotalScore();
	return totalScore;
}

//Mutator for setting reading score which checks for validitiy of score
//and uses calcTotalScore member function to update total score and returns
//error if reading score was invalid.
void ToeflScore::setReadingScore(const int &reading)
{
	if (isValid(reading))
	{
		readingScore = reading;
		calcTotalScore();
	}
	else
	{
		cout << "Reading score was invlaid!" << endl;
	}
}

//Mutator for setting listening score which checks for validitiy of score
//and uses calcTotalScore member function to update total score and returns
//error if reading score was invalid.
void ToeflScore::setListeningScore(const int &listening)
{
	if (isValid(listening))
	{
		listeningScore = listening;
		calcTotalScore();
	}
	else
	{
		cout << "Listening score was invalid!" << endl;
	}
}

//Mutator for setting speaking score which checks for validitiy of score
//and uses calcTotalScore member function to update total score and returns
//error if reading score was invalid.
void ToeflScore::setSpeakingScore(const int &speaking)
{
	if (isValid(speaking))
	{
		speakingScore = speaking;
		calcTotalScore();
	}
	else
	{
		cout << "Speaking score was invalid!" << endl;
	}
}

//Mutator for setting writing score which checks for validitiy of score
//and uses calcTotalScore member function to update total score and returns
//error if reading score was invalid.
void ToeflScore::setWritingScore(const int &writing)
{
	if (isValid(writing))
	{
		writingScore = writing;
		calcTotalScore();
	}
	else
	{
		cout << "Writing score was invalid!" << endl;
	}
}

//Mutator for setting all scores which checks for validitiy of the scores
//and uses calcTotalScore member function to update total score and returns
//error if a score was invalid.
void ToeflScore::setAll(const int &reading, const int &listening, const int &speaking, const int &writing)
{
	if (isValid(reading, listening, speaking, writing))
	{
		readingScore = reading;
		listeningScore = listening;
		speakingScore = speaking;
		writingScore = writing;
		calcTotalScore();
	}
	else if (!isValid(reading))
	{
		cout << "Reading score was invalid!" << endl;
	}
	else if (!isValid(listening))
	{
		cout << "listening score was invalid!" << endl;
	}
	else if (!isValid(speaking))
	{
		cout << "Speaking score was invalid!" << endl;
	}
	else if (!isValid(writing))
	{
		cout << "Writing score was invalid!" << endl;
	}
}

//calcTotalScore member function adds all the scores together
//Precondition: Function will be called
//Postcondition: Total score is updated
void ToeflScore::calcTotalScore()
{
	totalScore = readingScore + listeningScore + speakingScore + writingScore;
}

//isValid function with 4 parameters used to check validity of all needed member variables
//Precondition: The for scores are provided by user
//Postcondition: Validity is checked using the one parameter isValid and if they are valid
//true is returned. If not false is returned.
bool ToeflScore::isValid(const int &reading, const int &listening, const int &speaking, const int &writing)
{
	if (isValid(reading) && isValid(listening) && isValid(speaking) && isValid(writing))
		return true;
	else
	{
		return false;
	}
}

//isValid function with one parameter used to check validity of input by user.
//Precondition: User provides input
//Postcondition: If the score is bigger than or equal to zero and less than or
//equal to 30 it is valid and true is returned. Otherwise it is false and false
//is returned.
bool ToeflScore::isValid(const int &score)
{
	if (score >= 0 && score <= 30)
		return true;
	else
		return false;
}

