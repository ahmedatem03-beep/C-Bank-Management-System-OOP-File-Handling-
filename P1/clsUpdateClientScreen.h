#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateClientScreen:protected clsScreen
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
		cout << "________________________________________\n\n";
		cout << "FirstName     : " << Client.FirstName << endl;
		cout << "LastName      : " << Client.LastName << endl;
		cout << "Full Name     : " << Client.FullName() << endl;
		cout << "Email         : " << Client.Email << endl;
		cout << "Phone         : " << Client.Phone << endl;
		cout << "AccountNumber : " << Client.AccountNumber() << endl;
		cout << "Password      : " << Client.PinCode << endl;
		cout << "AccountBalance: " << Client.AccountBalance << endl;
		cout << "_________________________________________\n";
	}
public:

	static void ShowApdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber;
		cout << "\nPleas Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nAre you sure you want to update this client y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer == 'y'))
		{
			cout << "\n\nUpdate Client Info";
			cout << "\n_________________________\n";
			_ReadClientInfo(Client1);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client1.Save();

			switch (SaveResult)
			{
			case  clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClient(Client1);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}

			}
		}
	}
};

