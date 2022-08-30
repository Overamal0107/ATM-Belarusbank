#include <iostream>

#include <stdlib.h>

#include <conio.h>

#include <iomanip>

#include <thread>

#include <chrono>


using namespace std;
int CustomerAccountNumber = 998710002;
int pinNumber = 7777;
int AccountBalance = 0;

bool ValidateCustomerDetails() {

        int InputAccountNumber = -1;
        int InputPinNumber = -1;
        bool isAccountInvalid = true;
        bool isPinInvalid = true;

        cout << "\t\t\t\t\t\tБЕЛАРУСБАНК" << endl;
        cout << "\n\n\t\t\t\t\t|Visa|\t|Mastercard|\t|MIR|" << endl;

        while (isAccountInvalid) {

                cout << " \nПожалуйста, вставьте банковску карту: ";
                cin >> InputAccountNumber;

                if (InputAccountNumber == CustomerAccountNumber) {
                        isAccountInvalid = false;
                } else {
                        cout << " \nНеверный Номер Счета! Пробовать снова. " << endl;
                }
        }
        int RetryCount = 3;
        while (isPinInvalid && RetryCount) {

                cout << " Введите свой PIN-код : ";
                cin >> InputPinNumber;

                if (InputPinNumber == pinNumber) {
                        isPinInvalid = false;
                } else {
                        RetryCount--;
                        if (RetryCount)
                                cout << "Неверный PIN-код ! Пробовать снова." << endl;
                        else {
                                cout << " \nВаша учетная запись заблокирована! Лимит попыток ! Обратитесь в банк. " << endl;
                                return false;
                        }

                }

        }

        return true;

}

int DisplayMenu() {

        int UserInputOption = -1;

        cout << " \nДобро пожаловать в БЕЛАРУСБАНК!! Пожалуйста, выберите операцию, чтобы продолжить " << endl;
        cout << "    1 - Остаток на счету" << endl;
        cout << "    2 - Снять Наличные" << endl;
        cout << "    3 - Внесите Наличные" << endl;
        cout << "    4 - Олаты телефона" << endl;
        cout << "    5 - Выход" << endl;
        cout << " Выберите опцию, чтобы продолжить: " << endl;
        cin >> UserInputOption;

        return UserInputOption;

}

void DisplayAccountBalance() {

        cout << " Баланс Вашего счета составляет: " << endl;
        cout << AccountBalance << " BYN " << endl;

}

void WithDrawMoneyFromAccount() {

        int UserInputOption = -1;
        int valueToWithdraw = 0;
        long CustomerRequest = 0;
        bool isNotFinished = true;

        do {

                cout << "Варианты вывода средств:" << endl;
                cout << "1 -   5 BYN" << endl;
                cout << "2 -  10 BYN" << endl;
                cout << "3 -  20 BYN" << endl;
                cout << "4 -  50 BYN" << endl;
                cout << "5 - 100 BYN" << endl;
                cout << "6 - Отменить транзакцию" << endl;
                cout << "7 - Другая Сумма" << endl;
                cout << " Выберите вариант вывода средств (1-7) " << endl;

                cin >> UserInputOption;
                switch (UserInputOption) {
                case 1:
                        valueToWithdraw = 5;
                        break;
                case 2:
                        valueToWithdraw = 10;
                        break;
                case 3:
                        valueToWithdraw = 20;
                        break;
                case 4:
                        valueToWithdraw = 50;
                        break;
                case 5:
                        valueToWithdraw = 100;
                        break;
                case 6:
                        isNotFinished = false;
                        break;
                case 7:
                        cout << " Введите сумму для вывода: " << endl;
                        cin >> CustomerRequest;
                        valueToWithdraw = CustomerRequest;
                        isNotFinished = false;
                        break;
                default:
                        cout << "Недопустимый вариант! Пробовать снова." << endl;
                        break;
                }

                if (valueToWithdraw != 0) {
                        if (valueToWithdraw > AccountBalance) {
                                cout << " \nПрости!! Баланс Вашего Счета составляет всего BYN " << AccountBalance << ". Вы не можите вывети  " << valueToWithdraw << " BYN " << endl;
                        } else {
                                AccountBalance = AccountBalance - valueToWithdraw;
                                isNotFinished = false;
                        }
                        valueToWithdraw = 0;
                }

        } while (isNotFinished);

}

void DepositMoneyInAccount() {

        int UserInputOption = -1;
        bool isNotFinished = true;
        long depositAmount = 0;

        do {

                cout << " Варианты Внесения Наличных Денег. Пожалуйста, Введите Свой Выбор" << endl;
                cout << " 1 -   5 BYN " << endl;
                cout << " 2 -  10 BYN " << endl;
                cout << " 3 -  20 BYN " << endl;
                cout << " 4 -  50 BYN " << endl;
                cout << " 5 - 100 BYN " << endl;
                cout << " 6 - Отменить транзакцию " << endl;
                cout << " 7 - Другая сумма" << endl;
                cout << " Выберите вариант пополнения счета (1-7) " << endl;

                cin >> UserInputOption;
                switch (UserInputOption) {
                case 1:
                        AccountBalance = AccountBalance + 20;
                        isNotFinished = false;
                        break;
                case 2:
                        AccountBalance = AccountBalance + 40;
                        isNotFinished = false;
                        break;
                case 3:
                        AccountBalance = AccountBalance + 60;
                        isNotFinished = false;
                        break;
                case 4:
                        AccountBalance = AccountBalance + 100;
                        isNotFinished = false;
                        break;
                case 5:
                        AccountBalance = AccountBalance + 200;
                        isNotFinished = false;
                        break;
                case 6:
                        isNotFinished = false;
                        break;
                case 7:
                        cout << "Пожалуйста, Введите Сумму для внесения депозита:" << endl;
                        cin >> depositAmount;
                        AccountBalance = AccountBalance + depositAmount;
                        isNotFinished = false;
                        break;
                default:
                        cout << " Недопустимый вариант! Пробовать снова." << endl;
                        break;
                }

        } while (isNotFinished);

}
void Phonebillpayment() {

        int UserInputOption = -1;
        int valueToWithdraw = 0;
        long CustomerRequest = 0;
        bool isNotFinished = true;

        do {

                cout << "Варианты пополнения :" << endl;
                cout << "1 -   5 BYN" << endl;
                cout << "2 -  10 BYN" << endl;
                cout << "3 -  20 BYN" << endl;
                cout << "4 -  50 BYN" << endl;
                cout << "5 - 100 BYN" << endl;
                cout << "6 - Отменить транзакцию" << endl;
                cout << "7 - Другая Сумма" << endl;
                cout << " Выберите вариант вывода средств (1-7) " << endl;

                cin >> UserInputOption;
                switch (UserInputOption) {
                case 1:
                        valueToWithdraw = 5;
                        break;
                case 2:
                        valueToWithdraw = 10;
                        break;
                case 3:
                        valueToWithdraw = 20;
                        break;
                case 4:
                        valueToWithdraw = 50;
                        break;
                case 5:
                        valueToWithdraw = 100;
                        break;
                case 6:
                        isNotFinished = false;
                        break;
                case 7:
                        cout << " Введите сумму для пополнения : " << endl;
                        cin >> CustomerRequest;
                        valueToWithdraw = CustomerRequest;
                        isNotFinished = false;
                        break;
                default:
                        cout << "Недостаточно средст на счету ! Пробовать снова." << endl;
                        break;
                }

                if (valueToWithdraw != 0) {
                        if (valueToWithdraw > AccountBalance) {
                                cout << " \n Простите!! Баланс Вашего Счета составляет всего BYN " << AccountBalance << ". Вы не можите оплатить телефон   " << valueToWithdraw << " BYN " << endl;
                        } else {
                                AccountBalance = AccountBalance - valueToWithdraw;
                                isNotFinished = false;
                        }
                        valueToWithdraw = 0;
                }

        } while (isNotFinished);

}

int main(void) {

        system("color 2");
        setlocale(LC_ALL, "Russian");

        if (ValidateCustomerDetails()) {

                int isNotFinished = true;

                do {

                        switch (DisplayMenu()) {
                        case 1:
                                DisplayAccountBalance();
                                break;
                        case 2:
                                WithDrawMoneyFromAccount();
                                break;
                        case 3:
                                DepositMoneyInAccount();
                                break;
                        case 4:
                                Phonebillpayment();
                                break;
                        case 5:
                                isNotFinished = false;
                                break;
                        default:
                                cout << " Недопустимый вариант! Пробовать снова. " << endl;
                                break;
                        }

                } while (isNotFinished);

        }

        return 0;

}
