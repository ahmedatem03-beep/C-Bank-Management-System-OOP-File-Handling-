#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDelteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUserMenue:protected clsScreen
{
private:
    enum enManageUserOptions
    {
        ListUsers = 1, AddNewUser = 2, DeletUser = 3, UpdateUser = 4, FindUser = 5, MainMenue = 6
    };

    static short _ReadMangeUserOption()
    {
        cout << "Choos what do you want to do? [1 to 6]: ";
        short Number = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Betwen 1 to 6: ");
        return Number;
    }

    static void _GoBackToManageUserMenue()
    {
        cout << "\n\tPress any key to go back to Manage User Menue...\n";
        system("pause>0");
        ShowMangeUserMenue();
    }


    static void _ShowLisUsersScreen()
    {
        clstListUsersScreen::ShowUsersList();
    }
    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserList();
    }
    static void _ShowDeleteUserScreen()
    {
        clsDelteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUserScreen()
    {
        clsApdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformManageUserOptions(enManageUserOptions ManageUserOption)
    {
        switch (ManageUserOption)
        {
        case enManageUserOptions::ListUsers:
        {
            system("cls");
            _ShowLisUsersScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserOptions::AddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserOptions::DeletUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserOptions::UpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserOptions::FindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUserOptions::MainMenue:
        {

        }

        }
    }

public:
	static void ShowMangeUserMenue()
	{
        

        if (!CheckAccessRights(clsUser::enPermissions::pManageUser))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\tManage User Screen");
        cout << "===========================================\n";
        cout << "\t\tManage User Menue\n";
        cout << "===========================================\n";
        cout << "\t[1] List User.\n";
        cout << "\t[2] Add New User.\n";
        cout << "\t[3] Delete User.\n";
        cout << "\t[4] Update User.\n";
        cout << "\t[5] Find User.\n";
        cout << "\t[6] Main Menue.\n";
        cout << "===========================================\n";
        _PerformManageUserOptions(enManageUserOptions(_ReadMangeUserOption()));
	}

};

