#define _CRT_SECURE_NO_WARNINGS
#pragma once#include <time.h>

#include <iostream>

using namespace std;

namespace Bankomat {
    namespace Account {
        class account {
        public:
            account();
            int CustomerAccountNumber_A = 4444555;
            int CustomerAccountNumber_B = 7777666;
            int pinNumber1 = 7777;
            int pinNumber2 = 8888;
            int InputAccountNumber = -1;
            int InputPinNumber = -1;
            char password[5]; // ��� ���
            char user_account[13];
            long money;
         bool isAccountInvalid = true;
            bool isPinInvalid = true;
            void Open_account();
            void Show_info();
            long& Work_with_money(int m);
            bool Enter_to_your_account();

        private:
        }; // class accoun

        void account::Open_account() // ���������� ��������

        {
            int k;
            srand(time(0));
            for (int i = 0; i < 12; i++) {
                user_account[i] = rand() % 10 + 48;
            }
            user_account[12] = '\0';
            cout << "��� ���� " << user_account << endl;
            k = rand() % 10000;
            _itoa(k, password, 10);
            password[4] = '\0';
            cout << "��� ����� ������ " << password << endl;
            cout << "����� �����, ������� �� �������� �� ���� ����?" << endl;
            cin >> money;
        }

        void account::Show_info()

        {
            cout << "��� ���� " << user_account << endl;
            cout << "������ " << money << endl;
        }

        long& account::Work_with_money(int m = 0) {
            money -= m;
            return money;
        }

        account::account() {
            cout << "\t\t\t\t�����������" << endl;
            cout << "\n\n\t\t\t" <<
                "|Visa|\t|Mastercard|\t|MIR|" << endl;
            cout << "\n\n" <<
                "��������� ����� " <<
                "\n" <<
                endl;
        }

        bool account::Enter_to_your_account() {
            char tries[5];
            int times = 0;
            cout << "������� ������, ���� �� ������ ������������ ���� ������� ������" <<
                endl;

            while (times < 3) {
                cin >> tries;

                if (strcmp(tries, password) == 0) {
                    cout << "����� ���������� " << endl;
                    return 1;
                }
                else
                    cout << "������ ��������� �������" << endl;
                times++;
            }

            if (times == 3)
                cout << "������ ��� ������� ������ ������ 3 ����, ��� ������� "
                "������������ ! ���������� � ����." <<
                endl;
            return 0;
        }
    } // namespace Account
} // namespace Bankomat