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

          
            cout << "\t\t\t\t\t\t\tБЕЛАРУСБАНК" << endl;
            cout << "\n" << " Курс волют:" << "\n";
            float BYN_RUB_kurs = 3.3000;
            cout << " RUB kurs:" << BYN_RUB_kurs << "\n";
            float BYN_USD_kurs = 2.3700;
            cout << " USD kurs:" << BYN_USD_kurs << "\n";
            float BYN_EU_kurs = 2.2700;
            cout << "" << " EUR kurs:" << BYN_EU_kurs << "\n";

            cout << "\n" << " Выберите, операцию " << endl;
            cout << " 1: Остаток " << endl  << " 2: Снятие наличных  " << endl << " 3: Олаты телефона   " << endl << " 4: Первод на карту " << " 5: Выход " << endl;
            cin >> key;
            while ((key < 0) || (key >= 5))
                cin >> key;

            switch (key)
            {
            case 1:

                system("CLS");
                User->New->Show_info();
                cout << " Вы хотите вернуться в меню ? \t 1: Меню;\t2: Выход " << endl;

                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    { 
                        cout << " Хорошего дня " << endl;
                        exit(0);
                    }
                    else
                        cout << " Ошибка/Попробуйте еще раз" << endl;
                }
                break;
         
            case 2:
                cout << " Снятие наличных  " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << " У вас недостаточно денег, чтобы снять наличные ." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << " Теперь у вас   " << User->New->Work_with_money() << " на вашем счету " << endl;
                cout << " Вы хотите вернуться в меню? \t 1: Меню ;\t2: Выход " << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << " Хорошего дня " << endl;
                        exit(0);
                    }
                    else
                        cout << " Ошибка/Попробуйте еще раз " << endl;
                }
                break;
            case 3:
                cout << " Сколько вы хотите зачислить на мобильный счет ? " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << "У вас недостаточно денег, чтобы оплатить." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << " Деньги зачислены  \n "  << endl;
                cout << " Вы хотите вернуться в меню? \t 1: Меню ;\t2: Выход " << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << " Хорошего дня " << endl;
                        exit(0);
                    }
                    else
                        cout << " Ошибка/Попробуйте еще раз " << endl;
                }
                break;

            case 4 :
                cout << " Какую сумму хотите перевести  " << endl;
                cin >> key;
                if (User->New->Work_with_money() < key)
                {
                    cout << " У вас недостаточно денег, выполнить перевод ." << endl;
                    Sleep(1000);
                    continue;
                }
                else User->New->Work_with_money(key);
                cout << " Теперь у вас   " << User->New->Work_with_money() << " на вашем счету " << endl;
                cout << " Вы хотите вернуться в меню? \t 1: Меню ;\t2: Выход " << endl;
                while (OK)
                {
                    cin >> key;
                    if (key == 1) {
                        OK = 0;
                        continue;
                    }
                    else if (key == 2)
                    {
                        cout << " Хорошего дня " << endl;
                        exit(0);
                    }
                    else
                        cout << " Ошибка/Попробуйте еще раз " << endl;
                }
                break;
            case 5:
                cout << " Хорошего дня " << endl;
                exit(0);
                break;
            }
        }
    }
}

