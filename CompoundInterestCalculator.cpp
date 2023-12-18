#include <iostream>
#include <iomanip>
using namespace std;

#include "CompoundInterestCalculator.h"

// Function to create a string of a specified length of all one character
string CompoundInterestCalculator::nCharString(size_t n, char c) {
	string str;
	for (int i = 0; i < n; ++i) {
		str.push_back(c);
	}
	return str;
}

// Function to print a line to the table
void CompoundInterestCalculator::PrintDetails(int yearNumber, double yearEndBalance, double interestEarned) {
	int stringLength = to_string(yearEndBalance).size();  // Use this variable to get proper spacing in the tables
	cout << yearNumber << nCharString(20 - stringLength, ' ') << fixed << setprecision(2) << "$" << yearEndBalance
		<< nCharString(15, ' ') << fixed << setprecision(2) << "$" << interestEarned << endl;
}

// Function to calculate the balce with a monthly deposit
double CompoundInterestCalculator::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double monthlyInterest, int numYears) {
	double yearEndBalance = initialInvestment;
	// For loop compounds the interest monthly
	for (int i = 1; i <= 12; ++i) {
		yearEndBalance = yearEndBalance + (yearEndBalance * monthlyInterest);
	}

	return yearEndBalance;
}

// Function to calculate the balance with no monthly deposit
double CompoundInterestCalculator::calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyInterest, double monthlyDeposit, int numYears) {
	double yearEndBalance = initialInvestment;
	// For loop compounds the interest monthly and adds the monthly deposit
	for (int i = 1; i <= 12; ++i) {
		yearEndBalance = yearEndBalance + monthlyDeposit + ((yearEndBalance + monthlyDeposit) * monthlyInterest);
	}

	return yearEndBalance;
}

// Function to Print the display
void CompoundInterestCalculator::PrintMenu() {
	cout << nCharString(33, '*') << endl;
	cout << nCharString(10, '*') << " DataInput " << nCharString(12, '*') << endl;

	// Create variables for storing user input
	double initialInvestment;
	double monthlyDeposit;
	double interestRate;
	int numYears;

	// Create two variables for use in data table calculations
	double yearEndBalance;
	double interestEarned;

	// Collect user input
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> interestRate;
	interestRate = interestRate / 100 / 12; // Calculate the monthly interest percentage
	cout << "Number of years: ";
	cin >> numYears;
	cout << endl;

	// Create the table with no monthly deposits
	cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << nCharString(60, '=') << endl;
	cout << "Year" << nCharString(6, ' ') << "Year End Balance" << nCharString(6, ' ') << "Year End Interest Earned" << endl;
	cout << nCharString(60, '-') << endl;
	for (int i = 1; i <= numYears; ++i) {
		yearEndBalance = calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numYears);
		interestEarned = yearEndBalance - initialInvestment;
		initialInvestment = yearEndBalance; // Update the starting balance for the next iteration of the loop

		PrintDetails(i, yearEndBalance, interestEarned);
	}
	cout << endl;

	// Create the table with monthly deposits
	cout << "  Balance and Interest With Additional Monthly Deposits" << endl;
	cout << nCharString(60, '=') << endl;
	cout << "Year" << nCharString(6, ' ') << "Year End Balance" << nCharString(6, ' ') << "Year End Interest Earned" << endl;
	cout << nCharString(60, '-') << endl;
	for (int i = 1; i <= numYears; ++i) {
		yearEndBalance = calculateBalanceWithMonthlyDeposit(initialInvestment, interestRate, monthlyDeposit, numYears);
		interestEarned = yearEndBalance - initialInvestment;
		initialInvestment = yearEndBalance; // Update the starting balance for the next iteration of the loop

		PrintDetails(i, yearEndBalance, interestEarned);
	}

}