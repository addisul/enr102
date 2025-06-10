/*
Program Name: Diode Characteristics
Author: Addisu Lococo
Date: 3/27/2025
Description: two dimensional array organizing 100 data points by voltage, current and resistance. I(v) = I_o (e^(V/.026) -1)
*/

#include <iostream>
#include <iomanip>
#include <cmath>  // e^x -> exp (x) in <cmath header>
using namespace std;

const int ROWS = 100;
const int COLS = 3;

void fillArray2cols(double testArray[][COLS]); //used to fill the first 2 columns with diode voltage and current
void calcResistance(double testArray[][COLS]); //used to calculate diode resistance for each voltage
//void searchArray(double testArray[][COLS], double v, double& r); //used to search array to find the resistance at a user-specified voltage, return 'r' as resistance found at voltage 'v'

void intro(); //introduces user to program
void printArray(double testArray[][COLS]); //prints array to monitor

int main()
{
	//declare variables
	double diodeData[ROWS][COLS]; //first column is diode current, second is diode voltage calculated from diode current, third is diode resistance calculated from I and V.
	double voltage, resistance; // user will choose a voltage and program will determine resistance
	bool done; //used to determine when user is done finding resistance

	intro(); //explain to user what program does and how to use it
	
	//fill the first two columns with voltage and current of diode
	fillArray2cols(diodeData);


	//calculate resistance using I and V
	calcResistance(diodeData);

	//print the array
	printArray(diodeData);
	done = false;
	while (!done)
	{


		cout << endl << "Enter a value for diode voltage (must have only 2 decimal places): ";
		cin >> voltage;

		//find the resistance in the array that matches the user's voltaage
		searchArray(diodeData, voltage, resistance);

		//output results
		cout << endl << "Resistance at voltage of " << voltage << "V = " << resistance << "ohms" << endl << endl;
		cout << "Are you done with performing these determinations? Please enter 1 for yes and 0 for no: ";
		cin >> done;
	}
	cout << endl << "Thank you for using the program. " << endl;
}

/*
Function Name: intro
Author: Addisu Lococo
Date: 3/27/2025
Description: introduces function to the user
*/
void intro()
{
	cout << "This program uses diode theory to calculate the relationship between current and voltage for a diode." << endl;
	cout << "It then determines the resistance of the diode at each voltage." << endl;
	cout << "The user can enter a voltage value, and the program will provide the diode's resistance at that value." << endl;
	cout << "The user can repeat that work as often as they like, until they are done." << endl;
}
/*
Function Name: fillArray2cols
Author: Addisu Lococo
Date: 3/27/2025
Description: fills the array
*/
void fillArray2cols(double testArray[][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{

		testArray[i][0] = i * 0.01;
		testArray[i][1] = 2.0e-13 * (exp(testArray[i][0] / 0.026) - 1); //calculates current value for this row

	}
}
/*
Function Name: calcResistance
Author: Addisu Lococo
Date: 3/27/2025
Description: calculates the resistance using V and I
*/
void calcResistance(double testArray[][COLS])
{
	for (int i = 1; i < ROWS; i++)       //R = V/I = 0.01/(I_n - I_n-1)
	{
		testArray[i][2] = 0.01 / (testArray[i][1] - testArray[i - 1][1]);
	}
}
/*
Function Name: searchArray
Author: Addisu Lococo
Date: 3/27/2025
Description: The value of v (Voltage) is sent to the function and must be a value of 0 and 1.0 (does not include ti
*/
void searchArray(double testArray[][COLS], double v, double& e)
{
	int loc;

}
/*
Function Name: printArray
Author: Addisu Lococo
Date: 3/27/2025
Description:
*/
void printArray(double testArray[][COLS])
{
	cout << setw(25) << "Diode Voltage (V)" << setw(25) << "Diode Current (A)" << setw(25) << "Diode Resistance (Ohms)" << endl;
	cout << setw(75) << setfill('-') << " " << setfill(' ') << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << "Row " << i + 1 << ": ";
		for (int j = 0; j < COLS; j++)
		{
			cout << setw(15) << testArray[i][j] << " ";
		}
		cout << endl;
	}
}