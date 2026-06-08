#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsDelteUserScreen:protected clsScreen
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

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen");

		cout << "\nPleas Enter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, Choos another one: ";
			UserName = clsInputValidate::ReadString();
		}
		
		clsUser User1 = clsUser::Find(UserName);
		_PrintUsers(User1);

		char Answer = 'n';
		cout << "\nAre you sure you want yo delete this user?  y/n? ";
		cin >> Answer;

		if (toupper(Answer == 'y'))
		{
			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfilly :-)\n";
				_PrintUsers(User1);
			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
			
		}

	}


};

