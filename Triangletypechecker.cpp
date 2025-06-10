/*
Insert standard heading
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declare variables for the lengths of the triangle sides
    double a, b, c;

    // Output introduction to the user
    cout << "Welcome to the Triangle Type Checker!" << endl;
    cout << "This program will determine if the triangle with the given sides is a right triangle." << endl;
    cout << "Please enter the lengths of the three sides of the triangle:" << endl;

    // Input lengths of the triangle sides
    cout << "Enter side a: ";
    cin >> a;
    cout << "Enter side b: ";
    cin >> b;
    cout << "Enter side c: ";
    cin >> c;

    // Check for right triangle using Pythagorean theorem
    if (pow(a, 2) + pow(b, 2) == pow(c, 2) ||
        pow(a, 2) + pow(c, 2) == pow(b, 2) ||
        pow(b, 2) + pow(c, 2) == pow(a, 2)) {
        cout << "The triangle with sides " << a << ", " << b << ", and " << c << " is a right triangle." << endl;
    }
    else {
        cout << "The triangle with sides " << a << ", " << b << ", and " << c << " is not a right triangle." << endl;
    }

    return 0;
}