#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsDate
{
private:
	int Day;
	int Month;
	int Year;
public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
	}
	clsDate(string Date) {
		vector<string>vstring = SplitString(Date);
		Day = stoi(vstring[0]);
		Month = stoi(vstring[1]);
		Year = stoi(vstring[2]);
	}
	clsDate(int Day, int Month, int Year) {
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
	clsDate(int TotalDays, int year) {
		clsDate Date = GetDateFromDayOrderInYear(TotalDays, year);
		Day = Date.Day;
		Month = Date.Month;
		Year = Date.Year;
	}
	void SetDay(int Day) {
		this->Day = Day;
	}
	void SetMonth(int Month) {
		this->Month = Month;
	}
	void SetYear(int Year) {
		this->Year = Year;
	}
	int day() {
		return Day;
	}
	int month() {
		return Month;
	}
	int year() {
		return Year;
	}
	__declspec(property(get = day, put = SetDay))int _Day;
	__declspec(property(get = month, put = SetMonth))int _Month;
	__declspec(property(get = year, put = SetYear))int _Year;
	vector<string>SplitString(string s1, string Delim = "/") {
		vector<string>vstring;
		short pos = 0;
		string sword = "";
		while ((pos = s1.find(Delim)) != std::string::npos) {
			sword = s1.substr(0, pos);
			if (sword != "") {
				vstring.push_back(sword);
			}
			s1.erase(0, pos + Delim.length());
		}
		if (s1 != "")vstring.push_back(s1);
		return vstring;
	}
	static bool IsLeapYear(int year) {
		return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
	}
	bool IsLeapYear() {
		return IsLeapYear(Year);
	}
	static short NumberOfDaysInMonth(int month, int year) {
		if (month < 1 || month>12)return 0;
		int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arr[month - 1];
	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(Month, Year);
	}
	static bool IsLastDayInMonth(clsDate Date) {
		return(Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
	}
	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}
	static bool IsLastMonthInYear(int month) {
		return(month == 12);
	}
	bool IsLastMonthInYear() {
		return IsLastMonthInYear(Month);
	}
	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.Year = year;
		Date.Month = 1;
		while (true) {
			MonthDays = NumberOfDaysInMonth(Date.Month, year);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	static short GetDayOrder(int Year, int Month, int Day) {
		int a = (14 - Month) / 12;
		int Y = Year - a;
		int M = Month - (12 * a) - 2;
		int d = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
		return d;
	}
	short GetDayOrder() {
		return GetDayOrder(Year, Month, 1);
	}
	static string GetMonth(int month) {
		string Month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return Month[month - 1];
	}
	string GetMonth() {
		return GetMonth(Month);
	}
	static void PrintMonthCalender(short month, short year) {
		cout << "\n ________________" << GetMonth(month) << "________________\n\n";
		cout << "  Sat  Mon  Tue  Wed  Thu  Fri  Sat \n";
		short current = GetDayOrder(year, month, 1);
		int i;
		for (i = 0; i < current; i++) {
			printf("     ");
		}
		short NumberOfDays = NumberOfDaysInMonth(month, year);
		for (int j = 1; j <= NumberOfDays; j++) {
			printf("%5d", j);
			if (++i == 7) {
				cout << endl;
				i = 0;
			}
		}
		printf("\n ___________________________________\n");
	}
	void PrintMonthCalender() {
		return PrintMonthCalender(Month, Year);
	}
	static  void PrintYearCalender(int year) {
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", year);
		printf("  _________________________________\n");
		for (int i = 1; i <= 12; i++) {
			PrintMonthCalender(i, year);
		}
	}
	void PrintYearCalender() {
		PrintYearCalender(Year);
	}
	static bool IsValidDate(clsDate Date)
	{

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > DaysInMonth)
			return false;

		return true;
	}
	bool IsValidDate() {
		return IsValidDate(*this);
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDateBeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
		return  (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day : false)) : false);
	}
	bool IsDateAfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return  IsDate1EqualDate2(*this, Date2);
	}

	static clsDate IncreaseDayByOne(clsDate Date) {
		if (IsLastDayInMonth(Date)) {
			if (IsLastMonthInYear(Date.Month)) {
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}
		}
		else {
			Date.Day++;
		}
		return Date;
	}
	void IncreaseDayByOne() {
		*this = IncreaseDayByOne(*this);
	}
	static void SwapDates(clsDate& Date1, clsDate& Date2) {
		clsDate temp;
		temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}
	static int GetDiffrenceInDays(clsDate Date1, clsDate Date2) {
		int Days = 0;
		if (!IsDate1BeforeDate2(Date1, Date2)) {
			SwapDates(Date1, Date2);
		}
		while (IsDate1BeforeDate2(Date1, Date2)) {
			Days++;
			Date1 = IncreaseDayByOne(Date1);
		}
		return Days;
	}
	int GetDiffrenceInDays(clsDate Date2) {
		return GetDiffrenceInDays(*this, Date2);
	}
	static short CalculateMyAgeInDays(clsDate DateOfBirth) {
		return GetDiffrenceInDays(DateOfBirth, clsDate::GetSystemDate());
	}
	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Day, Month, Year);
	}
	static string GetSystemDateTimeToString() {
		time_t t = time(0);
		tm* now = localtime(&t);
		time_t curr_time;
		curr_time = time(NULL);
		tm* tm_local = localtime(&curr_time);
		short Day, Month, Year,Hour,Minute,Second;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = tm_local->tm_hour;
		Minute = tm_local->tm_min;
		Second = tm_local->tm_sec;
		return to_string(Day) + '/' + to_string(Month) + '/' + to_string(Year) + " - " + to_string(Hour) + ':' + to_string(Minute) + ':' + to_string(Second);
	}
	static string DateToString(clsDate Date) {
		return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);
	}
	string DateToString() {
		return DateToString(*this);
	}
	static int GetTotlalDays(clsDate Date) {
		int TotalDays = 0;
		for (int i = 1; i <= Date.Month - 1; i++) {
			TotalDays += NumberOfDaysInMonth(i, Date.Year);
		}
		TotalDays += Date.Day;
		return TotalDays;
	}
	int GetTotlalDays() {
		return GetTotlalDays(*this);
	}
	static clsDate IncreaseDateByXDays(int x, clsDate& Date) {
		short RemainingDays = x + GetTotlalDays(Date);
		short MonthDays = 0;
		Date.Month = 1;
		while (true) {
			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12) {
					Date.Month = 1;
					Date.Year++;
				}
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	void IncreaseDateByXDays(int x) {
		IncreaseDateByXDays(x, *this);
	}
	static clsDate IncreaseDateByOneWeek(clsDate& Date) {
		Date = IncreaseDateByXDays(7, Date);
		return Date;
	}
	void IncreaseDateByOneWeek() {
		IncreaseDateByOneWeek(*this);
	}
	static clsDate IncreaseDateByXWeek(int x, clsDate& Date) {
		while (x--) {
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeek(int x) {
		IncreaseDateByXWeek(x, *this);
	}
	static clsDate IncreaseDateByXMonth(int x, clsDate& Date) {
		while (x--) {
			Date.Month++;
			if (Date.Month > 12) {
				Date.Month = 1;
			}
		}
		return Date;
	}
	void IncreaseDateByXMonth(int x) {
		IncreaseDateByXMonth(x, *this);
	}
	static clsDate IncreaseDateByXYear(int x, clsDate& Date) {
		while (x--) {
			Date.Year++;
		}
		return Date;
	}
	void IncreaseDateByXYear(int x) {
		IncreaseDateByXYear(x, *this);
	}
	static clsDate IncreaseXDecade(int x, clsDate& Date) {
		IncreaseDateByXYear(x * 10, Date);
		return Date;
	}
	void IncreaseXDecade(int x) {
		IncreaseXDecade(x, *this);
	}
	static clsDate IncreaseXCentury(int x, clsDate& Date) {
		IncreaseDateByXYear(x * 100, Date);
		return Date;
	}
	void IncreaseXCentury(int x) {
		IncreaseXCentury(x, *this);
	}
	static clsDate IncreaseXMillennium(int x, clsDate& Date) {
		IncreaseDateByXYear(x * 1000, Date);
		return Date;
	}
	void IncreaseXMillennium(int x) {
		IncreaseXMillennium(x * 1000, *this);
	}
	static clsDate DecreaseDateByOneDay(clsDate& Date) {
		if (Date.Day == 1) {
			if (Date.Month == 1) {
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else {
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}
		else {
			Date.Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay() {
		DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByXDays(int x, clsDate& Date) {
		while (x--) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(int x) {
		DecreaseDateByXDays(x, *this);
	}
	static clsDate DecreaseDateByOneWeek(clsDate& Date) {
		Date = DecreaseDateByXDays(7, Date);
		return Date;
	}
	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}
	static clsDate DecreaseDateByXWeek(int x, clsDate& Date) {
		while (x--) {
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeek(int x) {
		DecreaseDateByXWeek(x, *this);
	}
	static clsDate DecreaseDateByXYear(int x, clsDate& Date) {
		Date.Year += x;
		return Date;
	}
	void DecreaseDateByXYear(int x) {
		DecreaseDateByXYear(x, *this);
	}
	static clsDate DecreaseDateByXDecade(int x, clsDate& Date) {
		DecreaseDateByXYear(x * 10, Date);
		return Date;
	}
	void DecreaseDateByXDecade(int x) {
		DecreaseDateByXDecade(x, *this);
	}
	static clsDate DecreaseDateByXCentury(int x, clsDate& Date) {
		DecreaseDateByXYear(x * 100, Date);
		return Date;
	}
	void DecreaseDateByXCentury(int x) {
		DecreaseDateByXCentury(x, *this);
	}
	static clsDate DecreaseDateByXMillennium(int x, clsDate& Date) {
		DecreaseDateByXYear(x * 1000, Date);
		return Date;
	}
	void DecreaseDateByXMillennium(int x) {
		DecreaseDateByXMillennium(x, *this);
	}
	static bool IsEndOfWeek(clsDate Date) {
		return (GetDayOrder(Date.Year, Date.Month, Date.Day) == 6);
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}
	static bool IsBussinessDay(clsDate Date) {
		return (GetDayOrder(Date.Year, Date.Month, Date.Day) != 6 || GetDayOrder(Date.Year, Date.Month, Date.Day) != 5);
	}
	bool IsBussinessDay() {
		return IsBussinessDay(*this);
	}
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - GetDayOrder(Date.Day, Date.Month, Date.Year);
	}
	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{

		clsDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;
		return GetDiffrenceInDays(Date1, EndOfMontDate);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;
		return GetDiffrenceInDays(Date1, EndOfYearDate);
	}
	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBussinessDay(DateFrom))
				Days++;

			DateFrom = IncreaseDayByOne(DateFrom);
		}
		return Days;
	}
	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}
	void Print() {
		cout << Day << '/' << Month << '/' << Year << "\n\n";
	}
};

