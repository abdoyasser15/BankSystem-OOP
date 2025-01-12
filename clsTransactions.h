#pragma once
#include <iostream>
using namespace std;
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTransactions :protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }
    static double ReadAmount(clsBankClient SourceClient)
    {
        double Amount;
        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate::ReadDoubleNumber();
        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDoubleNumber();
        }
        return Amount;
    }
public:
	static void ShowTransfer() {
		_DrawScreenHeader("\tTransfer Screen");
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationClient);
		double Amount = ReadAmount(SourceClient);
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

