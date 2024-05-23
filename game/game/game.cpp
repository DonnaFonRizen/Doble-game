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
enum ConsoleColor   // цвета
{
    Black = 0,
    Blue = 1,
    Magenta = 5,
    Blue2 = 7,
    Gray = 9,

};

void setcolor(int text, int background)   //функция закраски
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


//char storage[6][6];   //глобальное объявление массива


#define SPACE 'X'
#define RET ' '

char  matrix[6][6] = {                   // Пустая матрица
{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},
{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE}
};

char storage[6][6] = {           // Матрица хранящая символы
{1,177,11,3,11,1},
{177,11,177,15,4,15},
{3,1,3,15,4,3},
{177,3,11,11,4,3},
{1,15,1,177,15,4},
{15,11,4,1,4,177}
};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // описание хендла

COORD c = { 34, 9 }; //нач.положение

void about();  // об игре
void strelki();  // движение
int wait();
void massive(int x, int y); // вывод массива на экран
void proverka_win();          // проверка на победу
void enter(int y, int x);      // нажатие
void proverka(int i1, int i2, int j1, int j2);  // сравнение символов


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

                strelki();
            }break;
            case '2': about(); break;
            case '0': exit(0); break;
            default: continue;
            }
            wait();
        } while (1);
    }
    strelki();
    return 0;
}



// стартовое меню
void print_menu() {
    printf("\n      Выберете пункт меню:    \
           \n       ******************      \
           \n       | 1. Начать игру |      \
           \n       | 2. Об игре     |      \
           \n       | 0. Выход       |      \
           \n       ****************** \n");
}
void about() {
    printf("\n Игра <<перевертыши>> или <<найди пару>>\
                       \n 1. Поможет тебе развить способность к запоминанию,\
                       \nвнимательность и сообразительность.\
                       \n 2.Она состоит из 36-ти карточек,\
                       \nпод которыми находятся  пары одинаковых картинок.\
                       \n 3.Твоя задача - открыть все карточки.\
                       \n Выполнил: студент  Опарин Дмитрий\n ");
}

int wait() {

    fflush(stdin);
    return _getch();
}
// управление по полю стрелками
void strelki() {

    int k=0; int kol = 0, i1, j1, i2, j2;
    while (k != 27)

    {
        proverka_win();  
        massive(c.X, c.Y);

        k = _getch();
        if (k == 27)  k = _getch();
        switch (k)

        {

        case 72:if (c.Y > 9) c.Y--;break;

        case 75:if (c.X > 34) c.X--;break;

        case 77: if (c.X < 39) c.X++;break;

        case 80:if (c.Y < 14) c.Y++;break;

        case 13: enter(c.X - 34, c.Y - 9);
            kol++;
            switch (kol) {
            case 1:
                i1 = c.Y - 9;
                j1 = c.X - 34;
                break;

            case 2:
                i2 = c.Y - 9;
                j2 = c.X - 34;
                Sleep(1000);

                proverka(i1, i2, j1, j2);
                kol = 0;
                break;
            }

            break;


        } }
}
// проверка на победу проверяет что не осталось закрытых картинок
void proverka_win() {
    int b = 0;
    for (int i = 0; i < 6;i++)
        for (int j = 0;j < 6;j++) {
            if (matrix[i][j] != SPACE) {
                b++;
            }
        }
    if (b == 36) {
        system("cls");
        printf("YOU WIN"); _getch(); exit;
    }
}
// отрисовка игрового поля 

// srand(time(NULL)); 
void massive(int x, int y) {
    setcolor(1, 0);
    system("cls");

    COORD xy = { 34, 9 };

    for (int i = 0;i < 6;i++)
    {
        SetConsoleCursorPosition(h, xy);
        for (int j = 0;j < 6;j++)
        {
            setcolor(9, 7);
            printf("%c", matrix[i][j]);
        }
        xy.Y++;
    }
    COORD g = { x, y };
    SetConsoleCursorPosition(h, g);
}
// проверка совпадений
void proverka(int i1, int i2, int j1, int j2) {

    /*// if (matrix [i1][j1]!=SPACE || matrix[i2][j2]!=SPACE );
    if (storage[i1][j1]!=storage[i2][j2] ){
         matrix[i1][j1]=SPACE;
         //Sleep (1000);
         matrix[i2][j2]=SPACE;*/

    if (matrix[i1][j1] == matrix[i2][j2])
    {
        //matrix[i1][j1]=RET;
        //matrix[i2][j2]=RET;
    }

    else {
        matrix[i1][j1] = SPACE;
        matrix[i2][j2] = SPACE;
    }
    proverka_win();
}
// открытие картинок
void enter(int y, int x) {
    matrix[x][y] = storage[x][y];
}