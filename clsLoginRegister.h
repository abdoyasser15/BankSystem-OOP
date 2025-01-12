#pragma once
#include <iostream>
#include "clsUser.h"
using namespace std;
class clsLoginRegister
{
private:
	static string _GetLocalTime() {
		time_t curr_time;
		curr_time = time(NULL);
		tm* tm_local = localtime(&curr_time);
		string s;
		s = to_string(tm_local->tm_hour)+':' + to_string(tm_local->tm_min) + ':' + to_string(tm_local->tm_sec);
		return s;
	}
public:
	static void ShowLocalTime() {
		cout<<_GetLocalTime();
	}
};

