#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class FindClientScreen :protected clsScreen
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

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";
		cout << "\nPleas Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found!, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
	
		if (Client.IsEmpty())
			cout << "\nClient Found :-)\n";

		else
			cout << "\nClient is Not Found :-(\n";

		_PrintClient(Client);
	}
};

