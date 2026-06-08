#pragma once

#include <iostream>
#include <iomanip>

#include "clsUser.h"
#include "clsScreen.h"


class clstListUsersScreen:protected clsScreen
{
private:
	static void _PrintUsersRecordLien(clsUser User)
	{
		cout << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(25) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}

public:
	static void ShowUsersList()
	{
		vector<clsUser> vUser = clsUser::GetUsersList();

		string Title = "\tUser List Screen";
		string SubTitle = "\t   (" + to_string(vUser.size()) + ") User(s)";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_____________________________________________________________________________________________________\n\n";

		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Perimissin";
		cout << "\n_____________________________________________________________________________________________________\n\n";

		if (vUser.size() == 0)
			cout << "\t\t\t\tNo User available in the system!";
		else
		{
			for (clsUser& User : vUser)
			{
				_PrintUsersRecordLien(User);
				cout << endl;
			}
		}

		cout << "\n_____________________________________________________________________________________________________\n\n";
	}
};

