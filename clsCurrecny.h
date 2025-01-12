#pragma once
#include <iostream>
using namespace std;
#include "clsString.h"
#include <vector>
#include <fstream>
#include <string>
class clsCurrecny
{
private:
	enum enMode{EmptyMode = 0, Updatemode = 1};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrecny _ConvertLineToCurencyobject(string Line , string Separetor="#//#") {
		vector<string> vstring = clsString::Split(Line, Separetor);
		return clsCurrecny(enMode::Updatemode, vstring[0], vstring[1], vstring[2],stof(vstring[3]));
	}
	static string _ConvertCurrencyObjectToLine(clsCurrecny Curr,string Separetor = "#//#") {
		string Line = "";
		Line += Curr._Country + Separetor;
		Line += Curr._CurrencyCode + Separetor;
		Line += Curr._CurrencyName + Separetor;
		Line += to_string(Curr._Rate);
		return Line;
	}
	static vector<clsCurrecny> _LoadCurrencyDataFromFile() {
		vector<clsCurrecny>vCurrent;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line="";
			while (getline(MyFile,Line)) {
				clsCurrecny Curr = _ConvertLineToCurencyobject(Line);
				vCurrent.push_back(Curr);
			}
			MyFile.close();
		}
		return vCurrent;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrecny>vCurrent) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open()) {
			string Line = "";
			for (clsCurrecny C : vCurrent) {
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}
	void _Update() {
		vector<clsCurrecny>vCurrent = _LoadCurrencyDataFromFile();
		for (clsCurrecny &C : vCurrent) {
			if (C._CurrencyCode == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrent);
	}
	static clsCurrecny _GetEmptyCurrentObject() {
		return clsCurrecny(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrecny(enMode Mode,string Country,string CurrencyCode,string Currencyname,float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = Currencyname;
		_Rate = Rate;
	}
	bool Is_Empty() {
		return (enMode::EmptyMode == _Mode);
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}
	static clsCurrecny FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile,Line)) {
				clsCurrecny Curr = _ConvertLineToCurencyobject(Line);
				if (Curr.CurrencyCode() == CurrencyCode) {
					MyFile.close();
					return Curr;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrentObject();
	}
	static clsCurrecny FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrecny Currency = _ConvertLineToCurencyobject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrentObject();
	}
	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrecny C1 = clsCurrecny::FindByCode(CurrencyCode);
		return (!C1.Is_Empty());
	}
	static vector <clsCurrecny> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
};

