#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Make our variables
    string name;
    double milesPerRun;
    int daysPerWeek;
    double minutesPerRun;

    // Welcome message
    cout << "==============================" << endl;
    cout << "     Weekly Running Tracker" << endl;
    cout << "==============================" << endl;
    cout << "Welcome to my running program!" << endl;
    cout << endl;

    // Prompt questions and get user input
    cout << "What is your full name? ";
    getline(cin, name);

    cout << "How many miles do you run per session? ";
    cin >> milesPerRun;

    // Check if input is valid
    if (cin.fail() || milesPerRun <= 0)
    {
        cout << "Invalid miles entered." << endl;
        return 1;
    }

    cout << "How many days per week do you run? ";
    cin >> daysPerWeek;

    if (cin.fail() || daysPerWeek < 1 || daysPerWeek > 7)
    {
        cout << "Invalid days entered." << endl;
        return 1;
    }

    cout << "How many minutes does each run take? ";
    cin >> minutesPerRun;

    if (cin.fail() || minutesPerRun <= 0)
    {
        cout << "Invalid minutes entered." << endl;
        return 1;
    }

    // Calculate weekly distance and exercise time
    double weeklyMiles = milesPerRun * daysPerWeek;
    double weeklyMinutes = minutesPerRun * daysPerWeek;

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

    // Display a formatted summary
    cout << endl;
    cout << "==============================" << endl;
    cout << "       Running Report" << endl;
    cout << "==============================" << endl;

    cout << fixed << setprecision(2);
    cout << left << setw(20) << "Name:" << name << endl;
    cout << left << setw(20) << "Miles per run:" << milesPerRun << endl;
    cout << left << setw(20) << "Days per week:" << daysPerWeek << endl;
    cout << left << setw(20) << "Minutes per run:" << minutesPerRun << endl;
    cout << left << setw(20) << "Weekly miles:" << weeklyMiles << endl;
    cout << left << setw(20) << "Weekly minutes:" << weeklyMinutes << endl;

    // Create a file to save the report
    ofstream outFile;
    outFile.open("report.txt");

    // Write the running report to the file
    outFile << fixed << setprecision(2);
    outFile << "==============================" << endl;
    outFile << "       Running Report" << endl;
    outFile << "==============================" << endl;

    outFile << left << setw(20) << "Name:" << name << endl;
    outFile << left << setw(20) << "Miles per run:" << milesPerRun << endl;
    outFile << left << setw(20) << "Days per week:" << daysPerWeek << endl;
    outFile << left << setw(20) << "Minutes per run:" << minutesPerRun << endl;
    outFile << left << setw(20) << "Weekly miles:" << weeklyMiles << endl;
    outFile << left << setw(20) << "Weekly minutes:" << weeklyMinutes << endl;

    // Close the file
    outFile.close();

    cout << endl;
    cout << "Your report was saved to report.txt!" << endl;

    return 0;
}
