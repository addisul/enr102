/*
Program Name: loops 
Author: Addisu Lococo
Date: 3/6/2025
Description: Use a for loop to calculate averages. Repeat calculating averages, until user is done. 
First -- define a constant for how many numbers there are to average
Second -- ask user for how many numbers they have to average (modify first program to create the second)
*/


#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5; //N will be how many numbers are to be averaged

int main()
{
	double data, sum;  //data is for storing numbers user inputs, sum is used to calculate running total
	double average; //average is calculated as sum/N and is output as a result to user
	bool done; //used to decide if user is done which they will indicate with a 1 for done, 0 for not done

	cout << setw(15) << setfill('~') << " " << "INTRODUCTION " << setw(15) << " " << endl;
	cout <<  "This program will calculate the average of 5 folating point numbers that you will input." << endl;
	cout <<  "You will be able to repeat this calculation with different numbers as many times as you would like." << endl;
	cout << setw(43) << " " << endl;

	done = false;
	while (!done) 
	{
		sum = 0; //initialize running total to zero
		for (int i = 0; i < N; i++)  //loop peformed n times
		{
			cout << "Enter a number: ";
			cin >> data;
			sum = sum + data; //add in current data to the running total
		}
		average = sum / N; //calculates averages form sum

		//outputs results in a user-friendly format
		cout << setw(15) << setfill('~') << " " << "RESULTS " << setw(15) << " " << endl;
		cout << "Average = " << average << endl;
		cout << setw(38) << " " << endl;

		cout << endl << "Are you done? Please enter 1 for yes and 0 for no: ";
		cin >> done;
	}
	cout << endl << "Thank you for using my program." << endl;

	
	


	return 0;
}