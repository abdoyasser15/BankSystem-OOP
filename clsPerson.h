#pragma once
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include "InterfaceCommunication.h"
class clsPerson:public InterfaceCommunication
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson(string FirstName,string LastName,string Email,string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	void setLastName(string LastName) {
		_LastName = LastName;
	}
	void setEmail(string Email) {
		_Email = Email;
	}
	void setPhone(string Phone) {
		_Phone = Phone;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = setFirstName))string firstName;
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = setLastName))string lastName;
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = setEmail))string email;
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = setPhone))string phone;
	string FullName() {
		return _FirstName + " " + _LastName;
	}
	void SendEmail(string Title, string Body) {

	};
	void SendFax(string Title, string Body) {

	};
	void SendSMS( string Title,string Body) {

	};
};
