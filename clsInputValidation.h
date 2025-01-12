#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"
#include <string>
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To) {
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(double Number, double From, double To) {
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(float Number, float From, float To) {
		return (Number >= From && Number <= To);
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		return (clsDate::IsDate1AfterDate2(Date, From) && clsDate::IsDate1BeforeDate2(Date, To) ||
			clsDate::IsDate1AfterDate2(Date, To) && clsDate::IsDate1BeforeDate2(Date, From));
	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number , Enter Again \n") {
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number , Enter Again : \n") {
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static float ReadfloatNumber(string ErrorMessage = "Invalid Number , Enter Again : \n") {
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number Is Not Within Range , Enter Another Number : \n") {
		int Number;
		cin >> Number;
		while (!clsInputValidate::IsNumberBetween(Number, From, To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static short ReadshortNumberBetween(short From,short To, string ErrorMessage = "Number Is Not Within Range , Enter Another Number : \n") {
		short Number;
		cin >> Number;
		while (!clsInputValidate::IsNumberBetween(Number, From, To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid Number , Enter Again \n";
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

