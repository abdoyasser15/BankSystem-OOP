#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"
class clsFindUserScreen:protected clsScreen 
{
private:
    static void _PrintUser(clsUser User) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUserName    :" << User.UserName;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }
public:
    static void ShowFindUser() {
        _DrawScreenHeader("\t  Find User Screen");
        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(UserName);
        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
        _PrintUser(User1);
    }
};

