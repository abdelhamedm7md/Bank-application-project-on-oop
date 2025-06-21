#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen : protected clsScreen
{

private:
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
        cout << "| " << left << setw(8) << Currency.CurrencyCode();
        cout << "| " << left << setw(45) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate();
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
            << endl;
     
    }

public:
    static void ShowCurrenciesListScreen()
    {
        system("cls");
        vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
            << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
            << endl;

        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\tNo Currencies Available In the System!";
        }
        else
        {
            for (clsCurrency Currency : vCurrencies)
            {
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
            << endl;
    }
};