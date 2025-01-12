#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUser.h"
#include "clsUser.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUserScreen:protected clsScreen
{
private:
	enum _enManageUsers{enListUser=1,enAddNewUser=2,enDeleteUser=3,enUpdateUser=4,enFindUser=5,enMainMenu=6};
	static short _ReadManageUsersOptions() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _ShowListUsers() {
		clsUsersListScreen::ShowUsersList();
	}
	static void _ShowAddNewUser() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUser() {
		clsDeleteUser::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUser() {
		clsUpdateUserScreen::_ShowUpdateUser();
	}
	static void _ShowFindUser(){
		clsFindUserScreen::ShowFindUser();
	}
	static void _GoBackToTheManageUsersScreen() {
		cout << setw(37) << left << "\nPress Any Key To Go Back To The Manage Users Menu...";
		system("pause>0");
		showManageUsersOptions();
	}
	static void _PerformManagesersmenu(_enManageUsers Manage) {
		switch (Manage)
		{
		case _enManageUsers::enListUser:
			system("cls");
			_ShowListUsers();
			_GoBackToTheManageUsersScreen();
			break;
		case _enManageUsers::enAddNewUser:
			system("cls");
			_ShowAddNewUser();
			_GoBackToTheManageUsersScreen();
			break;
		case _enManageUsers::enDeleteUser:
			system("cls");
			_ShowDeleteUser();
			_GoBackToTheManageUsersScreen();
			break;
		case _enManageUsers::enUpdateUser:
			system("cls");
			_ShowUpdateUser();
			_GoBackToTheManageUsersScreen();
			break;
		case _enManageUsers::enFindUser:
			system("cls");
			_ShowFindUser();
			_GoBackToTheManageUsersScreen();
			break;
		case _enManageUsers::enMainMenu:
			
			break;
		}
	}
public:
	static void showManageUsersOptions() {
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;//this will be exit the function
		}
		system("cls");
		_DrawScreenHeader("\tManage Users Screen.");
		cout << setw(37) <<  left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t   Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete user.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManagesersmenu((_enManageUsers)_ReadManageUsersOptions());
	}
};

