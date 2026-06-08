#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalBalancesScreen:protected clsScreen
{

private:
	static void _PrintClientRecordLien(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:
	static void ShowClientsList()
	{
		vector<clsBankClient> vClient = clsBankClient::GetClientList();

		string Title = "\tBalances List Screen";
		string SubTitle = "\t   (" + to_string(vClient.size()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n____________________________________________________\n\n";

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n____________________________________________________\n\n";

		
		if (vClient.size() == 0)
			cout << "\t\t\t\tNo Client available in the system!";
		else
		{
			double Count = 0;
			for (clsBankClient& Client : vClient)
			{
				_PrintClientRecordLien(Client);
				cout << endl;
			}
		}

		cout << "\n____________________________________________________\n\n";

		double TotalBalance = clsBankClient::GetTotalBalances();
		cout << "\t\t\t\tTotal Balances is: " << TotalBalance << endl;

		cout << "\t\t\t" << clsUtil::NumberToText(TotalBalance) << endl;


	}


};


