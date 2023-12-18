#pragma once
#include <string>

class CompoundInterestCalculator {
	public:

		// Methods for calculating interest and displaying user output
		string nCharString(size_t n, char c);
		void PrintDetails(int yearNumber, double yearEndBalance, double interestEarned);
		double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double monthlyInterest, int numYears);
		double calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyInterest, double monthlyDeposit, int numYears);
		void PrintMenu();

};