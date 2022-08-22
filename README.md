// Библиотеки
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip> //позволяет округлять  до десятичных знаков

using namespace std;
// Объявляю класс BankAccount
class BankAccount {
    // Объявля. переменные
private:
    string pinNum;
    char accType;
    double balance;
    double amount;

public:
    // Конструктор банковского счета
    BankAccount() {
        // переменные баланса и суммы
        balance = 0.0;
        amount = 0.0;
    }

    //  прототипы функций
    void pinNumber();
    void accountType();
    void balanceChecking();
    void balanceSavings();
    void deposit();
    void withdraw();
    void display();
}; 

// // Функция для получения pin-кода от конечного пользователя
void BankAccount::pinNumber()
{
    setlocale(LC_ALL, "RUS");
    cout << "________________________________________________________________________________";
    cout << "\n\t\t\t        БЕЛАРУСБАНК БАНКОМАТ" << endl;
    cout << "________________________________________________________________________________";
    //prompts end user for the pin number to access bank account
    cout << "\n\t\t\t        ВВЕДИТЕ PIN-КОД: \n" << endl;
    cout << "\t\t\t\t      ";

    // For loop to allow user to re-enter pin 4 times if it is invalid
    for (int i = 0; i <= 3; i++) {
        // Mask pinNum with asterisks
        char ch;
        cout << setw(1); // Output formatting space
        ch = _getch();
        while (ch != 13) {
            pinNum.push_back(ch); //push pinNum and replace with asterisk
            cout << '*';
            ch = _getch();
        }


        // Set pinNum to 1234
        if (pinNum == "1234") {
            cout << "\n\n\t\t\t  Добро пожаловать в аккаунт!" << endl;
            // Display options menu if pinNumber is correct
            display();

            // Verify if pinNum contains only intergers
            while (!(cin >> pinNum)) {
                // Reset the input
                cin.clear();
                // Get string input
                while (cin.get() != '\n')
                    continue;
                // Ask user to try again:
                cout << "\n\t\t\t   Пожалуйста, введите цифровой Pin-код:  ";
            } // End while cin

         // Разрешить пользователю повторно ввести pin-код 4 раза перед блокировкой учетной записи
        }
        else if (i >= 3) {
            cout << "\n\t\t\t Ваша учетная запись заблокирована!\n";
            cout << "\t\t\t   Вы достигли предела попыток." << endl;
           
            { 
            system("pause");
            }
            // If user enters any numeric invalid pin, allow to re-enter pin
        }
        else {
            cout << "\n\t\t\t   Неверный Pin-код \n";
            cout << "\t\t\t   Введите Pin-Код Еще Раз: \n";
            cout << "\t\t\t\t   ";
            cin >> pinNum;
        }
    }
}

// Функция для получения типа учетной записи от конечного пользователя
void BankAccount::accountType() {
    cout << "\n\t\t\t Select Account Type:\n";
    cout << "\t\t\t Проверка 'C' or Сбережения 'S': ";
    cin >> accType;

   
    if (accType == 'C' || accType == 'c') {
        cout << "\t\t\t================================" << endl << endl;
        cout << "\t\t\t\tТекущий счет" << endl << endl;
        cout << "\t\t\t================================" << endl << endl;
        
    }
    else if (accType == 'S' || accType == 's') {
        cout << "\t\t\t================================" << endl << endl;
        cout << "\t\t\t\tСберегательный счет" << endl << endl;
        cout << "\t\t\t================================" << endl << endl;
    }
    else {
        cout << "\t\t\tНедопустимый Тип учетной записи.\n";
        cout << "\t\t\tВыберите Тип учетной записи: 'C' or 'S': ";
        cin >> accType;
    }
}


void BankAccount::deposit() {
    cout << "\n\t\t\t\t    ДИПОЗИТ\n";
    cout << "\t\t\t   Введите Сумму Вывод $";
    cin >> amount;
    cout << "\n\t\t\t========ЧЕК========" << endl << endl;
    cout << setprecision(2) << fixed; //round decimal 2 places
    cout << "\t\t\t Внесенная Сумма = $" << amount << endl << endl;
    balance += amount;
    cout << "\t\t\t Новый баланс $" << balance << endl << endl;
    cout << "\t\t\t===============================" << endl;
}


void BankAccount::withdraw() {
    cout << "\n\t\t\t\t    ВЫВОСТИ\n";
    cout << "\t\t\t   Введите Сумму Вывода $";
    cin >> amount;
    cout << "\n\t\t\t=======ЧЕК==========" << endl << endl;
    cout << "\t\t\t Снятая сумма = $" << amount << endl << endl;
    balance -= amount;
    cout << "\t\t\t Новый Баланс $" << balance << endl << endl;
    cout << "\t\t\t=================================" << endl;
}

//Функция отображения текущего баланса счета
void BankAccount::balanceChecking() {
    cout << "\n\t\t\t=====Текущий Баланс Счета=====";
    cout << "\n\t\t\t Текущий счет # xxxxxxxx4567\n";
    //Баланс = 10000;
    cout << "\n\t\t\t Баланс = $" << balance << endl;
    cout << "\n\t\t\t==================================" << endl;
}// // Завершить функцию проверки баланса

// Функция отображения баланса сберегательного счета
void BankAccount::balanceSavings() {
    cout << "\n\t\t\t=====Остаток на Сберегательном счете=====";
    cout << "\n\t\t\t Сберегательный счет # xxxxxxxx8901\n";
    //остаток = 25000;
    cout << "\n\t\t\t Баланс = $" << balance << endl;
    cout << "\n\t\t\t=================================" << endl;
}// // Функция экономии конечного остатка

// Отображение меню параметров после ввода pin-кода
void BankAccount::display() {
    int options = 1;
    // // Пока параметры не равны нулю, разрешить конечному пользователю выбрать опцию для доступа к банковскому счету
    while (options != 0) {
        cout << "\n\t\t\t  1. Выберите Тип учетной записи\n";
        cout << "\t\t\t  2. Депозит\n";
        cout << "\t\t\t  3. Вывости\n";
        cout << "\t\t\t  4. Текущий Баланс Счета\n";
        cout << "\t\t\t  5. Остаток на Сберегательном счете\n";
        cout << "\t\t\t  0. Завершение Транзакций\n";
        cout << "\n\t\t\t\t\t";
        cin >> options;

        //Оператор переключения для вызова функций на основе выбранного конечным пользователем параметра
        switch (options) {
        case 0: pinNumber();
            break;
        case 1: accountType();
            break;
        case 2: deposit();
            break;
        case 3: withdraw();
            break;
        case 4: balanceChecking();
            break;
        case 5: balanceSavings();
            break;
        default: cout << "\n\t\t\t   Недопустимая опция" << endl;
        }
    }
}

int main()
{
    //Изменение цвета текста на экране
    system("color 0b");
    // Объявить объект BankAccount
    BankAccount bank;
    //Функции вызова
    bank.pinNumber();
    bank.accountType();
    bank.balanceChecking();
    bank.balanceSavings();
    bank.deposit();
    bank.withdraw();

    return 0;
}

