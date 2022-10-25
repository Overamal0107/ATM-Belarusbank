#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <windows.h>

#include "account.h"

namespace Account {
	namespace Client {
		using namespace Account;

		class client { /* операция заведения новой банковской карточки
						  (эта операция требует ввода идентификационных данных пользователя
						  и не требует наличие хоть какой - то карточки) */
		public:
			Bankomat::Account::account* New;
			char fio[50];
			char adress[50];
			char telefon[15];
			char serial[50];
			client();
			~client();
		};  // namespace Client

		client::client() {
			New = new Bankomat::Account::account;
			cout << "Введите ваше имя и фамилию" << endl;
			cin.getline(fio, 50);
			cout << "Серия паспорта :" << endl;
			cin.getline(serial, 50);
			cout << "Введите свой адрес" << endl;
			cin.getline(adress, 50);
			cout << "Введите номер мобильного телефона" << endl;
			cin.getline(telefon, 50);
			cout << "Счёт открыт!!!" << endl << endl;
		}  // class client
		client::~client() { delete New; }

	}  // namespace Client
}  // namespace Account
