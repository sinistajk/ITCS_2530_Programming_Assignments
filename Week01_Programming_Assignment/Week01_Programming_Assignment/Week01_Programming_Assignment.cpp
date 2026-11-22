
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//VH Additions
//I will adjust the program with the 5-years Array to store the values
//... and introduce the risk levels
//=====================================================================
enum RiskTier { CONSERVATIVE, MODERATE, AGGRESSIVE };
RiskTier classifyRisk(double percentChange, double purchasePrice);
//=====================================================================


// Function declarations
void displayBanner();
void changeColor();
void getInput(string& name, int& shares, double& purchasePrice,
    double& currentPrice);
void calculateInvestment(int shares, double purchasePrice,
    double currentPrice, double& totalCost, double& currentValue,
    double& profitLoss, double& percentChange);
void displayMenu();

//VH Additions
//I am adjusting the saveReport function to include the risk profile and projected values
void saveReport(string name, int shares, double purchasePrice,
    double currentPrice, double totalCost, double currentValue,
    double profitLoss, double percentChange, RiskTier riskTier,
    const double projectedValues[5]);

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

    // Change console color and display welcome message
    changeColor();
    displayBanner();

    // Get and validate investment information
    getInput(name, shares, purchasePrice, currentPrice);

    // Calculate the investment values
    calculateInvestment(shares, purchasePrice, currentPrice,
        totalCost, currentValue, profitLoss, percentChange);

    //VH Additions
	//We will start using our new enum here to classify the risk of the 
    //investment based on the percent change and purchase price
    //=====================================================================
    double projectedValues[5];
    RiskTier riskTier = classifyRisk(percentChange, purchasePrice);
    //=====================================================================


    cout << fixed << setprecision(2);

    // Keep displaying the menu until the user exits
    do
    {
        displayMenu();
        cin >> menuChoice;

        // Check for invalid menu choices
        if (cin.fail() || menuChoice < 1 || menuChoice > 5)
        {
            cout << "Invalid menu choice. Try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            menuChoice = 0;
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
                if (profitLoss > 0 && percentChange >= 10)
                {
                    cout << "You made a large profit of $" << profitLoss << endl;
                }
                else if (profitLoss > 0 && percentChange < 10)
                {
                    cout << "You made a small profit of $" << profitLoss << endl;
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
                //=====================================================================
                //VH Additions
				//Here we will reflect the risk profile of the investment 
                //based on the percent change and purchase price
                //=====================================================================
                cout << left << setw(22) << "Risk profile:";
                switch (riskTier)
                {
                case CONSERVATIVE:
                    cout << "Conservative" << endl;
                    break;
                case MODERATE:
                    cout << "Moderate" << endl;
                    break;
                case AGGRESSIVE:
                    cout << "Aggressive" << endl;
                    break;
                }
                break;
                //=====================================================================

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

      
				//VH Additions
				//Here we will use an array to store and display the projected values for 5 years
                //also we will use another for loop to print it out
                //=====================================================================
            case 4:
            {
                // Show an example 5-year investment projection using an array
                cout << endl;
                cout << "==================================" << endl;
                cout << "     5-Year Investment Projection" << endl;
                cout << "==================================" << endl;
                cout << "Example using 5% yearly growth." << endl;
                cout << "Actual stock returns are not guaranteed." << endl;
                cout << endl;

                double runningValue = currentValue;
                for (int i = 0; i < 5; i++)
                {
                    runningValue = runningValue * 1.05;
                    projectedValues[i] = runningValue;
                }

                cout << left << setw(10) << "Year"
                    << "Projected Value" << endl;

                for (int i = 0; i < 5; i++)
                {
                    cout << left << setw(10) << (i + 1)
                        << "$" << projectedValues[i] << endl;
                }
                break;
            }
				//=====================================================================

            case 5:
                cout << endl;
                cout << "Thank you for using the Stock Investment Tracker!" << endl;
                break;
            }
        }

    } while (menuChoice != 5);

	//VH Additions
	// Saving the report in the file with the risk profile and projected values
	//=====================================================================
        /* saveReport(name, shares, purchasePrice, currentPrice,
        totalCost, currentValue, profitLoss, percentChange);*/
      
    // Save the investment report to a file
    saveReport(name, shares, purchasePrice, currentPrice,
        totalCost, currentValue, profitLoss, percentChange,
        riskTier, projectedValues);
	//=====================================================================

    return 0;
}

// Function to display the welcome banner
void displayBanner()
{
    cout << "==================================" << endl;
    cout << "       Stock Investment Tracker" << endl;
    cout << "==================================" << endl;
    cout << "Welcome to my stock market program!" << endl;
    cout << endl;
}

// Function to change the console text color
void changeColor()
{
    // Change text to green on a black background in Windows
    system("color 0A");
}

// Function to collect and validate user input
void getInput(string& name, int& shares, double& purchasePrice,
    double& currentPrice)
{
    // Get the user's name
    cout << "What is your full name? ";
    getline(cin, name);

    // Keep asking until a name is entered
    while (name == "")
    {
        cout << "Please enter your name: ";
        getline(cin, name);
    }

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
}

// Function to calculate investment values
void calculateInvestment(int shares, double purchasePrice,
    double currentPrice, double& totalCost, double& currentValue,
    double& profitLoss, double& percentChange)
{
    totalCost = shares * purchasePrice;
    currentValue = shares * currentPrice;
    profitLoss = currentValue - totalCost;
    percentChange = (profitLoss / totalCost) * 100;
}

// Function to display the main menu
void displayMenu()
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
}


//VH Additions
// Function to save the investment report to a file
//reflecting the risk profile and projected values
//=====================================================================
void saveReport(string name, int shares, double purchasePrice,
    double currentPrice, double totalCost, double currentValue,
    double profitLoss, double percentChange, RiskTier riskTier,
    const double projectedValues[5])
{
    // Create the report file
    ofstream outFile;
    outFile.open("report.txt");

    // Check that the file opened
    if (!outFile)
    {
        cout << "Error opening report.txt." << endl;
        return;
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
    outFile << left << setw(22) << "Risk profile:";
    switch (riskTier)
    {
    case CONSERVATIVE:
        outFile << "Conservative" << endl;
        break;
    case MODERATE:
        outFile << "Moderate" << endl;
        break;
    case AGGRESSIVE:
        outFile << "Aggressive" << endl;
        break;
    }

    outFile << endl;
    outFile << "==================================" << endl;
    outFile << "     5-Year Investment Projection" << endl;
    outFile << "==================================" << endl;
    outFile << left << setw(10) << "Year"
        << "Projected Value" << endl;

    for (int i = 0; i < 5; i++)
    {
        outFile << left << setw(10) << (i + 1)
            << "$" << projectedValues[i] << endl;
    }

    // Close the file
    outFile.close();

    cout << endl;
    cout << "Your report was saved to report.txt!" << endl;
}
//=====================================================================


//VH Additions
// Function to classify stock risk profile using an enum
//=====================================================================
RiskTier classifyRisk(double percentChange, double purchasePrice)
{
    if (percentChange < -10.0 || purchasePrice >= 500.0)
    {
        return AGGRESSIVE;
    }
    else if (percentChange >= -10.0 && percentChange <= 15.0)
    {
        return MODERATE;
    }
    else
    {
        return CONSERVATIVE;
    }
}
//=====================================================================