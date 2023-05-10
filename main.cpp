
//								ENSC 251 Term Project
// Fall 2020
// November 2 1:10PM
// Jacob Tong
// Daniyar Umuraliyev
// Alireza Jadidi
// Amir Eghbal

// This code sorts university applicant data. We provide a student class, as well as child classes - domestic and international student classes.
// We recieve the data from .txt files and sort based on user-chosen categories.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "Student.h"
#include "DomesticStudent.h"
#include "Istudent.h"
#include "ILinkedList.h"
#include "DLinkedList.h"

using namespace std;

///////////////////////////////////////////////////////////////Function Prototypes\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


void BubSortEverything(Istudent array[], int size);
void BubSortEverything(DomesticStudent array[], int size);

void BubSortScores(Istudent array[], int size, string category);
void BubSortScores(DomesticStudent array[], int size, string category);

void BubSortNames(Istudent array[], int size, string category);
void BubSortNames(DomesticStudent array[], int size, string category);


const int compareCGPA(const float thisCGPA, const float CGPA);
const int compareResearchScore(const int thisScore, const int score);
const int compareFirstName(const string thisFirstName, const string firstName);
const int compareLastName(const string thisLastName, const string lastName);
const int compareCountry(const string thisCountry, const string country);
const int compareProvince(const string thisProvince, const string province);


void PrintHeaderInternational();
void PrintHeaderDomestic();

////////////////////////////////////////////////////////////////Main Function Begin\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



int main()
{

	DLinkedList DList; //domestic student list
	ILinkedList IList; // international student list
	LinkedList List; // contains the merge of both DList and IList
	int dstu_count = 0;
	int istu_count = 0;
	int total_stu_count = dstu_count + istu_count;

	//////////////////////////////////////////////////////Read Domestic Student.txt//////////////////////////////////////////
	// I changed stu_count from 1 into zero for array purposes. If there's an error, check that first.

	//Read the domestic-stu.txt file and exit if failed
	string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open())
	{
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(domesticFile, line);
	cout << endl
		<< "File format: " << line << endl;

	while (getline(domesticFile, line))
	{
		total_stu_count = istu_count + dstu_count;
		DomesticStudent TempStu;

		istringstream ss(line);

		string firstName, lastName, province, s_CGPA, s_researchScore;
		float CGPA;
		int researchScore;

		//get firstName separated by comma
		getline(ss, firstName, ',');
		TempStu.setFirstName(firstName);

		//get lastName separated by comma
		getline(ss, lastName, ',');
		TempStu.setLastName(lastName);

		//Set student ID
		TempStu.generateID(total_stu_count);

		//get province separated by comma
		getline(ss, province, ',');
		TempStu.setProvince(province);

		//get cpga separated by comma, and convert string to float
		getline(ss, s_CGPA, ',');
		CGPA = atof(s_CGPA.c_str());
		TempStu.setCGPA(CGPA);

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		TempStu.setScore(researchScore);

		//print the student info to the screen
		cout << "Domestic student " << dstu_count << ": " << firstName << " "
			<< lastName << " from " << province << " has CGPA of "
			<< CGPA << ", and research score of " << researchScore << endl;

		//push TempStu object into our linked list DList
		DList.push(TempStu);
		cout << "push completed" << endl;
		dstu_count++;

	}

	dstu_count--; //on the last instance dstu_count increments, then while loop ends. So, we decrement. Now, dstu_count
	// will represent the last index in domestic_students[] that had a value read from .txt.

	//close your file
	domesticFile.close();
	cout << "Domestic file closed";


	////////////////////////////////////////////////////Read International-stu.txt\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	//Read the international-stu.txt file and exit if failed
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open())
	{
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}

	//Read the first line of international-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(internationalFile, line);
	cout << endl << "File format: " << line << endl;

	while (getline(internationalFile, line))
	{

		total_stu_count = istu_count + dstu_count;

		Istudent TempStu;

		istringstream ss(line);

		string firstName, lastName, country, s_CGPA, s_researchScore, s_reading, s_speaking, s_listening, s_writing;
		float CGPA;
		int researchScore, reading, speaking, listening, writing;

		//Basically everything read from file is a string, thus we need to convert those values.
		//get firstName separated by comma
		getline(ss, firstName, ',');
		TempStu.setFirstName(firstName);

		//get lastName separated by comma
		getline(ss, lastName, ',');
		TempStu.setLastName(lastName);

		//Set student ID
		TempStu.generateID(total_stu_count);

		//get country separated by comma
		getline(ss, country, ',');
		TempStu.setCountry(country);

		//get cpga separated by comma and convert string to float
		getline(ss, s_CGPA, ',');
		CGPA = atof(s_CGPA.c_str());
		TempStu.setCGPA(CGPA);

		//get researchScore separated by comma and convert to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		TempStu.setScore(researchScore);

		//get reading and convert to int
		getline(ss, s_reading, ',');
		reading = atoi(s_reading.c_str());
		TempStu.setReadingScore(reading);

		//get speaking and convert  int
		getline(ss, s_speaking, ',');
		speaking = atoi(s_speaking.c_str());
		TempStu.setSpeakingScore(speaking);

		//get listening and convert to int
		getline(ss, s_listening, ',');
		listening = atoi(s_listening.c_str());
		TempStu.setListeningScore(listening);

		//get writing and convert to int
		getline(ss, s_writing, ',');
		writing = atoi(s_writing.c_str());
		TempStu.setWritingScore(writing);

		//print the student info to the screen
		cout << "International student " << istu_count << ": " << firstName << " "
			<< lastName << " from " << country << " has CGPA of "
			<< CGPA << " and research score of " << researchScore << endl;

		//Push TempStu into our Istudent linked list IList
		IList.push(TempStu);


		istu_count++;
	}

	istu_count--; //on the last instance istu_count increments, then while loop ends. So, we decrement. Now, istu_count
	// will represent the last index in I_students[] that has a value read from .txt.

	//close your file
	internationalFile.close();

	cout << endl << "Testing Print of international Linked List: \n";
	PrintHeaderInternational();
	IList.print();
	cout << IList;


	cout << "\n -------------------------------- \n";
		DList.SearchDomesticResearchScore(98);
	/*	DList.SearchDomesticCGPA(4.225);
		DList.SearchDomesticID(1);
		DList.SearchDomesticID(20211000);
		DList.SearchDomesticID(20209000);
		DList.SearchDomesticID(20200062);

		IList.SearchInternationalResearchScore(62);
		IList.SearchInternationalCGPA(4);
		IList.SearchInternationalID(1);
		IList.SearchInternationalID(20211000);
		IList.SearchInternationalID(20209000);
		IList.SearchInternationalID(20200062);

		string firstName;
		string lastName;
		cout << "Enter name to search (firstname lastname):";
		cin >> firstName >> lastName;
		DList.SearchDomesticName(firstName, lastName);

		IList.SearchInternationalName(firstName, lastName);

		string first;
		string last;
		float gpa;
		int research;
		int id;
		DomesticStudent Amir;
		cout << "Enter new student first name:";
		cin >> first;
		Amir.setFirstName(first);
		cout << "Enter new student last name:";
		cin >> last;
		Amir.setLastName(last);
		cout << "Enter new student research score:";
		cin >> research;
		Amir.setScore(research);
		cout << "Enter new student id:";
		cin >> id;
		Amir.setID(id);
		cout << "Enter new student CGPA:";
		cin >> gpa;
		Amir.setCGPA(gpa);

		DList.push(Amir);
		DList.delete_Dnode("Emily", "Rivera");
	
	cout << endl << "Testing Print of domestic Linked List: \n";
	PrintHeaderDomestic();
	DList.print();

	cout << "Main closing." << endl;
	return 0;

}	*/
	/////////////////////////////////////////////User Interface Sorting of Students\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	char sort = 'y';
	do
	{


		// CHOOSE AN OPTION
		// so for 1 and 2, we alter the IList or DList.
		// for 3 and 4, you can search IList, DList, or the two combined.
		// the combined list is temporarily created. After the while loop, it is destroyed again.
		// aka permanent changes are made to IList and DList while the combined exists only in the while loop scope.
		char option;
		do
		{
			cout << "To choose an option, enter the number then press 'enter'" << endl
				 << "1) add a student" << endl
				 << "2) delete a student" << endl
				 << "3) search for ID, name, CGPA, or research score" << endl
				 << "4) find all students above a given threshold value" << endl;
			cin >> option;

			//Error Checking
			if (option != '1' && option != '2' && option != '3' && option != '4' )
			{
				cout << "ERROR. Please enter a number between 1 and 4 (including 1 and 4)." << endl;
			}
		}while (option != '1' && option != '2' && option != '3' && option != '4' );

		switch(option)
		{
		// ADD A STUDENT
		case '1':
		{
			char type;
			do{
				cout << "Hi there. Would you like to enter data for an international student or domestic student? Enter 'i' for an international student or 'd' for a domestic student." << endl;
			
				cin >> type;
			if(type != 'i' || type != 'd')
			cout << "Please enter a valid option: 'i' for international student, 'd' for domestic student." << endl;		
			}while(type != 'i' && type != 'd');
			
			if(type == 'i')
			{	
				//TempStu will be our temporary student.
				Istudent TempStu;
	
				cout << "Please enter their first name and last name separated by a space." << endl;
				string first, last;
				cin >> first;
				cin >> last;
				
				cout << "Please enter their CGPA:" << endl;
				int cgpa;
				cin >> cgpa;
				
				cout << "Please enter their Research Score:" << endl;
				int rscore;	
				
				cout << "Please enter their country of origin:" << endl;
				string birthplace;
				cin >> birthplace;
					
				cout << "Please enter their reading:" << endl;
				int read;
				cin >> read;
			
				cout << "Please enter their speaking score:" << endl;
				int speak;
				cin >> speak;

				cout << "Please enter their listening score:" << endl;
				int listen;
				cin >> listen;
		
				cout << "Please enter their writing score:" << endl;
				int write;
				cin >> write;
		
			
 			istu_count++;
			total_stu_count = dstu_count + istu_count;
			TempStu.generateID(total_stu_count);
			TempStu.setFirstName(first);
			TempStu.setLastName(last);
			TempStu.setCGPA(cgpa);
			TempStu.setScore(rscore);
			TempStu.setCountry(birthplace);
			TempStu.setReadingScore(read);
			TempStu.setSpeakingScore(speak);
			TempStu.setListeningScore(listen);
			TempStu.setWritingScore(write);
			//put TempStu into the IList
			IList.push(TempStu);
	
			} 
			else // aka for type 'd' = domestic student
			{
				DomesticStudent TempStu;
				cout << "Please enter their first name and last name separated by a space." << endl;
				string first, last;
				cin >> first;
				cin >> last;
				
				cout << "Please enter their CGPA:" << endl;
				int cgpa;
				cin >> cgpa;
				
				cout << "Please enter their Research Score:" << endl;
				int rscore;	
				
				cout << "Please enter their province of residence:" << endl;
				string state;
				cin >> state;
			

			dstu_count++;
			total_stu_count = dstu_count + istu_count;
			TempStu.generateID(total_stu_count);
			TempStu.setFirstName(first);
			TempStu.setLastName(last);
			TempStu.setCGPA(cgpa);
			TempStu.setScore(rscore);
			TempStu.setProvince(state);
			// put TempStu into DList
			DList.push(TempStu);

			}
		} break; // end of case 1


		// DELETE A STUDENT
		case '2':
		{	cout << "Hi there. To delete a student, you will enter their first name and last name separated by a space.You can choose which list of students you would like to delete this student from. If you choose 'both lists', all students, both international and domestic having the input name, will be deleted. If you choose a single list, like 'Domestic Student', then only domestic students sharing the input name will be deleted. ALL STUDENTS WITH THE INPUT NAME WILL BE DELETED. To select a choice, enter the number and press ENTER." << endl;
			cout << "1) Delete an international student \n2) Delete a domestic student \n3) Delete any student \n";
			
			char choice;
			do{
			if(choice == '1')
			IList.print();
	
			if(choice == '2')
			DList.print();
			
			if(choice == 3)
			{	
				List.print();
			}	
			}while(choice != '1' && choice != '2' && choice != 3);
			
			cout << "Now that you see who you can delete, please enter the name of the student you would like to delete. Enter their first name, then last name, separated by a space." << endl;
			string first, last;
			cin >> first;
			cin >> last;
			
			if(choice == '1')
			{
				IList.delete_node(first, last);
				IList.print();
			} 
			else if(choice == '2')
			{
				DList.delete_node(first, last);
				DList.print();
			}
			else // aka if choice == '3'
			{
				IList.delete_node(first, last);
				DList.delete_node(first, last);
				IList.print();
				DList.print();

			}

		} break; // end of case 2

		// SEARCH BY CATEGORY 
		case 3:
		{	char choice, stuType;
			string firstName, lastName;
			int  score, id;
			float cgpa;
			
			//ASK FOR CHOICE
			do{
			cout << "You have chosen to search for a student. Please choose what category you would like to search for?" << endl;
			cout << "To select, type the number and press ENTER.\n1) Name \n2) ID \n3) CGPA \n4) Research Score \n";
			cin >> choice;
			if(choice != '1' && choice != '2' && choice != '3' && choice != '4')
			cout << "Please enter a valid option between 1 and 4." << endl;
			}while(choice != '1' && choice != '2' && choice != '3' && choice != '4');
			
			//ASK FOR SEARCH VALUE. 
			switch(choice)
			case '1':
			cout << "Please enter the name you would like to search. Please enter the first name and last name separated by a space." << endl;
			cin >> firstName >> lastName;
			break;
	
			case '2':
			cout << "Please enter the ID number you would like to search for." << endl;
			cin >> id;
			break;

			case '3':
			cout << "Please enter the CGPA you wuold like to search for." << endl;
			cin >> cgpa;
			break;
	
			case '4':
			cout << "Please enter the research score you would like to search for." << endl;
			cin >> score;
			break;
		
			//ASK WHICH LIST TO SEARCH	
			do{
			cout << "Please select which type of student you would like to search through? To select, type the number then press ENTER." << endl;
			cout << "1) International Students \n2) Domestic Students \n3)All students \n";
			cin >> stuType;
			if(stuType != '1' && stuType != '2' && stuType != '3')
			cout << "Please enter a valid option between 1 and 3" << endl;
			}while(stuType != '1' && stuType != '2' && stuType != '3');


			// SEARCH THE LIST
			if(stuType == '1') //search the international list
			{
				if(choice == '1')
				IList.SearchName(firstName, lastName);	
				else if(choice == '2')
				IList.SearchID(id);
				else if(choice == '3')
				IList.SearchCGPA(cgpa);
				else
				IList.SearchResearchScore(score);	

			}
			else if(stuType == '2') //search the domestic list
			{
				if(choice == '1')
				DList.SearchName(firstName, lastName);	
				else if(choice == '2')
				DList.SearchID(id);
				else if(choice == '3')
				DList.SearchCGPA(cgpa);
				else
				DList.SearchResearchScore(score);

			}
			else //search the merged list
			{
				if(choice == '1')
				List.SearchName(firstName, lastName);	
				else if(choice == '2')
				List.SearchID(id);
				else if(choice == '3')
				List.SearchCGPA(cgpa);
				else
				List.SearchResearchScore(score);

			}

		} break;// end of case 3


		// FILTER BY THRESHOLD
		case 4:
		{
			cout << "Hi there. You chose to filter by a threshold value. Please choose if you would like to filter by CGPA, research score, or both! The value you enter provides you with the students scoring above or equal to the specified value." << endl;
			char choice, stuType;
			float cgpa;
			int score;
		
			// WHAT TO FILTER BY
			do{
				cout << "Choose by entering a number and pressing ENTER. Filter by: \n1) CGPA \n2) Research Score \n3) Both" << endl;
				cin >> choice;
				if(choice != '1' && choice != '2' && choice != '3')
				cout << "Please enter a valid choice between '1' and '3'" << endl;

			}while(choice != '1' && choice != '2' && choice != '3');
			

			// ENTER THRESHOLD VALUE
			if(choice == '1')
			{
				cout << "Please enter your threshold CGPA. All students scoring less than this are not printed." << endl;
				cin >> cgpa;
			}
			else if(choice == '2')
			{
				cout << "Please enter your threshold research score. All students scoring less than this are not printed." << endl;
				cin >> score;
			} 
			else // aka threshold cgpa and score
			{
				cout << "Please enter your threshold CGPA and research score. All students scoring less in one of these values are not printed." << endl;
				cout << "Enter the threshold CGPA: \n";
				cin >> cgpa;
				cout << "Enter the threshold research score: \n";
				cin >> score;	
	
			}	
		
			// WHAT LIST TO SEARCH?	
			do
			{
				cout << "Choose what list you would like to search. Enter the number and press ENTER. \n1) International Students \n2) Domestic Students \n3) Both" << endl;
				cin >> stuType;
				if(stuType != '1' && stuType != '2' && stuType != '3')
				cout << "Please enter a valid choice between '1' and '3'" << endl; 
			}while(stuType != '1' && stuType != '2' && stuType != '3');

		
			// SEARCH BY THRESHOLD VALUE
			if(stuType == '1')
			{
				if(choice == '1')
				IList.SearchThreshold(cgpa);
				else if(choice == '2')
				IList.SearchThreshold(score);
				else if(choice == '3')
				IList.SearchThreshold(cgpa, score);
				else
				cout << "Threshold search error." << endl;		
			} 
			else if(stuType == '2')
			{
				if(choice == '1')
				DList.SearchThreshold(cgpa);
				else if(choice == '2')
				DList.SearchThreshold(score);
				else if(choice == '3')
				DList.SearchThreshold(cgpa, score);
				else 
				cout << "Threshold search error." << endl;
			}
			else // aka stuType == '3'
			{
				if(choice == '1')
				List.SearchThreshold(cgpa);
				else if(choice == '2')
				List.SearchThreshold(score);
				else if(choice == '3')
				List.SearchThreshold(cgpa, score);
				else
				cout << "Threshold search error." << endl;		

			}

		} break; // end of case 4

/*
		do
		{
			cout << "Would you like to sort again? Press 'y' to retry or 'n' to exit." << endl;
			cin >> sort;
			if (sort != 'y' && sort != 'Y' && sort != 'n' && sort != 'N')
			{
				cout << "ERROR. Incorrect entry." << endl;
			}
			else if (sort == 'n' || sort == 'N')
				return 0;

		} while (sort != 'y' && sort != 'Y' && sort != 'n' && sort != 'N');

		option = 0;

	} while (sort == 'y' || sort == 'Y');
*/

cout << endl << "End of main function. Bye bye." << endl;

return 0;

}




/////////////////////////////////////////////////////////////////////END OF MAIN FUNCTION\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




///////////////////////////////////////////////////////////////////////BUBBLE SORT FUNCTIONS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// 6 Bubble Sort Functions.
// #1 and #2 sort by research score, then CGPA, then country/province names. It sorts everything.
// #3 and #4 sort numbers. You sort by "research score" or "CGPA".
// #5 and #6 sort strings. You can sort by "first name" or "last name".

//	#1
//BUBBLE SORT EVERYTHING INTERNATIONAL
// sort by research, then CGPA, then country. We have to drop an International Student if they have too low a TOEFL grade.
void BubSortEverything(Istudent array[], int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			float holdCGPA1 = array[i].getCGPA();
			float holdCGPA2 = array[i + 1].getCGPA();
			int holdRScore1 = array[i].getScore();
			int holdRScore2 = array[i + 1].getScore();
			string holdCountry1 = array[i].getCountry();
			string holdCountry2 = array[i + 1].getCountry();

			if (compareResearchScore(holdRScore1, holdRScore2) == -1)
			{
				Istudent temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			else if (compareResearchScore(holdRScore1, holdRScore2) == 0 && compareCGPA(holdCGPA1, holdCGPA2) == -1)
			{
				Istudent temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			else if (compareResearchScore(holdRScore1, holdRScore2) == 0 && compareCGPA(holdCGPA1, holdCGPA2) == 0 && compareCountry(holdCountry1, holdCountry2) == 1)
			{
				Istudent temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
		}
	}
}

//	#2
//BUBBLE SORT EVERYTHING DOMESTIC
// sorts by research score, then CGPA, then province name
void BubSortEverything(DomesticStudent array[], int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			float holdCGPA1 = array[i].getCGPA();
			float holdCGPA2 = array[i + 1].getCGPA();
			int holdRScore1 = array[i].getScore();
			int holdRScore2 = array[i + 1].getScore();
			string holdProvince1 = array[i].getProvince();
			string holdProvince2 = array[i + 1].getProvince();
			if (compareResearchScore(holdRScore1, holdRScore2) == -1)
			{
				DomesticStudent temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			else if (compareResearchScore(holdRScore1, holdRScore2) == 0 && compareCGPA(holdCGPA1, holdCGPA2) == -1)
			{
				DomesticStudent temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			else if (compareResearchScore(holdRScore1, holdRScore2) == 0 && compareCGPA(holdCGPA1, holdCGPA2) == 0 && compareProvince(holdProvince1, holdProvince2) == 1)
			{
				DomesticStudent temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
		}
	}
}

//	#3
//INTERNATIONAL CGPA OR RESEARCH SCORE BUBBLE SORT
//will sort CGPA or Research Score on an Istudent array. Category is what the user wants to sort by: CGPA or Research Score
// Higher scores are at the front/beginning of the array, lower scores are near the end/back.
void BubSortScores(Istudent array[], int size, string category)
{
	if (category == "CGPA" || category == "cgpa")
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				float holdCGPA1 = array[i].getCGPA();
				float holdCGPA2 = array[i + 1].getCGPA();
				if (compareCGPA(holdCGPA1, holdCGPA2) == -1)
				{
					Istudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}
	else if (category == "research") //sort by research score
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				int holdRScore1 = array[i].getScore();
				int holdRScore2 = array[i + 1].getScore();
				if (compareResearchScore(holdRScore1, holdRScore2) == -1)
				{
					Istudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}

	else
	{
		cout << "Something went wrong with your sort. Please check "
			"research"
			" and "
			"CGPA"
			" are entered as categories for your function to sort by 'research' or 'CGPA'. "
			<< endl;
	}
}

//	#4
//DOMESTIC CGPA OR RESEARCH SCORE BUBBLE SORT
//will sort CGPA or Research Score on an Domestic student array. Category is what the user wants to sort by: CGPA or Research Score
// Higher scores are at the front/beginning of the array, lower scores are near the end/back.
void BubSortScores(DomesticStudent array[], int size, string category)
{
	if (category == "CGPA" || category == "CGPA")
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				float holdCGPA1 = array[i].getCGPA();
				float holdCGPA2 = array[i + 1].getCGPA();
				if (compareCGPA(holdCGPA1, holdCGPA2) == -1)
				{
					DomesticStudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}
	else if (category == "research") //sort by research score
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				int holdRScore1 = array[i].getScore();
				int holdRScore2 = array[i + 1].getScore();
				if (compareResearchScore(holdRScore1, holdRScore2) == -1)
				{
					DomesticStudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}

	else
	{
		cout << "Something went wrong with your sort. Please check "
			"research"
			" and "
			"CGPA"
			" are entered as categories for your function to sort by 'research' or 'CGPA'. "
			<< endl;
	}
}

//	#5
//INTERNATIONAL NAME BUBBLE SORT
// will sort an international array based on name. Category is whether you want to sort based on first or last names.
// Adam is at the start of the array, Zachary is near the end.
void BubSortNames(Istudent array[], int size, string category)
{
	if (category == "first" || category == "First")
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				string name1 = array[i].getFirstName();
				string name2 = array[i + 1].getFirstName();

				// a 1 means array[i] name is larger than namehold==array[i+1] name.
				if (compareFirstName(name1, name2) == 1)
				{
					Istudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}
	else if (category == "last" || category == "Last")
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				string name1 = array[i].getLastName();
				string name2 = array[i + 1].getLastName();

				// a 1 means array[i] name is larger than namehold==array[i+1] name.
				if (compareLastName(name1, name2) == 1)
				{
					Istudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}
	else
	{
		cout << "Something went wrong with your sort. Please check "
			"first"
			" and "
			"last"
			" are entered as categories for your function to sort by first name or last name. "
			<< endl;
	}
}

//	#6
//DOMESTIC NAME BUBBLE SORT
// will sort an international array based on name. Category is whether you want to sort based on first or last names.
// Adam is at the start of the array, Zachary is near the end.
void BubSortNames(DomesticStudent array[], int size, string category)
{
	if (category == "first" || category == "First")
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				string name1 = array[i].getFirstName();
				string name2 = array[i + 1].getFirstName();

				// a 1 for compareFirstName() means array[i] name is bigger than array[i+1] name.
				if (compareFirstName(name1, name2) == 1)
				{
					DomesticStudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}
	else if (category == "last" || category == "Last")
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				string name1 = array[i].getLastName();
				string name2 = array[i + 1].getLastName();

				// a 1 for compareFirstName() means array[i] name is bigger than array[i+1] name.
				if (compareLastName(name1, name2) == 1)
				{
					DomesticStudent temp = array[i + 1];
					array[i + 1] = array[i];
					array[i] = temp;
				}
			}
		}
	}
	else
	{
		cout << "Something went wrong with your sort. Please check "
			"first"
			" and "
			"last"
			" are entered as categories for your function to sort by first name or last name. "
			<< endl;
	}
}
///////////////////////////////////////////////////PRINT FUNCTIONS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


// Print out header columns when printing out international student data
void PrintHeaderInternational()
{
	cout << setw(20) << left << "First Name";
	cout << setw(20) << left << "Last Name";
	cout << setw(14) << left << "Student ID";
	cout << setw(10) << "Country";
	cout << setw(10) << "CGPA";
	cout << setw(18) << left << "Research Score";
	cout << setw(15) << left << "TOEFL Total";
	cout << setw(12) << left << "Reading";
	cout << setw(12) << left << "Listening";
	cout << setw(12) << left << "Speaking";
	cout << setw(12) << left << "Writing";
	cout << endl;
}

// Print out header columns when printing out domestic student data
void PrintHeaderDomestic()
{
	cout << setw(20) << left << "First Name";
	cout << setw(20) << left << "Last Name";
	cout << setw(14) << left << "Student ID";
	cout << setw(12) << "Province";
	cout << setw(10) << "CGPA";
	cout << setw(18) << left << "Research Score";
	cout << endl;
}
