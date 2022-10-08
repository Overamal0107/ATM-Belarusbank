#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <windows.h>
#include "account.h"
namespace Account
{
    namespace Client
    {
        using namespace Account;

        class client
        {
        public:
            Bankomat::Account::account* New;
            char fio[50];
            char adress[50];
            char serial[50];
            char currency[1];
            client();
            ~client();



        };

        client::client()
        {
            New = new Bankomat::Account::account;
            cout << "Введите ваше имя и фамилию" << endl;
            cin.getline(fio, 50);
            cout << "Серия паспорта :" << endl;
            cin.getline(serial, 50);
            cout << "Введите свой адрес" << endl;
            cin.getline(adress, 50);
            cout << "Выберете валюту(US,EU,Rb,Br):" << endl;
            cin.getline(currency, 50);
            cout << "Счёт открыт!!!" << endl << endl;
        }

        client::~client()
        {
            delete New;
        }

    }
}