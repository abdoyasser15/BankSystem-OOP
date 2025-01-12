#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsListClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
using namespace std;
class FindClientScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
    {
	cout << "\nClient Card:";
	cout << "\n___________________";
	cout << "\nFirstName   : " << Client.GetFirstName();
	cout << "\nLastName    : " << Client.GetLastName();
	cout << "\nFull Name   : " << Client.FullName();
	cout << "\nEmail       : " << Client.email;
	cout << "\nPhone       : " << Client.phone;
	cout << "\nAcc. Number : " << Client.GetAccountNumber();
	cout << "\nPassword    : " << Client.PinCode;
	cout << "\nBalance     : " << Client.AccountBalance;
	cout << "\n___________________\n";
    }
public:
	static void FindClient() {
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;//this will be exit the function
		}
		_DrawScreenHeader("\t Find Client Screen ");
		string AccountNumber = "";
		cout << "Enter AccountNumber You Want To Find : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is Not Exist Please Enter Another AccountNumber : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}
		_PrintClient(Client);
	}
};

