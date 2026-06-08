#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsWithdrawScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadDoubleNumber();
	}
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t  Withdraw Screen");

		string AccountNumber = "";
		cout << "\nPleas Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\nClient with [" << AccountNumber << "] does not exist.\n";
			cout << "\nPleas Enter Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);


		cout << "\n\nPleas Enter Withdraw Amount: ";
		double Amount = clsInputValidate::ReadDoubleNumber();

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this transaction? y/n: ";
		cin >> Answer;

		if (toupper(Answer == 'y'))
		{

			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client1.AccountBalance;

			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

