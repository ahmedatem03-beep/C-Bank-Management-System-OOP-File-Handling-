#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "InputEventFlags.h"

class clsTransfereScreen:protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "________________________________________\n";
		cout << "Full Name     : " << Client.FullName() << endl;
		cout << "AccountNumber : " << Client.AccountNumber() << endl;
		cout << "AccountBalance: " << Client.AccountBalance << endl;
		cout << "\________________________________________\n";
	}


	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}


	static double ReadAmount(clsBankClient SourceClient)
	{
		double Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadDoubleNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDoubleNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScren()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);



		
		double Amount = ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? y/n: ";
		cin >> Answer;

		if (toupper(Answer == 'y'))
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);



	}


};

