// FlappyBird.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> //to manage the inputs
#include <dos.h> //delay and fotograms
#include <stdlib.h>
#include <string.h>
#include <windows.h> //more features in windows console
#include <time.h>


using namespace std;

void gotoxy(short x, short y) {
    COORD pos = { x ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void sleep(unsigned milliseconds)
{
    sleep(milliseconds * 1000); // takes microseconds
}

void play()
{
    system("cls");

    while (1)
    {
        sleep(100);
    }
    return;
}

int main()
{
  //  setcursor(0, 0);
    srand((unsigned)time(NULL));

    do
    {
        system("cls");
        
        gotoxy(10, 6); cout << " | Flappy Bird in C++ |";
        gotoxy(10, 7); cout << endl;
        gotoxy(10, 9); cout << "1. Play";
        gotoxy(10, 10); cout << "2. Controls";
        gotoxy(10,11); cout << "3. Exit";
        char op = _getche();

        if (op == '1') play();
      //  else if (op == '2') instrucctions();
        else if (op == '3') exit(0);

    } while (1);

    return 0;
}


