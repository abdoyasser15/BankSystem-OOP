#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName : "; Client.firstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName : "; Client.lastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : "; Client.email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : "; Client.phone = clsInputValidate::ReadString();
		cout << "\nEnter Pin Code : "; Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter AccountBalance : "; Client.AccountBalance = clsInputValidate::ReadDoubleNumber();
	}
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
	static void DeleteClientMethod() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;//this will be exit the function
		}
		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "Enter AccountNumber You Want To Delete : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is Not Exist Please Enter Another AccountNumber : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		char Check = 'Y';
		cout << "\nAre You Sure You Want To Delete This Client Y/N : ";
		cin >> Check;
		if (Check == 'Y' || Check == 'y') {
			if (Client.Delete()) {
				cout << "Client Delete Successfully : ";
				_PrintClient(Client);
			}
			else {
				cout << "\nError Client Was not Deleted\n";
			}
		}
	}
};

