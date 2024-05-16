#include <clocale>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <string.h>

using namespace std;

int main() {
    setlocale(0, "Russian");
    void print_menu(); {
        int ch;
        do {
            system("cls");
            print_menu();
            fflush(stdin);
            ch = _getch();
            system("cls");
            switch (ch) {
            case '1': {

            
            }break;
            case '2': ; break;
            case '0': exit(0); break;
            default: continue;
            }
         
        } while (1);
    }
    
    return 0;
}


void print_menu() {
    printf("\n      Выберете пункт меню:    \
           \n       ******************      \
           \n       | 1. Начать игру |      \
           \n       | 2. Об игре     |      \
           \n       | 0. Выход       |      \
           \n       ****************** \n");
}


