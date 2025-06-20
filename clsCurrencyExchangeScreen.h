#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrenciesMainMenueOptions
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4,
        eMainMenue = 5
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return choice;
    }


    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
		_GoBackToMainMenue();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
        _GoBackToMainMenue();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
        _GoBackToMainMenue();
    }


    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
        _GoBackToMainMenue();
    }


    static void _PerformCurrencyExchangeOperation(enCurrenciesMainMenueOptions Option)
    {
        switch (Option)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
            _ShowListCurrenciesScreen();
            break;

        case enCurrenciesMainMenueOptions::eFindCurrency:
            _ShowFindCurrencyScreen();
            break;

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
            _ShowUpdateCurrencyRateScreen();
            break;

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
            _ShowCurrencyCalculatorScreen();
            break;

        case enCurrenciesMainMenueOptions::eMainMenue:
            break;
        }
    }
public:
    static void ShowCurrencyExchangeScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencys))
        {
            return;
        }
        system("cls");
        clsScreen::_DrawScreenHeader("\t\tCurrency Exchange Main Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyExchangeOperation((enCurrenciesMainMenueOptions)_ReadMainMenueOption());
    }
};
