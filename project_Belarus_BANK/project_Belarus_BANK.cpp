#define _CRT_SECURE_NO_WARNINGS#include <conio.h>

#include <iostream>

#include "bank.h"

#include <string>

#include <cassert>

using namespace std;

int main()

{

	setlocale(LC_ALL, "Russian");
	system("color 2");
	system("CLS");
	system("mode con cols=70 lines=50");

	Bank::bank Bank_A;
	if (Bank_A.User->New->Enter_to_your_account()) Bank_A.Menu();
	return 0;

}
