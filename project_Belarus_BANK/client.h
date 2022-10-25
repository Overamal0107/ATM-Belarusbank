#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <windows.h>

#include "account.h"

namespace Account {
	namespace Client {
		using namespace Account;

		class client { /* �������� ��������� ����� ���������� ��������
						  (��� �������� ������� ����� ����������������� ������ ������������
						  � �� ������� ������� ���� ����� - �� ��������) */
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
			cout << "������� ���� ��� � �������" << endl;
			cin.getline(fio, 50);
			cout << "����� �������� :" << endl;
			cin.getline(serial, 50);
			cout << "������� ���� �����" << endl;
			cin.getline(adress, 50);
			cout << "������� ����� ���������� ��������" << endl;
			cin.getline(telefon, 50);
			cout << "���� ������!!!" << endl << endl;
		}  // class client
		client::~client() { delete New; }

	}  // namespace Client
}  // namespace Account
