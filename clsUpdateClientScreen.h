#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateClientScreen:clsScreen
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
	static void UpdateClient() {
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
			return;//this will be exit the function
		}
		_DrawScreenHeader("\tUpdate Client Screen");
		cout << "\nPlease Enter client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account Number is Not Found , Choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		cout << "\n\nUpdate Client Info : ";
		cout << "\n____________________________";
		_ReadClientInfo(Client1);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyProject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		}
	}
};

