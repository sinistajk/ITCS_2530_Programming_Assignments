#include <iostream>
using namespace std;

int main()
{
    // Make our variables
    double milesPerRun;
    int daysPerWeek;
    double minutesPerRun;

	// Prompt questions and get user input
    cout << "How many miles do you run per session? ";
    cin >> milesPerRun;

    cout << "How many days per week do you run? ";
    cin >> daysPerWeek;

    cout << "How many minutes does each run take? ";
    cin >> minutesPerRun;

    // Calculate weekly distance and exercise time
	double weeklyMiles = milesPerRun * daysPerWeek; // Calculate total miles run per week in a new var we just made
	double weeklyMinutes = minutesPerRun * daysPerWeek; // Calculate total minutes run per week in a new var we just made

    // Display a summary of user running activity
    cout << endl;
    cout << "Your Weekly Running Summary" << endl;
    cout << "You run " << milesPerRun << " miles per session, ";
    cout << daysPerWeek << " days per week." << endl;
    cout << "Each run takes about " << minutesPerRun;
    cout << " minutes." << endl;
    cout << "You run a total of " << weeklyMiles;
    cout << " miles and exercise for " << weeklyMinutes;
    cout << " minutes every week!" << endl;

    return 0;
}