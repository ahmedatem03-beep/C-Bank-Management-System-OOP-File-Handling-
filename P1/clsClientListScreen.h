#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"


class clsClientListScreen:protected clsScreen
{
private:
	static void _PrintClientRecordLien(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(25) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:
	static void ShowClientsList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClient))
		{
			return;// this will exit the function and it will not continue
		}


		vector<clsBankClient> vClient = clsBankClient::GetClientList();

		string Title = "\tClient List Screen";
		string SubTitle = "\t   (" + to_string(vClient.size()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);
		
		cout << "\n_____________________________________________________________________________________________________\n\n";

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_____________________________________________________________________________________________________\n\n";

		if (vClient.size() == 0)
			cout << "\t\t\t\tNo Client available in the system!";
		else
		{
			for (clsBankClient& Client : vClient)
			{
				_PrintClientRecordLien(Client);
				cout << endl;
			}
		}

		cout << "\n_____________________________________________________________________________________________________\n\n";
	}


};

