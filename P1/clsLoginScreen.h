#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen:protected clsScreen
{

private:
	static bool _Login()
	{
		bool LoginFiald = false;
		string UserName, Password;
		short FialdLoginCount = 0;
		do
		{
			
			if (LoginFiald)
			{
				FialdLoginCount++;
				cout << "\nInvlaid UserName/Password!\n";
				cout << "You have " << (3 - FialdLoginCount)
					<< " trials to login.\n\n";
			}
			if (FialdLoginCount == 3)
			{
				cout << "\nYou are locked after 3 faild trials.\n\n";
				return false;
			}

			cout << "\nEnter User Name: ";
			UserName = clsInputValidate::ReadString();
			cout << "Enter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFiald = CurrentUser.IsEmpty();
			

		} while (LoginFiald);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
	}


public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen");

		
	   return _Login();
	
		


	}



};

