#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsListClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "FindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
using namespace std;
class clsMainScreen:protected clsScreen 
{
private:
	enum _enMainMenuOptions{enShowClientList = 1,enAddNewClient=2,enDeleteClient=3,
	enUpdateClient=4,enFindClient=5,enTransactions=6,enManagerUsers=7,enloginRegisterScreen=8,enCurrencyExchange=9,enLogout=10};
	static short _ReadMainMenuOptions() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}
	// ...
	static void _GoBackToTheMainMenu() {
		cout << setw(37) << left << "\nPress Any Key To Go Back To The Main MenuScreen...";
		system("pause>0");
		ShowMainMenuScreen();
	}
	static void _ShowAllClientScreen() {
		clsListClientScreen::ShowClientList();
 	}
	static void _ShowAddNewClientScreen() {
		clsAddNewClientScreen::AddNewClient();
	}
	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::DeleteClientMethod();
	}
	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::UpdateClient();
	}
	static void _ShowFindClientScreen() {
		FindClientScreen::FindClient();
	}
	static void _ShowTransactionsMenu() {
		clTransactionsScreen::ShowTransactionsScreen();
	}
	static void _ShowManageUsersMenu() {
		clsManageUserScreen::showManageUsersOptions();
	}
	static void _ShowLoginRegisterScreen() {
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchange() {
		clsCurrencyExchangeScreen::_ShowMainCurrentScreen();
	}
	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
		// Then WILL go Back
	}
	static void _PerformMainmenuOptions(_enMainMenuOptions Menu) {
		switch (Menu)
		{
		case clsMainScreen::enShowClientList:
			system("cls");
			_ShowAllClientScreen();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enTransactions:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enManagerUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enloginRegisterScreen:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enCurrencyExchange:
			system("cls");
			_ShowCurrencyExchange(); 
			_GoBackToTheMainMenu();
			break;
		case clsMainScreen::enLogout:
			system("cls");
			_Logout();
			break;
		}
	}
public:
	static void ShowMainMenuScreen() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainmenuOptions((_enMainMenuOptions)_ReadMainMenuOptions());
	}
};

