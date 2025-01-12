#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include <iomanip>
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculator.h"
using namespace std;
class clsCurrencyExchangeScreen:protected clsScreen 
{
private:
	enum enCurrent{ListCurrencies=1,FindCurrencies=2,UpdateCurrencies=3,CurrencyCalculator=4,MainMenu=5};
	static short _ReadMainCurrencyOptions() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _GoBackToMainCurrency() {
		cout << setw(37) << left << "\nPress Any Key To Go Back To The Main MenuScreen...";
		system("pause>0");
		_ShowMainCurrentScreen();
	}
	static void _ShowListCurrencies() {
		clsCurrencyListScreen::_ShowListCurrentScreen();
	}
	static void _ShowFindCurrencies() {
		clsFindCurrencyScreen::_ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurrencies() {
		clsUpdateRate::ShowUpateRate();
	}
	static void _ShowCurrencyCalculator() {
		clsCurrencyCalculator::_ShowCurrencyCalculator();
	}
	static void _performCurrencyExchange(enCurrent Curr) {
		switch (Curr)
		{
		case enCurrent::ListCurrencies:
			system("cls");
			_ShowListCurrencies();
			_GoBackToMainCurrency();
			break;
		case enCurrent::FindCurrencies:
			system("cls");
			_ShowFindCurrencies();
			_GoBackToMainCurrency();
			break;
		case enCurrent::UpdateCurrencies:
			system("cls");
			_ShowUpdateCurrencies();
			_GoBackToMainCurrency();
			break;
		case enCurrent::CurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToMainCurrency();
			break;
		case enCurrent::MainMenu:
			break;
		}
	}
public:
	static void _ShowMainCurrentScreen() {
		system("cls");
		string Title = "\t Currency Exchange Main Screen";
		_DrawScreenHeader(Title);
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_performCurrencyExchange((enCurrent)_ReadMainCurrencyOptions());
	}
};

