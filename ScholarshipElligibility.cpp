#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	bool eligible = false;
	int response;

	cout << setw(20) << setfill('*') << " " << "    DCC SCHOLARSHIP ELIGIBILITY TEST     " << setw(20) << setfill('*')
		<< " " << endl << endl;
	cout << "Demonstrate setw and setfill." << endl << "Note if column width needed is wider than width set, C++ will automatically\n expand the width." << endl << endl;
	cout << setw(10) << setfill('*') << "hello" << setw(10) << setfill(' ') << "hello" << " " << setw(5) << "123456" << endl << endl;
	cout << "This program will test to see if you are elibible for a DCC Foundation" << endl << "     Scholarship." <<
		endl << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;

	cout << "After each question, type the number '1' to answer yes and the number '0' to" << endl <<
		"      answer no.  Then press ENTER." << endl << endl;

	cout << "-------------------------------------------------------------------------------" << endl << endl;

	cout << "Will you have earned 24 or more credits at DCC, including credits taken" << endl << "      this semester? Response: ";
	cin >> response;

	if (response)
	{
		cout << endl << "Is your current cumulative GPA at 2.0 or higher? Response: ";
		cin >> response;

		if (response)
		{

			cout << endl << "Will you be enrolled in 12 or more credits at DCC in the upcoming" << endl <<
				"     fall semester? Response: ";
			cin >> response;

			if (response)
			{
				cout << endl << "Are you a Conklin Scholar? Response: ";
				cin >> response;

				if (!response)
				{
					cout << endl << "Are you matriculated in a program or certificate? Response: ";
					cin >> response;

					if (response)
					{
						cout << endl << "Have you previously earned a degree or certificate at DCC? Response: ";
						cin >> response;

						if (!response)
							eligible = true;
					}
				}
			}
		}
	}

	cout << endl << "-------------------------------------------------------------------------------" << endl << endl;

	if (eligible)
		cout << endl << "You are eligible for a scholarship, PLEASE APPLY!!" << endl << endl;
	else
		cout << endl << "I'm sorry, you are not eligible at this time." << endl << endl;

	return 0;
}