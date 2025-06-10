/*
Program Name: Airport Parking Fee Calculator
Author: Addisu Lococo
Date: 2/27/2025
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    double hoursParked; // Number of hours parked
    double parkingFee; // Calculated parking fee
    

    // Output introduction of the program to the user
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Airport Parking Fee Calculator                                                  |\n";
    cout << "This program calculates the parking fee based on the number of hours parked.    |\n";
    cout << "Please enter the number of hours parked:                                        |\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Prompt for hours parked
    cout << "Enter the number of hours parked: ";
    cin >> hoursParked;

    // Calculate parking fee based on hours parked
    if (hoursParked >= 0 && hoursParked <= 3) {    
        parkingFee = 5.0;
    }
    else if (hoursParked > 3 && hoursParked <= 9) {
        parkingFee = 6.0 * static_cast<int>(hoursParked + 1);
    }
    else if (hoursParked > 9 && hoursParked <= 24) {
        parkingFee = 60.0;
    }
    else {
        parkingFee = 150.0;
    }

    // Output results to user
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Parking Fee Calculation Result: \n";
    cout << "Total parking fee for " << hoursParked;
    cout << fixed << showpoint << setprecision(2);
    cout << " hours is: $" << parkingFee << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";


    return 0;
}