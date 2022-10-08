#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <thread>
#include <chrono>
#include "bank.h"


using namespace std;
//using namespace Bankomat::Bank;

 int main()
{
     

    setlocale(LC_ALL, "Russian");

   
    system("color 2");
    system("CLS");
    Bank::bank Bank_A;
    if (Bank_A.User->New->Enter_to_your_account())
        Bank_A.Menu();
  


return 0;

}
