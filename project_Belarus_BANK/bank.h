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


            cout << " БЕЛАРУСБАНК " << endl;
            cout << "\n" << " Курс волют:" << "\n";
            double BYN_RUB_kurs = 3.3000;
            cout << "\n RUB kurs:" << BYN_RUB_kurs << "\n";
            double BYN_USD_kurs = 2.3700;
            cout << " USD kurs:" << BYN_USD_kurs << "\n";
            double BYN_EU_kurs = 2.2700;
            cout << "" << " EUR kurs:" << BYN_EU_kurs << "\n";

            cout << "\n" << " Выберите, операцию " << endl;
            cout << " 1: Остаток " << endl << " 2: Снятие наличных  " << endl << " 3: Олаты телефона   " << endl << " 4: Первод на карту " << endl << " 5: Выход " << endl;
            cin >> key;
            while ((key < 0) || (key >= 6))
                cin >> key;

            switch (key)

            {
            case 1: // Остаток 

                system("CLS");
                User->New->Show_info();
                cout << "Вы хотите вернуться в меню ? \n\t\n 1: Меню;\t\n 2: Выход" << endl;

                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }
                break;

            case 2: // Остаток/Добавление новой валюты банкнот, в которой банкомат может выдавать бумажные деньги
                currency();
            case 3: // Оплата телефона 
                cout << "Номер телефона : " << endl;
                cin >> telefon;
                cout << "Сколько вы хотите зачислить на мобильный счет ?" << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << "У вас недостаточно денег, чтобы оплатить." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << "Деньги зачислены  \n" << endl;
                cout << "Вы хотите вернуться в меню ? \n\t\n 1: Меню; \t\n 2: Выход" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }
                break;

            case 4:
                       /* Добавление банков посредников, через которые проходит операция пользователя.
                       Например, банкомат принадлежит банку Б1, а банковская карточка принадлежит банку Б2,
                       но чтобы обратиться из Б1 в Б2, нужно сделать запрос через банк Б3*/

                cout << "\nID Банкомата БеларусБанк [" << IDbankomat << "]" << endl;
                cout << "Счет :" << User->New->user_account << endl;
                cout << "\nНа какой счет хотите перевести деньги :" << endl;
                cin >> check;
                cout << "Через какой банк хотите совершить перевод? \n\t\n 1: Альфабанк \t\n 2: Белинвестбанк" << endl;
                while (OK)
                {
                    cin >> key;
                    if (money == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (money == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }
                cin>>IDbankomat;
                cout << "\nКакую сумму хотите перевести" << endl;
                cin >> money;
                if (User->New->Work_with_money() < money)
                {
                    cout << "У вас недостаточно денег, выполнить перевод ." << endl;

                    Sleep(1000);

                    continue;
                }
                else User->New->Work_with_money(money);

                cout << "Теперь у вас " << User->New->Work_with_money() << "BYN на вашем счету" << endl;

                cout << "Вы хотите вернуться в меню? \n\t\n 1: Меню ;\t\n 2: Выход" << endl;
                while (OK)
                {
                    cin >> key;
                    if (money == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (money == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }
                break;
            case 5: // Выход 
                cout << "Хорошего дня" << endl;
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
            cout << "\nВы хотите вернуться в меню? \n\t\n 1: Меню \t\n 2: Выход" << endl;
            while (OK)
            {
                cin >> key;
                if (key == 1) {
                    OK = 0;
                    continue;
                }
                else if (key == 2)
                {
                    cout << "Хорошего дня" << endl;
                    exit(0);
                }
                else
                    cout << "Ошибка/Попробуйте еще раз" << endl;
            }
            cin >> key;
            while ((key < 0) || (key >= 5))
                cin >> key;

            switch (key)
            {
                break;
            case 1:
            {
                cout << "Снятие наличных " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << "У вас недостаточно денег, чтобы снять наличные ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(key);
                cout << "Теперь у вас " << User->New->Work_with_money() << " на вашем счету" << endl;
                cout << "Вы хотите вернуться в меню? \n\t\n 1: Меню \t\n 2: Выход" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }

                break;
            case 2:

            {
                cout << setprecision(2) << fixed;
                cout << "Сколько USD хотите получить ?: ";
                cin >> rand;
                cout << rand << " USD(s)= ";
                equivD = (rand * DOLLAR);
                cout << equivD << " BYN(s)\n ";
                if (User->New->Work_with_money() < equivD)
                {
                    cout << "У вас недостаточно денег, чтобы снять наличные ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(equivD);
                cout << "Теперь у вас " << User->New->Work_with_money() << " BYN на вашем счету" << endl;

                cout << "Вы хотите вернуться в меню? \n\t\n 1: Меню \t\n 2: Выход" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }

            }
            break;

            case 3:
            {
                cout << setprecision(2) << fixed;
                cout << "Сколько EUR хотите получить ?: ";
                cin >> rand;
                cout << rand << " EUR(s)= ";
                equivD = (rand * EUROS);
                cout << equivD << " BYN(s)\n ";
                if (User->New->Work_with_money() < equivD)
                {
                    cout << "У вас недостаточно денег, чтобы снять наличные ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(equivD);
                cout << "Теперь у вас " << User->New->Work_with_money() << "BYN на вашем счету" << endl;

                cout << "Вы хотите вернуться в меню? \n\t\n 1: Меню \t\n 2: Выход" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }
            }
            break;

            case 4:
            {
                cout << setprecision(2) << fixed;
                cout << "Сколько RUB хотите получить ?: ";
                cin >> rand;
                cout << rand << " RUB(s)= ";
                equivD = (rand * RUBL);
                cout << equivD << " BYN(s)\n ";
                if (User->New->Work_with_money() < equivD)
                {
                    cout << "У вас недостаточно денег, чтобы снять наличные ." << endl;
                    Sleep(1000);

                }
                else User->New->Work_with_money(equivD);
                cout << "Теперь у вас " << User->New->Work_with_money() << "BYN на вашем счету" << endl;

                cout << "Вы хотите вернуться в меню? \n\t\n 1: Меню \t\n 2: Выход" << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << "Хорошего дня" << endl;
                        exit(0);
                    }
                    else
                        cout << "Ошибка/Попробуйте еще раз" << endl;
                }


            }

            }
            }



        }


    }// void::bank::currenty()
}// namespace Bank

