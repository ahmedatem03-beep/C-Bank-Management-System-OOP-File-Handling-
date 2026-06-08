#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepsitScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransfereScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsMenue:protected clsScreen
{
private:
    enum enTransactionsOptions
    {
        Deposit = 1, Withdraw = 2, TotalBalance = 3, Transfere = 4, TransferLog = 5, MainMenue = 6
    };

    static short _ReadTransactionOption()
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        short Number = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Betwen 1 to 6: ");
        return Number;
        
    }

    static void _GoBackToTransactionMenue()
    {
        cout << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
        ShowTransactionsScreen();
    }
   
    static void _ShowDepositScreen()
    {
        clsDepsitScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalancesScreen::ShowClientsList();
    }

    static void _ShowTransferScreen()
    {
        clsTransfereScreen::ShowTransferScren();
    }
    
    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerformTransactionsOptions(enTransactionsOptions TransactionsOptions)
    {
        switch (TransactionsOptions)
        {
        case enTransactionsOptions::Deposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionsOptions::Withdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionsOptions::TotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionsOptions::Transfere:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionsOptions::TransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionsOptions::MainMenue:
        {
        }

        }
    }

public:
    
    static void ShowTransactionsScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t Transactions Screen");

        cout << "===========================================\n";
        cout << "\t\tTransactions Menue\n";
        cout << "===========================================\n";
        cout << "\t[1] Deposit.\n";
        cout << "\t[2] Withdraw.\n";
        cout << "\t[3] Total Balance.\n";
        cout << "\t[4] Transfere.\n";
        cout << "\t[5] Transfere Log.\n";
        cout << "\t[6] Main Menue.\n";
        cout << "===========================================\n";

        _PerformTransactionsOptions(enTransactionsOptions(_ReadTransactionOption()));

    }

    
};

