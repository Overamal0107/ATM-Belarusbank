#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <windows.h>
#include "client.h"

namespace Bank
{
    class bank
    {
    public:
        Account::Client::client* User;
        bank();
        ~bank();
        void Menu();
        //private:  
    };
    bank::bank()
    {
        User = new Account::Client::client;
        User->New->Open_account();
    }
    bank:: ~bank()
    {
        delete User;
    }
    void bank::Menu()
    {

        Sleep(1000);
        int key;

        while (1)
        {
            bool OK = 1;
            system("CLS");

          
            cout << "\t\t\t\t\t\t\t�����������" << endl;
            cout << "\n" << " ���� �����:" << "\n";
            float BYN_RUB_kurs = 3.3000;
            cout << " RUB kurs:" << BYN_RUB_kurs << "\n";
            float BYN_USD_kurs = 2.3700;
            cout << " USD kurs:" << BYN_USD_kurs << "\n";
            float BYN_EU_kurs = 2.2700;
            cout << "" << " EUR kurs:" << BYN_EU_kurs << "\n";

            cout << "\n" << " ��������, �������� " << endl;
            cout << " 1: ������� " << endl  << " 2: ������ ��������  " << endl << " 3: ����� ��������   " << endl << " 4: ����� " << endl;
            cin >> key;
            while ((key < 0) || (key >= 5))
                cin >> key;

            switch (key)
            {
            case 1:

                system("CLS");
                User->New->Show_info();
                cout << " �� ������ ��������� � ���� ? \t 1: ����;\t2: ����� " << endl;

                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    { 
                        cout << " �������� ��� " << endl;
                        exit(0);
                    }
                    else
                        cout << " ������/���������� ��� ���" << endl;
                }
                break;
         
            case 2:
                cout << " ������ ��������  " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << " � ��� ������������ �����, ����� ����� �������� ." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << " ������ � ���   " << User->New->Work_with_money() << " �� ����� ����� " << endl;
                cout << " �� ������ ��������� � ����? \t 1: ���� ;\t2: ����� " << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << " �������� ��� " << endl;
                        exit(0);
                    }
                    else
                        cout << " ������/���������� ��� ��� " << endl;
                }
                break;
            case 3:
                cout << " ������� �� ������ ��������� �� ��������� ���� ? " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << "� ��� ������������ �����, ����� ��������." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << " ������ ���������  \n "  << endl;
                cout << " �� ������ ��������� � ����? \t 1: ���� ;\t2: ����� " << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << " �������� ��� " << endl;
                        exit(0);
                    }
                    else
                        cout << " ������/���������� ��� ��� " << endl;
                }
                break;
            case 4:
                cout << " �������� ��� " << endl;
                exit(0);
                break;
            }
        }
    }
}

