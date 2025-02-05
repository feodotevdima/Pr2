#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef BASECLASS_H
#define BASECLASS_H

class User
{
protected:

	string Name, Password;

public:

	User()
	{
		cout << "Введите Имя: ";
		cin >> Name;
		cout << "Введите Пароль: ";
		cin >> Password;
	}

	User(string name, string password)
	{
		Name = name;
		Password = password;
	}

	string GetName()
	{
		return Name;
	}
	void SetName(string name)
	{
		Name = name;
	}


	string GetPassword()
	{
		return Password;
	}
	void SetPassword(string password)
	{
		Password = password;
	}
};

#endif