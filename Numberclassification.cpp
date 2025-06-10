#include <iostream>
using namespace std;

int main() {
    // Variable to store user input
    double number;

    // Output introduction to the user
    cout << "Welcome to the Number Classification Program!" << endl;
    cout << "This program will help you determine if a number is positive, negative, or zero." << endl;
    cout << "Please enter a number: ";

    // Get user input
    cin >> number;

    // Output the number and its classification
    if (number > 0) {
        cout << "You entered: " << number << ". This number is positive." << endl;
    }
    else if (number < 0) {
        cout << "You entered: " << number << ". This number is negative." << endl;
    }
    else {
        cout << "You entered: " << number << ". This number is zero." << endl;
    }

    return 0;
}