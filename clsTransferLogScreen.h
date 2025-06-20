#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:
    static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DataTime;
        cout << "| " << setw(20) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(20) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationBalance;
        cout << "| " << setw(20) << left << TransferLogRecord.UserName;
    }

public:
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTrnsferLogRecord> vTransferLog = clsBankClient::GetTransfersLogList();

        _DrawScreenHeader("\tTransfer Log Screen", "\t\t(" + to_string(vTransferLog.size()) + ") Record(s).");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(20) << "S. Account";
        cout << "| " << left << setw(20) << "D. Account";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S. Balance";
        cout << "| " << left << setw(10) << "D. Balance";
        cout << "| " << left << setw(20) << "User Name";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n";

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else
            for (clsBankClient::stTrnsferLogRecord Record : vTransferLog)
            {
                PrintTransferLogRecordLine(Record);
				cout << endl;
            }

        cout << setw(8) << left << "";
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n";
    }

};
