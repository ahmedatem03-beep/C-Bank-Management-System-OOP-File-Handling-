#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsFindUserScreen:protected clsScreen
{
private:
	static void _PrintUsers(clsUser User)
	{
		cout << "\nUser Card:\n";
		cout << "________________________________________\n";
		cout << "FirstName   : " << User.FirstName << endl;
		cout << "LastName    : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "User Name   : " << User.UserName << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "Permissions : " << User.Permissions << endl;
		cout << "\________________________________________\n";
	}

public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		cout << "\nPleas Enter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found, Choos Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}
		_PrintUsers(User1);

	}


};

