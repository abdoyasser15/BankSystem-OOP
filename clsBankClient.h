#pragma once
#include <iostream>
#include "clsPerson.h"
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;
class clsBankClient:public clsPerson
{
private:
	enum enMode{EmptyMode = 0 , UpdateMode = 1,AddNewMode=2};
	
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete=0;
	static clsBankClient _ConvertLineToClientObject(string Line , string separetor = "#//#") {
		vector<string>vstring = clsString::Split(Line,separetor);
		return clsBankClient(enMode::UpdateMode, vstring[0], vstring[1], vstring[2], vstring[3], vstring[4], vstring[5],stod(vstring[6]));
	}
	static clsBankClient _GetEmptyClientObject() 
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static string _ConvertClientObjectTOLine(clsBankClient Client, string separetor = "#//#") {
		string Line="";
		Line += Client.firstName+separetor;
		Line += Client.lastName + separetor;
		Line += Client.email + separetor;
		Line += Client.phone + separetor;
		Line += Client.GetAccountNumber()+ separetor;
		Line += Client.PinCode + separetor;
		Line += to_string(Client.AccountBalance);
		return Line;
	}
	static vector<clsBankClient>_LoadClientDataFromFile() {
		vector<clsBankClient>vClient;
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);//read Mode
			if (MyFile.is_open()) {
				string Line;
				while (getline(MyFile,Line)) {
					clsBankClient Client = _ConvertLineToClientObject(Line);
					vClient.push_back(Client);
				}
				MyFile.close();
			}
			return vClient;
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectTOLine(*this));
	}
	void _AddDataLineToFile(string Line) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}
	}
	static void _SaveClientDataToFile(vector<clsBankClient>vClients) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::out);
		if (MyFile.is_open()) {
			string Line;
			for (clsBankClient C:vClients) {
				if (C._MarkForDelete==0) {
					Line = _ConvertClientObjectTOLine(C);
					MyFile << Line << "\n";
				}
			}
			MyFile.close();
		}
	}
	void _Update() {
		vector<clsBankClient>_vClient = _LoadClientDataFromFile();
		for (clsBankClient &Client : _vClient) {
			if (Client.GetAccountNumber() == GetAccountNumber()) {
				Client = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClient);
	}
	string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeToString() + Seperator;
		TransferLogRecord += _AccountNumber + Seperator;
		TransferLogRecord += DestinationClient.GetAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	} 
	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	
public:
	 struct stTransferLog {
		string Date;
		string Acc1;
		string Acc2;
		string Amount;
		double Bal1;
		double Bal2;
		string UserName;
	};
	static stTransferLog Transfer(string Line, string separetor = "#//#") {
		stTransferLog t;
		vector<string>vstring = clsString::Split(Line, separetor);
		t.Date = vstring[0];
		t.Acc1 = vstring[1];
		t.Acc2 = vstring[2];
		t.Amount = vstring[3];
		t.Bal1 = stod(vstring[4]);
		t.Bal2 = stod(vstring[5]);
		t.UserName = vstring[6];
		return t;
	}
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone,string AccountNumber,string PinCode,float AccountBalance)
		:clsPerson(FirstName, LastName,Email,Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
	}
	bool IsEmpty() {
		return(_Mode == enMode::EmptyMode);
	}
	void setAccountNumber(string AccountNumber) {
		_AccountNumber = AccountNumber;
	}
	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	void setAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	string GetAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = setAccountNumber))string AccountNumber;
	string GetPintCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPintCode, put = setPinCode))string PinCode;
	double GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance))double AccountBalance;
	void Print() {
		cout << "\nClient Card:\n";
		cout << "_____________________________________\n";
		cout << "FirstName      : " << firstName << endl;
		cout << "LastName       : " << lastName << endl;
		cout << "FullName       : " << FullName() << endl;
		cout << "Email          : " << email << endl;
		cout << "Phone          : " << phone << endl;
		cout << "AccountNumber  : " << AccountNumber << endl;
		cout << "PinCode        : " << PinCode << endl;
		cout << "AccountBalance : " << AccountBalance << endl;
		cout << "____________________________________\n";
	}
	static clsBankClient Find(string accountNumber) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);//read Mode
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == accountNumber) {
					return Client;
					MyFile.close();
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string accountNumber,string pinCode) {
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);//read Mode
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetAccountNumber() == accountNumber && Client.PinCode == pinCode) {
					return Client;
					MyFile.close();
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string accounNumber) {
		clsBankClient Client = Find(accounNumber);
		return(!Client.IsEmpty());
	}
	enum enSaveResults{svFaildEmptyProject=0,svSucceeded=1, svFaildAccountNumberExists = 2};
	enSaveResults Save() {
		switch (_Mode) {
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyProject;
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(GetAccountNumber())) {
				return enSaveResults::svFaildAccountNumberExists;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}

		}

	}
	static clsBankClient GetAddNewClientObject(string accountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
	}
	bool Delete() {
		vector<clsBankClient>vClient = _LoadClientDataFromFile();
		for (clsBankClient &C:vClient) {
			if (C.GetAccountNumber()==GetAccountNumber()) {
				C._MarkForDelete = 1;
				break;
			}
		}
		_SaveClientDataToFile(vClient);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector<clsBankClient>GetClientList() {
		return _LoadClientDataFromFile();
	}
	static double GetTotalBalances() {
		vector<clsBankClient>vClients = _LoadClientDataFromFile();
		double Total = 0;
		for (clsBankClient C : vClients) {
			Total += C.AccountBalance;
		}
		return Total;
	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
	}
	bool Transfer(float Amount, clsBankClient& DestinationClient,string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}
	static vector<stTransferLog> LoadTransferLogScreen() {
		vector<stTransferLog>vTransfer;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode
		if (MyFile.is_open()){
			string Line;
			while (getline(MyFile, Line)) {
				stTransferLog t = Transfer(Line);
				vTransfer.push_back(t);
			}
			MyFile.close();
		}
		return vTransfer;
	}
};

