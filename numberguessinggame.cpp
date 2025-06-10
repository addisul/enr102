/*
Program Name: Number guessing game
Author: Addisu Lococo
Date: 4/10/2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int ROWS = 20;    //constant for rows
const int COLS = 10;    //constant for columns
const int CHANCES = 3;            //constant for the amount of attempts before game ends
void fillArray(int testArray[ROWS][COLS]);     //function to fill the array randomly with numbers from 0 to 99
void searchArray(int testArray[][COLS], int userchoice, int& numOfOccurences);     //function used to search for the integer, and then the row of a inputted integer in the array 
void printArray(int testArray[ROWS][COLS]);  //function used for other programmers to understand what the array looks like
void displayArray(int testArray[ROWS][COLS]);        //used to display the array at the end of the game


int main() 
{
	int playerChoice; //variable for storing the input from the user
	int count;
	int Attempts;  //integer for storing the amount of attempts the users has/uses
	int numberArray[ROWS][COLS];  //formal definition
	
	cout << setw(50) << setfill('~') << " " << endl;
	cout << setw(30) << setfill(' ') << "INTRODUCTION" << endl;
	cout << setw(50) << setfill('~') << " " << endl << endl;
	cout << setw(5) << setfill(' ') << " " << "Welcome to my Number Guessing Game!" << endl << endl << endl;
	cout << setw(70) << setfill('~') << " " << endl;
	cout << "From a randomly generated table with numbers inclusive from 0 to 99," << endl << endl;
	cout << "you will first to provide an integer number inclusive from 0 to 99. " << endl << endl;
	cout << "Then you will be provided with the amount of times it appears in the table" << endl << endl;
	cout <<"in the table" << endl << endl;
	cout << "You will have 3 attempts to guess the row in which it occurs once." << endl << endl;
	cout << "If you guess correctly in 3 attempts or less you win," << endl << endl;
	cout << " otherwise better luck next time" << endl << endl;
	cout << setw(70) << setfill('~') << " " << endl;

	//printArray(numberArray);   This is strictly for testing use and is for other programmers
	srand(time(0)); //set the seed to 0

	fillArray(numberArray);
	
	
	cout << "Please enter an integer number inclusive between 0 and 99: ";
	cin >> playerChoice;
	searchArray(numberArray, playerChoice, count);
	cout << count;
			
	
	displayArray(numberArray);
	


	bool done;
	done = false;
	while (!done)
	{
		cout << endl;
		cout << "Would you like to play again? Type 1 for yes and 0 for no.";
		cin >> done;
	}
	cout << endl;
	cout << setw(50) << setfill('~') << " " << endl << endl;
	cout << "Thank you for playing my Number Guessing Game." << endl;
	cout << endl;
	cout << setw(50) << setfill('~') << " " << endl;





}


/*
Author: Addisu Lococo
Date: 4/20/2025
//Function Name: searchArray
//Description: searches to see if the input value is in the array, tells the user the number of occurences of their input integer
//*/
void searchArray(int testArray[][COLS], int userinput, int& numOfOccurences)
{
	numOfOccurences = 0;
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			if (userinput == testArray[i][j])
			{
				numOfOccurences++;
			}

		}
	}
}




/*
Author: Addisu Lococo
Date: 4/20/2025
Function Name: fillArray
Description: fills the array with random numbers
*/
	void fillArray(int testArray[ROWS][COLS])
	{
		for (int i = 0; i < ROWS; ++i)
		{ 
			for (int j = 0; j < COLS; ++j)
			{
				testArray[i][j] = static_cast<int> (rand()) % 100; // generate random numbers between 0 and 99

			}
		}
	}




/*
Author: Addisu Lococo
Date: 4/20/2025
Function Name: printArray
Description: prints the array to the monitor, this is strictly for testing and will be removed when deployed 
*/
	void printArray(int testArray[][COLS])
	{
		cout << "This is the array showing you values so you understand \n how the array is filled and what it looks like" << endl;

		cout << setw(7) << "C1" << setw(4) << "C2" << setw(4) << "C3" << setw(4) << "C4" << setw(4) << "C5" << setw(4) << "C6" << setw(4) << "C7" << setw(4) << "C8" << setw(4) << "C9" << setw(4) << "C10" << endl;
		for (int i = 0; i < ROWS; i++)
		{
			cout << "R" << setw(3) << left << (i + 1) << right;
			for (int j = 0; j < COLS; j++)
			{
				cout << setfill (' ') << setw (7) << testArray[i][j];
			}

		}
	}

/*
Author: Addisu Lococo
Date: 4/20/2025/*
Function Name: displayArray
Description: displays the array to the user at the end of the game
*/
			void displayArray(int testArray[][COLS])
		{
				cout << setw(30) << setfill('~') << " Array " << setw(20) << setfill('~') << " " << setfill(' ') << endl;

				cout << setw(7) << "C1" << setw(4) << "C2" << setw(4) << "C3" << setw(4) << "C4" << setw(4) << "C5" << setw(4) << "C6" << setw(4) << "C7" << setw(4) << "C8" << setw(4) << "C9" << setw(4) << "C10" << endl;
				for (int i = 0; i < ROWS; i++)
				{
					cout << "R" << setw(3) << left << (i + 1) << right;
					for (int j = 0; j < COLS; j++)
					{
						cout << setfill(' ') << setw(7) << testArray[i][j];
					}
					cout << endl;
				}
		}















			//if (playerChoice != testArray[])
			//{
			//	cout << setw(10) << " " << "Sorry that Number is not in the Array" << endl;
			//	cout << "Please enter an integer number inclusive between 0 and 99" << endl;
			//}
			//else {
			//	searchArray(testArray);

			//	int RowGuess;
			//	for (int i = 0; i < CHANCES; i++)
			//	{
			//		bool found = false;
			//		while (!found)
			//		{
			//			cout << "What row do you think this number appears in?" << endl;
			//			cin >> RowGuess;

			//			for (int i = 0; i < ROWS; ++i)
			//			{

			//				for (int j = 0; j < COLS; ++j)
			//				{

			//					if ()
			//					{
			//						found = true;
			//						cout << "Congrats! YOU WIN!" << endl;
			//					}

			//					else
			//					{
			//						cout << "Sorry You Are Incorrect." << endl;
			//						cout << "Try Again Next Time" << endl;
			//					}



			//				}
			//			}



			//		}
			//	}