#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <time.h>

using namespace std;

namespace Bankomat {
    namespace Account {
        class account {
        public:
            account();
            char password[5];// пин код
            char user_account[13];
            long money;
            void Open_account();
            void Show_info();
            long& Work_with_money(int m);
            bool Enter_to_your_account();

        private:
        };  // class accoun

        void account::Open_account() // Банковская карточка

        {
            int k;
            srand(time(0));
            for (int i = 0; i < 12; i++) {
                user_account[i] = rand() % 10 + 48;
            }
            user_account[12] = '\0';
            cout << "Ваш счет " << user_account << endl;
            k = rand() % 10000;
            _itoa(k, password, 10);
            password[4] = '\0';
            cout << "Ваш новый пароль " << password << endl;
            cout << "Сумма денег, которую вы положите на свой счет?" << endl;
            cin >> money;
        }

        void account::Show_info()

        {
            cout << "Ваш счет " << user_account << endl;
            cout << "Баланс " << money << endl;
        }

        long& account::Work_with_money(int m = 0) {
            money -= m;
            return money;
        }

        account::account() {
            cout << "\t\t\t\tБЕЛАРУСБАНК" << endl;
            cout << "\n\n\t\t\t"
                << "|Visa|\t|Mastercard|\t|MIR|" << endl;
            cout << "\n\n"
                << "Получение Карты "
                << "\n"
                << endl;
        }

        bool account::Enter_to_your_account() {
            char tries[5];
            int times = 0;
            cout << "Введите пароль, если вы хотите использовать свою учетную запись"
                << endl;

            while (times < 3) {
                cin >> tries;

                if (strcmp(tries, password) == 0) {
                    cout << "Добро пожаловать " << endl;
                    return 1;
                }
                else
                    cout << "Ошибка повторите попытку" << endl;
                times++;
            }

            if (times == 3)
                cout << "Ошибка при попытке ввести пароль 3 раза, ваш аккаунт "
                "заблокирован "
                << endl;
            return 0;
        }
    }  // namespace Account
}  // namespace Bankomat
