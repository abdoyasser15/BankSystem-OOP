#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewClientScreen:protected clsScreen
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
	static void AddNewClient() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;//this will be exit the function
		}
		_DrawScreenHeader("\tAdd New Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter AccountNumber : ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account Number Is Already Used , Please Enter Another AccountNumber : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		clsAddNewClientScreen::_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyProject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists: {
			cout << "\nAccount Number is Exist \n";
			break;
		}

		}
	}
};

