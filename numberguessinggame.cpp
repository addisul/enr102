/*
Program Name: Number Guessing Game
Author: Addisu Lococo
Date: 4/22/2025
Description: This program declares an integer array (testArray[][COLS]) with 20 rows and 10 columns and calls a function to fill it with random integers from 0 to 99 inclusive. 
The program asks the user to guess a number (playerChoice) and then calls another function to determine if the number is present in the array (searchArray(int testArray[][COLS]) and if it is, 
how many times it appears and assigns the boolean value (numberPresent) to either true or false. 
If the number is not in the array, the program prompts the user to play again. 
As long as the number guessed is present, the program lets the user know how many times the number appears (count) and then allows the user up to three guesses (RowGuess) as to which row the number can be found in. 
If the user guesses a row correctly (either on the 1st, 2nd, or 3rd try), the program tells them they “won” (found = true). If they did not guess correctly after 3 tries (found = false), the program tells them they “lost”. Either way, the program outputs the array in a well formatted fashion showing 20 rows and 10 columns.
The user is allowed to play as many times as they want, and are greeted farewell when chosen to stop.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int ROWS = 20;    //constant for rows
const int COLS = 10;    //constant for columns
const int CHANCES = 3;     //constant for the amount of attempts before game ends

void fillArray(int testArray[][COLS]);     //function to fill the array randomly with numbers from 0 to 99
void searchArray(int testArray[][COLS], int userchoice, int& numOfOccurences);     //function used to search for the integer, and then the row of a inputted integer in the array 
void printArray(int testArray[][COLS]);  //function used for other programmers to understand what the array looks like
void displayArray(int testArray[][COLS]);        //used to display the array at the end of the game


int main()
{
	int playerChoice; //variable for storing the input from the user
	bool numberPresent;
	int count; //counts the number of times the playerChoice is seen in the array
	int RowGuess;  //variable for the row the user guesses 
	int Attempts = 0; //variables to keep track of the user's attempts to guess the correct row
	int numberArray[ROWS][COLS];  //actual parameter

	cout << setw(50) << setfill('~') << " " << endl;
	cout << setw(30) << setfill(' ') << "INTRODUCTION" << endl;       //introduces the program to the user
	cout << setw(50) << setfill('~') << " " << endl << endl;
	cout << setw(5) << setfill(' ') << " " << "Welcome to my Number Guessing Game!" << endl << endl;
	cout << setw(70) << setfill('~') << " " << endl;
	cout << "From a randomly generated table with numbers inclusive from 0 to 99," << endl << endl;
	cout << "you will first to provide an integer number inclusive from 0 to 99. " << endl << endl;
	cout << "Then you will be provided with the amount of times it appears in the" << endl << endl;
	cout << "table. If the integer is not in the table you have to start over." << endl << endl;
	cout << "You will have 3 attempts to guess a row in which it occurs." << endl << endl;
	cout << "If you guess correctly in 3 attempts or less you win," << endl << endl;
	cout << "otherwise better luck next time." << endl << endl;


	//printArray(numberArray);   This is strictly for testing use and is for other programmers
	srand(time(0)); //set the seed to 0




	bool done;
	done = false;  //creates a loop to allow the user to replay
	while (!done)
	{
		fillArray(numberArray); //fills the array

		cout << setw(59) << setfill('~') << " ";
		cout << endl << "Please enter an integer number inclusive between 0 and 99: ";
		cin >> playerChoice;
		cout << setw(59) << setfill('~') << " " << endl;

		searchArray(numberArray, playerChoice, count);   //searches to see how many times the player chosen integer is seen in the table

		if (count > 0)
		{
			numberPresent = true; //sets the boolean value for numberPresent to true
			if (count > 1)
			{
				cout << endl << "The Number " << playerChoice << " Appears " << count << " times." << endl << endl;
			}
			else if (count == 1)
			{
				cout << endl << "The Number " << playerChoice << " Appears " << count << " time." << endl << endl;
			}

			bool found = false;
			while (!found && Attempts < 3)  //while loop to keep track of the amount of attempts the user takes to guess the row their chosen integer is in
			{
				cout << "What row do you think this number appears in?" << endl;
				cin >> RowGuess;

				if (RowGuess < 1 || RowGuess > ROWS)        //establishes the bounds for guessing the row
				{
					cout << "Is not within bounds. Please enter a valid row: ";
					cin >> RowGuess;
				}

				for (int j = 0; j < COLS; j++)
				{

					if (playerChoice == numberArray[RowGuess - 1][j])    //checks the values starting at each row
					{
						found = true;  //if a match is found, end loop user has won
					}

				}

				if (!found && Attempts < 3)  //if match is not made, increment attempts and prompt user to guess again
				{
					cout << endl << "Please try again " << playerChoice << " was not found in that row" << endl << endl;
					Attempts++;
				}







			}

			if (!found && Attempts == 3)     //if the user has not made a match and has attempted 3 times end loop, the user loses
			{
				cout << setfill(' ') << setw(5) << "Sorry you have used all of your attempts" << endl;
				cout << endl << setfill(' ') << setw(25) << "YOU LOSE" << endl;
			}
			else if (found && Attempts <= 3) //if the user has made a match and the attempts are less than or equal to 3, they win
			{
				cout << endl << "The Number " << playerChoice << " is seen in row " << RowGuess << endl;
				cout << setfill(' ') << setw(15) << "Congrats! YOU WIN!" << endl;
			}
		}
		else  //if the count is less than 1 than they must play again because that integer is not in the table
		{
			numberPresent = false;  //sets the boolean value for numberPresent to false
			cout << endl << "Sorry that number is not in the table" << endl;
			cout << "You can play again if you like" << endl;

		}



		displayArray(numberArray);  //display the table 

		cout << endl;
		cout << "Would you like to play again? Type 1 for no and 0 for yes: ";   //prompt to ask if the user wants to play again 
		cin >> done;



	}

	cout << endl;
	cout << setw(50) << setfill('~') << " " << endl << endl;
	cout << "Thank you for playing my Number Guessing Game" << endl;      //farewell greeting if the user chooses to stop playing
	cout << endl;
	cout << setw(50) << setfill('~') << " " << endl;



}

/*
Author: Addisu Lococo
Date: 4/20/2025
Function Name: searchArray
Description: Searches to see if the input value (formal parameter userinput) is in the table (formal parameter testArray[][COLS]. Then it tells the user the number of occurences of their input integer (formal parameter numOfOccurences).
*/
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
Description: Fills the table (formal parameter testArray[][COLS]) with random integers between 0 and 99 inclusive.
*/
void fillArray(int testArray[][COLS])
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
Description: Prints the array (formal parameter testArray[][COLS]) to the monitor, this is strictly for testing and will be removed when deployed.
*/
void printArray(int testArray[][COLS])
{
	cout << endl;
	cout << "This is the array showing you values so you understand \n how the array is filled and what it looks like" << endl;

	cout << setfill(' ') << setw(7) << "C1" << setw(4) << "C2" << setw(4) << "C3" << setw(4) << "C4" << setw(4) << "C5" << setw(4) << "C6" << setw(4) << "C7" << setw(4) << "C8" << setw(4) << "C9" << setw(4) << "C10" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << "R" << setw(3) << left << (i + 1) << right;
		for (int j = 0; j < COLS; j++)
		{
			cout << setfill(' ') << setw(4) << testArray[i][j]; //print's every value in the table within the bounds
		}
		cout << endl;
	}
}

/*
Author: Addisu Lococo
Date: 4/20/2025/*
Function Name: displayArray
Description: Displays the array (formal parameter testArray[][COLS]) to the user at the end of the game.
*/
void displayArray(int testArray[][COLS])
{
	cout << endl;
	cout << setw(25) << setfill('~') << " Array " << setw(20) << setfill('~') << " " << setfill(' ') << endl;

	cout << setw(7) << "C1" << setw(4) << "C2" << setw(4) << "C3" << setw(4) << "C4" << setw(4) << "C5" << setw(4) << "C6" << setw(4) << "C7" << setw(4) << "C8" << setw(4) << "C9" << setw(4) << "C10" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << "R" << setw(3) << left << (i + 1) << right;
		for (int j = 0; j < COLS; j++)
		{
			cout << setfill(' ') << setw(4) << testArray[i][j]; //displays every value in the table within the bounds
		}
		cout << endl;
	}
}

















