#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "clsDate.h"
using namespace std;
class clsUtil
{
public:
	enum enCharType {
		SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChar = 4, Spectialchar = 5
	};
	static void Srand() {
		srand(time(NULL));
	}
	static int RandomNumber(int From, int To) {
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	static char GetRandomCharacter(enCharType CharType) {
		if (CharType == MixChar) {
			CharType = (enCharType)RandomNumber(1, 3);
		}
		switch (CharType) {
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;
		case enCharType::Spectialchar:
			return char(RandomNumber(33, 47));
			break;
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
			break;
		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}
	static string GenerateWord(int length, enCharType CharType) {
		string word = "";
		for (int i = 0; i < length; i++) {
			word += GetRandomCharacter(CharType);
		}
		return word;
	}
	static string  GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";
		Key = GenerateWord(4, CharType) + "-";
		Key = Key + GenerateWord(4, CharType) + "-";
		Key = Key + GenerateWord(4, CharType) + "-";
		Key = Key + GenerateWord(4, CharType);
		return Key;
	}
	static void GenerateKeys(int length, enCharType CharType = CapitalLetter) {
		for (int i = 1; i <= length; i++) {
			cout << "Key[" << i << "] : " << GenerateKey(CharType) << "\n";
		}
	}
	static void Swap(int& Num1, int& Num2) {
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	static void Swap(double& Num1, double& Num2) {
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	static void Swap(string& S1, string& S2) {
		string Temp;
		Temp = S1;
		S1 = S2;
		S2 = Temp;
	}
	static void Swap(clsDate& Date1, clsDate& Date2) {
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}
	static  void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static  void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static void FillArrayWithRandomNumbers(int arr[100], int arrLenght, int From, int To) {
		for (int i = 0; i < arrLenght; i++) {
			arr[i] = RandomNumber(From, To);
		}
	}
	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, int To) {
		for (int i = 0; i < arrLength; i++) {
			arr[i] = GenerateWord(To, CharType);
		}
	}
	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType) {
		for (int i = 0; i < arrLength; i++) {
			arr[i] = GenerateKey(CharType);
		}
	}
	static string Taps(int size) {
		string s = "";
		for (int i = 0; i < size; i++) {
			s = s + "\t";
		}
		return s;
	}
	static string  EncryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string  DecryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}
	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return  arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}
};

