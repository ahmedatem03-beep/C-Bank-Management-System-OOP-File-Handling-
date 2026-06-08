#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen :protected clsScreen
{

private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName:";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName:";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email:";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone:";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password:";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission:";
		User.Permissions = _ReadPermissionsToSet();

	}

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

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want to give fill access? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n";

		cout << "Show Client List? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pListClient;
		}

		cout << "Add New Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "Delete Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "Update Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "Find Client? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "Transactions? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "Manage User? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			 Permissions += clsUser::enPermissions::pManageUser;
		}

		cout << "Show Login Register? y/n? ";
		cin >> Answer;
		if (toupper(Answer == 'y'))
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return Permissions;
	}


public:

	static void ShowAddNewUserList()
	{
		_DrawScreenHeader("\tAdd New User List");

		cout << "\nPleas Enter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is Already Used, Choos Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(User1);

		clsUser::enSaveResults SaveResults;
		SaveResults = User1.Save();

		switch (SaveResults)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Aded Successfully :-)\n";
			_PrintUsers(User1);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError User not seved because it's empty!\n";
			break;
		}
		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError User not seved because User Name is Used!\n";
			break;
		}

		}

	}


};

