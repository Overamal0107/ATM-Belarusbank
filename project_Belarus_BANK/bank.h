#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <map>
#include <string>
#include <iomanip>
#include "account.h"
#include "client.h"
#include<functional>
#include <wincrypt.h>

const double DOLLAR = 2.3700;
const double EUROS = 2.2700;
const double RUBL = 3.3000;


namespace Bank
{


    class bank
    {
    public:

        Account::Client::client* User;
        bank();
        ~bank();
        void Menu();
        void currency();


    };  //class bank 
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
        int equivD = 0;
        double equivE = 0.0;
        int IDbankomat = 198547;
        int telefon;
        double rand = 0.0;
        long  check;
        long money;
        while (1)
        {
            bool OK = 1;
            system("CLS");


            cout << " ����������� " << endl;
            cout << "\n" << " ���� �����:" << "\n";
            double BYN_RUB_kurs = 3.3000;
            cout << "\n RUB kurs:" << BYN_RUB_kurs << "\n";
            double BYN_USD_kurs = 2.3700;
            cout << " USD kurs:" << BYN_USD_kurs << "\n";
            double BYN_EU_kurs = 2.2700;
            cout << "" << " EUR kurs:" << BYN_EU_kurs << "\n";

            cout << "\n" << " ��������, �������� " << endl;
            cout << " 1: ������� " << endl << " 2: ������ ��������  " << endl << " 3: ����� ��������   " << endl << " 4: ������ �� ����� " << endl << " 5: ����� " << endl;
            cin >> key;
            while ((key < 0) || (key >= 6))
                cin >> key;

            switch (key)

            {
            case 1: // ������� 

                system("CLS");
                User->New->Show_info();
                cout << "�� ������ ��������� � ���� ? \n\t\n 1: ����;\t\n 2: �����" << endl;

                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }
                break;

            case 2: // �������/���������� ����� ������ �������, � ������� �������� ����� �������� �������� ������
                currency();
            case 3: // ������ �������� 
                cout << "����� �������� : " << endl;
                cin >> telefon;
                cout << "������� �� ������ ��������� �� ��������� ���� ?" << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << "� ��� ������������ �����, ����� ��������." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << "������ ���������  \n" << endl;
                cout << "�� ������ ��������� � ���� ? \n\t\n 1: ����; \t\n 2: �����" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }
                break;

            case 4:
                       /* ���������� ������ �����������, ����� ������� �������� �������� ������������.
                       ��������, �������� ����������� ����� �1, � ���������� �������� ����������� ����� �2,
                       �� ����� ���������� �� �1 � �2, ����� ������� ������ ����� ���� �3*/

                cout << "\nID ��������� ����������� [" << IDbankomat << "]" << endl;
                cout << "���� :" << User->New->user_account << endl;
                cout << "\n�� ����� ���� ������ ��������� ������ :" << endl;
                cin >> check;
                cout << "����� ����� ���� ������ ��������� �������? \n\t\n 1: ��������� \t\n 2: �������������" << endl;
                while (OK)
                {
                    cin >> key;
                    if (money == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (money == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }
                cin>>IDbankomat;
                cout << "\n����� ����� ������ ���������" << endl;
                cin >> money;
                if (User->New->Work_with_money() < money)
                {
                    cout << "� ��� ������������ �����, ��������� ������� ." << endl;

                    Sleep(1000);

                    continue;
                }
                else User->New->Work_with_money(money);

                cout << "������ � ��� " << User->New->Work_with_money() << "BYN �� ����� �����" << endl;

                cout << "�� ������ ��������� � ����? \n\t\n 1: ���� ;\t\n 2: �����" << endl;
                while (OK)
                {
                    cin >> key;
                    if (money == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (money == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }
                break;
            case 5: // ����� 
                cout << "�������� ���" << endl;
                exit(0);
                break;
            }
        }

    }// bank Menu

    void bank::currency()

    {

        Sleep(1000);

        int key;
        int equivD;
        double equivE = 0.0;
        double rand;
        while (1)
        {
            bool OK = 1;
            system("CLS");

            cout << " 1: BYN " << endl << " 2: USD  " << endl << " 3: EUR  " << endl << " 4: RUB  " << endl;
            cout << "\n�� ������ ��������� � ����? \n\t\n 1: ���� \t\n 2: �����" << endl;
            while (OK)
            {
                cin >> key;
                if (key == 1) {
                    OK = 0;
                    continue;
                }
                else if (key == 2)
                {
                    cout << "�������� ���" << endl;
                    exit(0);
                }
                else
                    cout << "������/���������� ��� ���" << endl;
            }
            cin >> key;
            while ((key < 0) || (key >= 5))
                cin >> key;

            switch (key)
            {
                break;
            case 1:
            {
                cout << "������ �������� " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << "� ��� ������������ �����, ����� ����� �������� ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(key);
                cout << "������ � ��� " << User->New->Work_with_money() << " �� ����� �����" << endl;
                cout << "�� ������ ��������� � ����? \n\t\n 1: ���� \t\n 2: �����" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }

                break;
            case 2:

            {
                cout << setprecision(2) << fixed;
                cout << "������� USD ������ �������� ?: ";
                cin >> rand;
                cout << rand << " USD(s)= ";
                equivD = (rand * DOLLAR);
                cout << equivD << " BYN(s)\n ";
                if (User->New->Work_with_money() < equivD)
                {
                    cout << "� ��� ������������ �����, ����� ����� �������� ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(equivD);
                cout << "������ � ��� " << User->New->Work_with_money() << " BYN �� ����� �����" << endl;

                cout << "�� ������ ��������� � ����? \n\t\n 1: ���� \t\n 2: �����" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }

            }
            break;

            case 3:
            {
                cout << setprecision(2) << fixed;
                cout << "������� EUR ������ �������� ?: ";
                cin >> rand;
                cout << rand << " EUR(s)= ";
                equivD = (rand * EUROS);
                cout << equivD << " BYN(s)\n ";
                if (User->New->Work_with_money() < equivD)
                {
                    cout << "� ��� ������������ �����, ����� ����� �������� ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(equivD);
                cout << "������ � ��� " << User->New->Work_with_money() << "BYN �� ����� �����" << endl;

                cout << "�� ������ ��������� � ����? \n\t\n 1: ���� \t\n 2: �����" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }
            }
            break;

            case 4:
            {
                cout << setprecision(2) << fixed;
                cout << "������� RUB ������ �������� ?: ";
                cin >> rand;
                cout << rand << " RUB(s)= ";
                equivD = (rand * RUBL);
                cout << equivD << " BYN(s)\n ";
                if (User->New->Work_with_money() < equivD)
                {
                    cout << "� ��� ������������ �����, ����� ����� �������� ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(equivD);
                cout << "������ � ��� " << User->New->Work_with_money() << "BYN �� ����� �����" << endl;

                cout << "�� ������ ��������� � ����? \n\t\n 1: ���� \t\n 2: �����" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "�������� ���" << endl;
                        exit(0);
                    }
                    else
                        cout << "������/���������� ��� ���" << endl;
                }


            }

            }
            }



        }


    }// void::bank::currenty()
}// namespace Bank

