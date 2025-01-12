#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include"clsCurrecny.h"
#include "clsScreen.h"
class clsCurrencyListScreen:protected clsScreen
{
private:
	static void _printCurrency(clsCurrecny Curr) {
		cout << setw(8) << left << "" << "| " << setw(30) << left << Curr.Country();
		cout << "| " << setw(8) << left << Curr.CurrencyCode();
		cout << "| " << setw(45) << left << Curr.CurrencyName();
		cout << "| " << setw(10) << left << Curr.Rate();
	}
public:
	static void _ShowListCurrentScreen() {
		vector<clsCurrecny> vCurr = clsCurrecny::GetCurrenciesList();
		string Title = "\tCurrency list Screen.";
		string SubTitle = "\t    (" + to_string(vCurr.size()) + ") Currency.";
		_DrawScreenHeader(Title,SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		for (clsCurrecny C : vCurr) {
			_printCurrency(C);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

