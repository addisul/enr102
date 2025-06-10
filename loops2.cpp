/*
Program Name:  loops pt2
Author: Addisu Lococo
Date: 3/6/2025
Description: Use a for loop to calculate averages. Repeat calculating averages, until user is done.
First -- define a constant for how many numbers there are to average
Second -- ask user for how many numbers they have to average (modify first program to create the second)
*/


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	double data, sum;  //data is for storing numbers user inputs, sum is used to calculate running total
	double average; //average is calculated as sum/n and is output as a result to user
	int n; // user-provided input for how many numbers they have to average
	bool done; //used to decide if user is done which they will indicate with a 1 for done, 0 for not done

	cout << setw(15) << setfill('~') << " " << "INTRODUCTION " << setw(15) << " " << endl;
	cout << "This program will calculate the average of 5 folating point numbers that you will input." << endl;
	cout << "Each time, you will be asked how many numbers you have to average." << endl;
	cout << "You will be able to repeat this calculation with different numbers as many times as you would like." << endl;
	cout << setw(43) << " " << endl;

	string fileNameIn, fileNameOut;
	ifstream inNum; //input file stream variable for inputting from an input file
	ofstream outNum; //output file stream variable for outputting to an output file

	//Ask for input file name and link to input file stream variable inNum
	cout << "Enter the name of the input text file. Your text file name cannot" <<
		endl << "have any spaces and must start with a letter." <<
		endl << "Enter input file name: ";
	cin >> fileNameIn;
	fileNameIn.append(".txt");
	inNum.open(fileNameIn);	/*input file must exist in same file folder as
							the program .cpp file*/

							//Ask for output file name and link to output file stream variable outNum
	cout << "Enter the name of the output text file. Your text file name cannot" <<
		endl << "have any spaces and must start with a letter." <<
		endl << "Enter output file name: ";
	cin >> fileNameOut;
	fileNameOut.append(".txt");
	outNum.open(fileNameOut); /*output file will be created by VS in same file folder
							as the program .cpp file*/
	done = false;
	while (!done)
	{

		cout << endl << "Please enter how many numbers you have to average: ";
		cin >> n;
		cout << endl;
		sum = 0; //initialize running total to zero
		for (int i = 0; i < n; i++)  //loop peformed n times
		{
			 inNum >> data;
			sum = sum + data; //add in current data to the running total
		}
		average = sum / n; //calculates averages form sum

		//outputs results in a user-friendly format
		cout << endl << setw(15) << setfill('~') << " " << "RESULTS " << setw(15) << " " << endl;
		cout << "Average = " << average << endl;
		cout << setw(38) << " " << endl;

		cout << endl << "Are you done? Please enter 1 for yes and 0 for no: ";
		cin >> done;
	}

	cout << endl << setw(15) << setfill('~') << " " << "Thank you for using my progam. " << setw(15) << " " << endl;


	return 0;
}