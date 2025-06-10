
/*
Program Name: Blinds Controller	
Author:Addisu Lococo
Date:2/27/2025
Program Description:Write a program that brings in 5 floating point numbers from data.txt file
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// Declare variables first and then start the programming statements
	/*
	variables a through e are used to store information from input file
	  and then used in calculations for blinds controller to the monitor and an output file
	  output file
	*/
	double a, b, c, d, e;
	double average; // used to calculate average of five input numbers, and used to calculate angle
	int angle; // value is determined based on average
	/*
	fileNameIn and fileNameOut are string names provided by the user
	for the names of the input file and output file, respectively.
	*/
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
	cout << " Remember to have a message to user about what program does and how to use it." << endl;

	//ignore first five numbers
	inNum.ignore(100, '\n');
	inNum.ignore(100, '\n');
	inNum.ignore(100, '\n');
	inNum.ignore(100, '\n');
	inNum.ignore(100, '\n');

	//Bring in five numbers from the input file
	inNum >> a >> b >> c >> d >> e;

	// Calculate average
	average = (a + b + c + d + e) / 5.0;
	
	//figure out what angle has to be based on value of average and problem statement
	if (0 <= average && average <= 1)
	{
		angle = 0;
	}
	else if (1 < average && average <= 2.5)
	{
		angle = 30;
	}
	else if (2.5 < average && average <= 4)
	{
		angle = 60;
	}
	else 
	{
		angle = 90;
	}

	// then output the result to monitor and output file as follows
	cout << fixed << showpoint << setprecision(2);

	cout << "average = " << average << " V" << endl;
	
	cout << "angle = " << angle << " degrees" << endl;
	//results to output file

	outNum << fixed << showpoint << setprecision(2);
	outNum << "average = " << average << " V" << endl;
	outNum << "angle = " << angle << " degrees" << endl;

	inNum.close();
	outNum.close();

	return 0;
}



