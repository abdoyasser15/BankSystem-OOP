#pragma once
#include <iostream>
#include "clsInputValidation.h"
#include "clsString.h"
#include "clsCurrecny.h"
#include "clsScreen.h"
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:
	static short _ReadChoice() {
		cout << "\nFind By : [1] Code Or [2] Country ? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 2, "\nEnter Number between 1 to 2 ? ");
		return Choice;
	}
	static string _ReadCurrencyCode() {
		string CurrencyCode = "";
		cout << "\nPlease Enter CurrencyCode : ";
		CurrencyCode = clsInputValidate::ReadString();
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		return CurrencyCode;
	}
	static void _PrintCurrent(clsCurrecny Curr) {
		cout << "\nCurrency Card : ";
		cout << "\n_______________________________\n";
		cout << "Country    : " << Curr.Country() << "\n";
		cout << "Code       : " << Curr.CurrencyCode() << "\n";
		cout << "Name       : " << Curr.CurrencyName() << "\n";
		cout << "Rate(1$) = : " << Curr.Rate() << "\n";
		cout << "_______________________________\n";
	}
	static string _ReadCountry() {
		string CountryName = "";
		cout << "\nPlease Enter CountryName : ";
		CountryName = clsInputValidate::ReadString();
		CountryName = clsString::UpperAllString(CountryName);
		return CountryName;
	}
public:
	static void _ShowFindCurrencyScreen() {
		string Title = "\tFind Currency Screen ";
		_DrawScreenHeader(Title);
		short Choice = _ReadChoice();
		if (Choice == 1) {
			string CurrencyCode = _ReadCurrencyCode();
			clsCurrecny Curr = clsCurrecny::FindByCode(CurrencyCode);
			if (clsCurrecny::IsCurrencyExist(CurrencyCode)) {
				_PrintCurrent(Curr);
			}
			else {
				cout << "\nCurrency Was not Found :-(\n";
			}
		}
		else if(Choice==2){
			string Countryname = _ReadCountry();
			clsCurrecny Curr = clsCurrecny::FindByCountry(Countryname);
			if (!Curr.Is_Empty()) {
				_PrintCurrent(Curr);
			}
			else {
				cout << "\nCurrency Was not Found :-(\n";
			}
		}
		
	}
};

