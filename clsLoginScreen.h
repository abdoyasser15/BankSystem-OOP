#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login() {
		bool LoginFaild = false;
        short counter = 3;
		string username, password;
        do
        {

            if (LoginFaild)
            {
                counter--;
                cout << "\nInvlaid Username/Password!\nYou Have "<<counter<<" Trials To Login.\n";
            }

            cout << "Enter Username? ";
            cin >> username;

            cout << "Enter Password? ";
            cin >> password;

            CurrentUser = clsUser::Find(username, password);
            LoginFaild = CurrentUser.IsEmpty();
        } while (LoginFaild&&counter>1);
        if (counter > 1) {
            CurrentUser.RegisterLogin();
            clsMainScreen::ShowMainMenuScreen();
            return true;
        }
        else {
         cout << "\nYou Have Locked After 3 Trials\n\n";
         return false;
        }
	}
public:
	static bool ShowLoginScreen() {
        system("cls");
		_DrawScreenHeader("\t Login Screen ");
        if (_Login()) {
            return true;
        }
        else {
            return false;
        }
	}
};

