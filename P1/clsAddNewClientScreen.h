#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;
class clsAddNewClientScreen:clsScreen
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



	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Add New Client Screen");
		string AccountNumber = "";
		cout << "\nPleas Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClient NewClient1 = clsBankClient::GedAddNewClientObject(AccountNumber);


		_ReadClientInfo(NewClient1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient1.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(NewClient1);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}

		}


	}

};

