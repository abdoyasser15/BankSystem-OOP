#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsTransferLog:protected clsScreen
{
private:
	static void _PrintCard(clsBankClient::stTransferLog TransferLogRecord) {
		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.Date;
		cout << "| " << setw(8) << left << TransferLogRecord.Acc1;
		cout << "| " << setw(8) << left << TransferLogRecord.Acc2;
		cout << "| " << setw(15) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.Bal1;
		cout << "| " << setw(10) << left << TransferLogRecord.Bal2;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;
	}
public:
	 static void ShowTransferLog() {
		vector<clsBankClient::stTransferLog>vtransfer = clsBankClient::LoadTransferLogScreen();
		string Ttile = "\t Transfer Log List Screen ";
		string SubTitle = "\t    (" + to_string(vtransfer.size()) + ") Client(s).";
		_DrawScreenHeader(Ttile,SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vtransfer.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else
			for (clsBankClient::stTransferLog Record : vtransfer)
			{

				_PrintCard(Record);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

