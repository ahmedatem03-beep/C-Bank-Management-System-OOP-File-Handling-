#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsDepsitScreen:protected clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t  Deposit Screen");

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

		
		cout << "\n\nPleas Enter Deposit Amount: ";
		double Amount = clsInputValidate::ReadDoubleNumber();

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this transaction? y/n: ";
		cin >> Answer;

		if (toupper(Answer == 'y'))
		{
			
			Client1.Deposit(Amount);

			cout << "\nAccount Deposit Successfuly.\n";

			cout << "\n New Balance is: " << Client1.AccountBalance << endl;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}

};

