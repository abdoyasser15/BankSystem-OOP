#pragma once
#include <iostream>
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrecny.h"
using namespace std;
class clsUpdateRate:protected clsScreen
{
private:
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
	static float _GetNewRate() {
		float Rate;
		cout << "\nUpdate Currency Rate : ";
		cout << "\n_________________________";
		cout << "\nEnter New Rate : ";
		Rate = clsInputValidate::ReadfloatNumber();
		return Rate;
	}
public:
	static void ShowUpateRate() {
		string Title = "\t Update Currency Screen";
		_DrawScreenHeader(Title);
		string CurrencyCode = _ReadCurrencyCode();
		while (!clsCurrecny::IsCurrencyExist(CurrencyCode)) {
			cout << "Invalid Enter Again : ";
			CurrencyCode = _ReadCurrencyCode();
		}
		clsCurrecny Curr = clsCurrecny::FindByCode(CurrencyCode);
		_PrintCurrent(Curr);
		char Check = 'n';
		cout << "\nAre You Sure You Want to Update The Rate Of This Currency Y/N ? ";
		cin >> Check;
		if (Check=='y'||Check=='Y') {
			float Rate = _GetNewRate();
			Curr.UpdateRate(Rate);
			_PrintCurrent(Curr);
		}
	}
};

