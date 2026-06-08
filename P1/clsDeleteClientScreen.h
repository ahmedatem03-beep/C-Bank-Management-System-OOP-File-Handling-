#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsDeleteClientScreen :clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "________________________________________\n";
		cout << "FirstName     : " << Client.FirstName << endl;
		cout << "LastName      : " << Client.LastName << endl;
		cout << "Full Name     : " << Client.FullName() << endl;
		cout << "Email         : " << Client.Email << endl;
		cout << "Phone         : " << Client.Phone << endl;
		cout << "AccountNumber : " << Client.AccountNumber() << endl;
		cout << "Password      : " << Client.PinCode << endl;
		cout << "AccountBalance: " << Client.AccountBalance << endl;
		cout << "\________________________________________\n";
	}
public:
	

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";
		cout << "\nPleas Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "Are you sure uoy want to delete this client y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer=='y'))
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfuly :-)\n";
				
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError Client is not deleted.\n";
			}
		}

	}

};

