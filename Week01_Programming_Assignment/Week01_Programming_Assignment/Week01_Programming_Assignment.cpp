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
    int menuChoice = 0;
    int year;
    double purchasePrice;
    double currentPrice;
    double totalCost;
    double currentValue;
    double profitLoss;
    double percentChange;
    double projectedValue;

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

    // Keep asking until the user enters valid shares
    while (cin.fail() || shares <= 0)
    {
        cout << "Invalid number of shares. Try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> shares;
    }

    cout << "What was the purchase price per share? $";
    cin >> purchasePrice;

    // Keep asking until the purchase price is valid
    while (cin.fail() || purchasePrice <= 0)
    {
        cout << "Invalid purchase price. Try again: $";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> purchasePrice;
    }

    cout << "What is the current price per share? $";
    cin >> currentPrice;

    // Keep asking until the current price is valid
    while (cin.fail() || currentPrice < 0)
    {
        cout << "Invalid current price. Try again: $";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> currentPrice;
    }

    // Calculate the investment values
    totalCost = shares * purchasePrice;
    currentValue = shares * currentPrice;
    profitLoss = currentValue - totalCost;
    percentChange = (profitLoss / totalCost) * 100;

    cout << fixed << setprecision(2);

    // Keep displaying the menu until the user exits
    do
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "             Main Menu" << endl;
        cout << "==================================" << endl;
        cout << "1. View profit or loss" << endl;
        cout << "2. View investment report" << endl;
        cout << "3. Get investment performance rating" << endl;
        cout << "4. View 5-year investment projection" << endl;
        cout << "5. Exit program" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> menuChoice;

        // Check for invalid menu choices
        if (cin.fail() || menuChoice < 1 || menuChoice > 5)
        {
            cout << "Invalid menu choice. Try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
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
                cout << left << setw(22) << "Purchase price:" << "$" << purchasePrice << endl;
                cout << left << setw(22) << "Current price:" << "$" << currentPrice << endl;
                cout << left << setw(22) << "Total cost:" << "$" << totalCost << endl;
                cout << left << setw(22) << "Current value:" << "$" << currentValue << endl;
                cout << left << setw(22) << "Profit/Loss:" << "$" << profitLoss << endl;
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

            case 4:
                // Show an example 5-year investment projection
                cout << endl;
                cout << "==================================" << endl;
                cout << "     5-Year Investment Projection" << endl;
                cout << "==================================" << endl;
                cout << "Example using 5% yearly growth." << endl;
                cout << "Actual stock returns are not guaranteed." << endl;
                cout << endl;

                projectedValue = currentValue;

                cout << left << setw(10) << "Year"
                    << "Projected Value" << endl;

                // Repeat the calculation for five years
                for (year = 1; year <= 5; year++)
                {
                    projectedValue = projectedValue * 1.05;

                    cout << left << setw(10) << year
                        << "$" << projectedValue << endl;
                }
                break;

            case 5:
                cout << endl;
                cout << "Thank you for using the Stock Investment Tracker!" << endl;
                break;
            }
        }

    } while (menuChoice != 5);

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
    outFile << left << setw(22) << "Purchase price:" << "$" << purchasePrice << endl;
    outFile << left << setw(22) << "Current price:" << "$" << currentPrice << endl;
    outFile << left << setw(22) << "Total cost:" << "$" << totalCost << endl;
    outFile << left << setw(22) << "Current value:" << "$" << currentValue << endl;
    outFile << left << setw(22) << "Profit/Loss:" << "$" << profitLoss << endl;
    outFile << left << setw(22) << "Percent change:" << percentChange << "%" << endl;

    // Close the file
    outFile.close();

    cout << endl;
    cout << "Your report was saved to report.txt!" << endl;

    return 0;
}
