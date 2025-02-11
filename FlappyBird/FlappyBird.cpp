#include <iostream>
#include <conio.h> // para gestionar las entradas
#include <windows.h> // para funciones de consola en Windows
#include <cstdlib>
#include <ctime>

using namespace std;

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20
#define WIN_WIDTH 70

int pipePos[2];
int gapPos[2];
int pipeFlag[2];
char bird[2][6] = { '/','-','-','o','\\',' ',
                    '|','_','_','_',' ','>' };
int birdPos;
int score;

void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcursor(bool visible, DWORD size) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (size == 0) {
        size = 20; // tamaño por defecto
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(WIN_WIDTH, i);
        cout << "|";
    }
}

void genPipe(int ind) {
    gapPos[ind] = 3 + rand() % 14;
}

void drawPipe(int ind) {
    if (pipeFlag[ind] == true) {
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            if (i < gapPos[ind] || i > gapPos[ind] + 6) {
                gotoxy(WIN_WIDTH - pipePos[ind], i);
                cout << "***";
            }
        }
    }
}

void erasePipe(int ind) {
    if (pipeFlag[ind] == true) {
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            if (i < gapPos[ind] || i > gapPos[ind] + 6) {
                gotoxy(WIN_WIDTH - pipePos[ind], i);
                cout << "   ";
            }
        }
    }
}

void drawBird() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            gotoxy(j + 2, i + birdPos);
            cout << bird[i][j];
        }
    }
}

void eraseBird() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            gotoxy(j + 2, i + birdPos);
            cout << " ";
        }
    }
}

int collision() {
    if (pipePos[0] >= 61) {
        if (birdPos < gapPos[0] || birdPos > gapPos[0] + 6) {
            return 1;
        }
    }
    return 0;
}

void gameover() {
    system("cls");
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "-------- Game Over -------" << endl;
    cout << "--------------------------" << endl;
    cout << "Press any key to go back to menu.";
    _getch();
}

void updateScore() {
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void instructions() {
    system("cls");
    cout << "Instructions";
    cout << "\n----------------";
    cout << "\n Press spacebar to make the bird fly";
    cout << "\nPress any key to go back to menu";
    _getch();
}

void play() {
    birdPos = 6;
    score = 0;
    pipeFlag[0] = 1;
    pipeFlag[1] = 0;
    pipePos[0] = pipePos[1] = 4;

    system("cls");
    drawBorder();
    genPipe(0);
    updateScore();

    gotoxy(10, 5); cout << "Press any key to start";
    _getch();
    gotoxy(10, 5); cout << "                      ";

    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 32) { // Espacio para volar
                if (birdPos > 3)
                    birdPos -= 3;
            }
            if (ch == 27) { // ESC para salir
                break;
            }
        }

        drawBird();
        drawPipe(0);
        drawPipe(1);

        if (collision() == 1) {
            gameover();
            return;
        }

        Sleep(100);
        eraseBird();
        erasePipe(0);
        erasePipe(1);
        birdPos += 1;

        if (birdPos > SCREEN_HEIGHT - 2) {
            gameover();
            return;
        }

        if (pipeFlag[0] == 1)
            pipePos[0] += 2;

        if (pipeFlag[1] == 1)
            pipePos[1] += 2;

        if (pipePos[0] >= 40) {
            pipeFlag[1] = 1;
            pipePos[1] = 4;
            genPipe(1);
        }
        if (pipePos[0] > 68) {
            score++;
            updateScore();
            pipeFlag[1] = 0;
            pipePos[0] = pipePos[1];
            gapPos[0] = gapPos[1];
        }
    }
}

int main() {
    setcursor(0, 0);
    srand((unsigned)time(NULL));

    do {
        system("cls");
        gotoxy(10, 5); cout << " -------------------------- ";
        gotoxy(10, 6); cout << " |     Flappy Bird        | ";
        gotoxy(10, 7); cout << " --------------------------";
        gotoxy(10, 9); cout << "1. Start Game";
        gotoxy(10, 10); cout << "2. Instructions";
        gotoxy(10, 11); cout << "3. Quit";
        gotoxy(10, 13); cout << "Select option: ";
        char op = _getche();

        if (op == '1') play();
        else if (op == '2') instructions();
        else if (op == '3') exit(0);

    } while (1);

    return 0;
}
