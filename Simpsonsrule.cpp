/*
Program Name: Simpson's Rule
Author: Addisu Lococo
Date: 3/13/2025
Description: Program will use Simpson's rule to calcuate the integral of a well-defined
	function over a user defined interval. Calculations can be repeated, as often as user 
	wants, with different intervals and ifferent delta-x.
Use a function call to a function that calculates the area of a trapezoid.
*/


#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void areaTrapezoid(double h, double b1, double b2, double& a); //function prototype

int main()
{
	double xInitial, xFinal; //start and end points of integration interval
	double y1, y2; //y values of function of x at either end of a partition
	int numOfPartitions; //user-supplied numbre of partitions within intergration interval
	double deltaX; //calculation = (xFinal-xInitial)/numOfPartitions
	double areaOneTrapezoid, integral; //areaOneTrapezoid calculated by function and added into running sum to calculate integral
	bool done; //user enters 1 or 0 when asked if they are done to end the work


	cout << "Explain to user what the program does and how to use it..." << endl << endl;
	
	done = false; //initialize done to start the loop
	while (!done)
	{	// gather neccessary data from user
		cout << "Please enter the intial x value for the integration interval: ";
		cin >> xInitial;
		cout << "Please enter the final x value for the integration interval: ";
		cin >> xFinal;
		cout << "Please enter the number of partitions within the interval: ";
		cin >> numOfPartitions;

		//calculate deltaX
		deltaX = (xFinal - xInitial) / numOfPartitions;
		//set up loop for running sum, to calculate each area and add it into total sum which eventually is the integral.
		integral = 0;
		for (int i = 0; i < numOfPartitions; i++)
		{
			y1 = pow(xInitial, 2); //x1
			y2 = pow((xInitial + deltaX), 2); //x2
			areaTrapezoid(deltaX, y1, y2, areaOneTrapezoid); //calculate area of one trapezoid
			integral = integral + areaOneTrapezoid; //add area in to calculate integral
			xInitial = xInitial + deltaX;
		}
		cout << fixed << showpoint << setprecision(3);
		cout << "Integral = " << integral << endl << endl;

		cout << "Are you done? Please enter 1 for yes and 0 for no: ";
		cin >> done;

	}
	cout << "Thank you." << endl;
	return 0;
}
/*
Function Name: areaTrapezoid
Author: 
Date:
Function Description: This function calculates the area of a trapezoid given its height and the length of each of its bases. The area is returned through parameter 'a'. 
Parameters:
h - height of trapezoid, sent to function
b1 - length of one of the bases of trapezoid, sent to function
b2 - length of the other of the bases of trapezoid, sent to function
a - calculate area of trapezoid = (1/2)h(b1 + b2), returned to calling program
*/
void areaTrapezoid(double h, double b1, double b2, double& a)
{
	a = 0.5 * h * (b1 + b2);
}