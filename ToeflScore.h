//Header file for ToeflScore class
//Author: Amirali Eghbal

//Ifndef used to avoid using header file incorrectly

#ifndef TOEFLSCORE_H
#define TOEFLSCORE_H
using namespace std;


//ToeflScore class definition
class ToeflScore
{
public:
	ToeflScore(); //Default constructor
	//Constructor with the 4 member variable parameters
	ToeflScore(const int& reading, const int& listening, const int& speaking, const int& writing);
	//Accessors for the different scores and total score
	int getReadingScore() const;
	int getListeningScore() const;
	int getSpeakingScore() const;
	int getWritingScore() const;
	int getTotalScore();
	//Mutators for setting the scores and setAll to set all at the same time
	void setReadingScore(const int& reading);
	void setListeningScore(const int& listening);
	void setSpeakingScore(const int& speaking);
	void setWritingScore(const int& writing);
	void setAll(const int& reading, const int& listening, const int& speaking, const int& writing);
private:
	//The 4 score member variables
	int readingScore;
	int listeningScore;
	int speakingScore;
	int writingScore;
	int totalScore;
	//isValid function that takes 4 parameters to check validity of all member variables
	bool isValid(const int& reading, const int& listening, const int& speaking, const int& writing);
	//isValid function that takes one parameter to check the validity of an input
	bool isValid(const int& score);
	//calcTotalscore function to calculate total score
	void calcTotalScore();
};
#endif
