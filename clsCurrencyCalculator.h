#pragma once
#include <iostream>
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrecny.h"
using namespace std;
class clsCurrencyCalculator:protected clsScreen
{
private:
	static string _ReadCurrencyCode1() {
		string CurrencyCode = "";
		cout << "\nPlease Enter CurrencyCode1 : ";
		CurrencyCode = clsInputValidate::ReadString();
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		return CurrencyCode;
	}
	static string _ReadCurrencyCode2() {
		string CurrencyCode = "";
		cout << "\nPlease Enter CurrencyCode2 : ";
		CurrencyCode = clsInputValidate::ReadString();
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		return CurrencyCode;
	}
	static float _GetAmount() {
		float Amount;
		cout << "\nEnter Amount to Exchange : ";
		Amount = clsInputValidate::ReadfloatNumber();
		return Amount;
	}
	static void _PrintCurrentFrom(clsCurrecny Curr) {
		cout << "\nConvert From : ";
		cout << "\n_______________________________\n";
		cout << "Country    : " << Curr.Country() << "\n";
		cout << "Code       : " << Curr.CurrencyCode() << "\n";
		cout << "Name       : " << Curr.CurrencyName() << "\n";
		cout << "Rate(1$) = : " << Curr.Rate() << "\n";
		cout << "_______________________________\n";
	}
	static void _PrintCurrentTo(clsCurrecny Curr) {
		cout << "\nTo : ";
		cout << "\n_______________________________\n";
		cout << "Country    : " << Curr.Country() << "\n";
		cout << "Code       : " << Curr.CurrencyCode() << "\n";
		cout << "Name       : " << Curr.CurrencyName() << "\n";
		cout << "Rate(1$) = : " << Curr.Rate() << "\n";
		cout << "_______________________________\n";
	}
public:
	static void _ShowCurrencyCalculator() {
		string Title = "\t Update Currency Screen";
		_DrawScreenHeader(Title);
		string CurrencyCode1 = _ReadCurrencyCode1();
		while (!clsCurrecny::IsCurrencyExist(CurrencyCode1)) {
			cout << "Invalid Enter Again : ";
			CurrencyCode1 = _ReadCurrencyCode1();
		}
		clsCurrecny Curr1 = clsCurrecny::FindByCode(CurrencyCode1);
		string CurrencyCode2 = _ReadCurrencyCode2();
		while (!clsCurrecny::IsCurrencyExist(CurrencyCode2)) {
			cout << "Invalid Enter Again : ";
			CurrencyCode2 = _ReadCurrencyCode2();
		}
		clsCurrecny Curr2 = clsCurrecny::FindByCode(CurrencyCode2);
		float Amount = _GetAmount();
		_PrintCurrentFrom(Curr1);
		float dollar = Amount / Curr1.Rate();
		cout << Amount << " " << Curr1.CurrencyCode() << " = " << dollar << "USD" << endl;
		if (Curr2.CurrencyCode()!="USD"){
			_PrintCurrentTo(Curr2);
			cout << Amount << " " << Curr1.CurrencyCode() << " = " << Curr2.Rate() * dollar << " " << Curr2.CurrencyCode() << endl;
		}
		char Check = 'n';
		cout << "Do You Perform To Perform Another Calculation Y/N ? ";
		cin >> Check;
		if (Check=='y'||Check=='Y') {
			system("cls");
			_ShowCurrencyCalculator();
		}
	}

};

