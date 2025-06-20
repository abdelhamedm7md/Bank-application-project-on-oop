#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void setFirstName(string FirstName) { _FirstName = FirstName; }
	string FirstName() { return _FirstName; }
	///__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName) { _LastName = LastName; }
	string LastName() { return _LastName; }
	///__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetEmail(string Email) { _Email = Email; }
	string Email() { return _Email; }
	//__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void setPhone(string Phone) { _Phone = Phone; }
	string Phone() { return _Phone; }
	///__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";

	}




};

