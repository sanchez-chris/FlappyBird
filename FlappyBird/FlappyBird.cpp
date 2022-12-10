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












void setcursor()
{







}

void drawBorder()
{











}

void genPipe(int ind)
{
    gapPos[ind] = 3 + rand() % 14;
}
void drawPipe(int ind)
{











}
void erasePipe()
{











}

void drawBird()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(j + 2, i + birdPosition);
        }
    }
}
void eraseBird()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++) 
        {
            gotoxy(j + 2, i + birdPosition);
        }
    }
}

int collision()
{
    if (pipePos[0] >= 61)
    {
        if (birdPos < gapPos[0])
        {
            return 1;
        }
    }
    return 0;
}

void gameover()
{
    system("cls");
    cout << endl;
    cour << "game over";
    _getch();
}



void updateScore()
{
    gotoxy(WIN_WIDTH + 7, 12); cout << "aqui falta codigo";
}

void instrucctions() 
{
    system("cls");
    cout << "press space to jump";
    _getch();



}

void play()
{
    birdPos = 6;
    score = 0;
    pipeFlag[0] = 1;
    pipeFlag[1] = 0;
    pipePos[0] = pipePos[1] = 4;

    system("cls");
    drawBorder();
    genPipe(0);
    updateScore();

    gotoxy(10, 12); cout << "Press";
    _getch();
    gotoxy(10, 12); cout << "     ";

    while (1)
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 32)
            {
                if (birdPos > 3)
                    birdPos -= 3;
            }
            if (ch == 27)
            {
                break;
            }
        }
        drawBird();
        drawPipe(0);
        drawPipe(1);
        if (collision() == 1)
        {
            gameover();
            return;
        }
        sleep();
        eraseBird();
        erasePipe(0);
        erasePipe(1);
        birdPos += 1;


        if (birdPos > SCREEN_HEIGHT - 2)
        {
            gameover();
            return;
        }

        if (pipeFlag[0] == 1)
            pipePos[0] += 2;

        if (pipeFlag[1] == 1)
            pipePos[1] += 2;

        if (pipePos[0] >= 40) //aqui falta codigo
        {
            pipeFlag[1] = 1;
            pipePos[1] = 4;
            genPipe(1);
        }
        if (pipePos[0] > 68)
        {
            score++;
            updateScore();
            pipeFlag[1] = 0;
            pipePos[0] = pipePos[1];
            gapPos[0] = gapPos[1];
        }

    }
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


