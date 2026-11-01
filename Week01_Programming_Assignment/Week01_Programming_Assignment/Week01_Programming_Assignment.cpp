#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Make our variables
    string name;
    int shares;
    int menuChoice;
    double purchasePrice;
    double currentPrice;
    double totalCost;
    double currentValue;
    double profitLoss;
    double percentChange;

    // Welcome message
    cout << "==================================" << endl;
    cout << "       Stock Investment Tracker" << endl;
    cout << "==================================" << endl;
    cout << "Welcome to my stock market program!" << endl;
    cout << endl;

    // Get the user's name
    cout << "What is your full name? ";
    getline(cin, name);

    // Get the user's investment information
    cout << "How many shares did you purchase? ";
    cin >> shares;

    if (cin.fail() || shares <= 0)
    {
        cout << "Invalid number of shares." << endl;
        return 1;
    }

    cout << "What was the purchase price per share? $";
    cin >> purchasePrice;

    if (cin.fail() || purchasePrice <= 0)
    {
        cout << "Invalid purchase price." << endl;
        return 1;
    }

    cout << "What is the current price per share? $";
    cin >> currentPrice;

    if (cin.fail() || currentPrice < 0)
    {
        cout << "Invalid current price." << endl;
        return 1;
    }

    // Calculate the investment values
    totalCost = shares * purchasePrice;
    currentValue = shares * currentPrice;
    profitLoss = currentValue - totalCost;
    percentChange = (profitLoss / totalCost) * 100;

    // Display the menu
    cout << endl;
    cout << "==================================" << endl;
    cout << "             Main Menu" << endl;
    cout << "==================================" << endl;
    cout << "1. View profit or loss" << endl;
    cout << "2. View investment report" << endl;
    cout << "3. Get investment performance rating" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> menuChoice;

    if (cin.fail() || menuChoice < 1 || menuChoice > 3)
    {
        cout << "Invalid menu choice." << endl;
        return 1;
    }

    cout << fixed << setprecision(2);

    // Use switch to handle the user's menu choice
    switch (menuChoice)
    {
    case 1:
        cout << endl;
        cout << "Your total investment was $" << totalCost << endl;
        cout << "Your investment is now worth $" << currentValue << endl;

        // Check whether the investment gained or lost money
        if (profitLoss > 0)
        {
            cout << "You made a profit of $" << profitLoss << endl;
        }
        else if (profitLoss < 0)
        {
            cout << "You have a loss of $" << -profitLoss << endl;
        }
        else
        {
            cout << "Your investment has not gained or lost money." << endl;
        }
        break;

    case 2:
        // Display a formatted investment report
        cout << endl;
        cout << "==================================" << endl;
        cout << "        Investment Report" << endl;
        cout << "==================================" << endl;

        cout << left << setw(22) << "Name:" << name << endl;
        cout << left << setw(22) << "Shares purchased:" << shares << endl;
        cout << left << setw(22) << "Purchase price:" << purchasePrice << endl;
        cout << left << setw(22) << "Current price:" << currentPrice << endl;
        cout << left << setw(22) << "Total cost:" << totalCost << endl;
        cout << left << setw(22) << "Current value:" << currentValue << endl;
        cout << left << setw(22) << "Profit/Loss:" << profitLoss << endl;
        cout << left << setw(22) << "Percent change:" << percentChange << "%" << endl;
        break;

    case 3:
        // Give an investment performance rating
        cout << endl;
        cout << "Investment Performance Rating" << endl;

        if (percentChange >= 10 && profitLoss > 0)
        {
            cout << "Your investment has performed very well!" << endl;
        }
        else if (percentChange > 0 && percentChange < 10)
        {
            cout << "Your investment has made a small profit." << endl;
        }
        else if (percentChange == 0)
        {
            cout << "Your investment has not changed in value." << endl;
        }
        else
        {
            cout << "Your investment has lost value." << endl;
        }
        break;
    }

    // Create the report file
    ofstream outFile;
    outFile.open("report.txt");

    // Check that the file opened
    if (!outFile)
    {
        cout << "Error opening report.txt." << endl;
        return 1;
    }

    // Save the investment report
    outFile << fixed << setprecision(2);
    outFile << "==================================" << endl;
    outFile << "        Investment Report" << endl;
    outFile << "==================================" << endl;

    outFile << left << setw(22) << "Name:" << name << endl;
    outFile << left << setw(22) << "Shares purchased:" << shares << endl;
    outFile << left << setw(22) << "Purchase price:" << purchasePrice << endl;
    outFile << left << setw(22) << "Current price:" << currentPrice << endl;
    outFile << left << setw(22) << "Total cost:" << totalCost << endl;
    outFile << left << setw(22) << "Current value:" << currentValue << endl;
    outFile << left << setw(22) << "Profit/Loss:" << profitLoss << endl;
    outFile << left << setw(22) << "Percent change:" << percentChange << "%" << endl;

    // Close the file
    outFile.close();

    cout << endl;
    cout << "Your report was saved to report.txt!" << endl;

    return 0;
}