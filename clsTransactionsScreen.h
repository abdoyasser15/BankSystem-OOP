#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDepositeScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransactions.h"
#include "clsTransferLog.h"
using namespace std;
class clTransactionsScreen :protected clsScreen
{
private:
	enum _enTransactionsMenu { enDeposite = 1, enWithDraw = 2, enTotalBalnces = 3,enTransactions=4,enTransferLog=5, enMainMenu = 6 };
	static short _ReadTransactionsOptions() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _GoBackToTheTransactionsmenu() {
		cout << setw(37) << left << "\nPress Any Key To Go Back To The Transaction Menu...";
		system("pause>0");
		ShowTransactionsScreen();
	}
	static void _PerformTransactionsMenu(_enTransactionsMenu Menu) {
		switch (Menu)
		{
		case _enTransactionsMenu::enDeposite:
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTheTransactionsmenu();
			break;
		case _enTransactionsMenu::enWithDraw:
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTheTransactionsmenu();
			break;
		case _enTransactionsMenu::enTotalBalnces:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTheTransactionsmenu();
			break;
		case _enTransactionsMenu::enTransactions:
			system("cls");
			_ShowTrasactions();
			_GoBackToTheTransactionsmenu();
			break;
		case _enTransactionsMenu::enTransferLog:
			system("cls");
			_ShowTrasactionsLog();
			_GoBackToTheTransactionsmenu();
			break;
		case _enTransactionsMenu::enMainMenu:// Not Skip
			
			break;
		}
	}
	static void _ShowDepositeScreen() {
		clsDepositeScreen::DepositeScreen();
	}
	static void _ShowWithDrawScreen() {
		clsWithDrawScreen::WithDrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTrasactions() {
		clsTransactions::ShowTransfer();
	}
	static void _ShowTrasactionsLog() {
		clsTransferLog::ShowTransferLog();
	}
public:
	static void ShowTransactionsScreen() {
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
			return;//this will be exit the function
		}
		_DrawScreenHeader("\tTransactions Menu Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposite Screen.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw Screen.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances Screen.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] MainMenu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenu((_enTransactionsMenu)_ReadTransactionsOptions());
	}
};

