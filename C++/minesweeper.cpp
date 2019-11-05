#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<random>
#include<windows.h>
#include<time.h>
#include<winuser.h>
using namespace std;

bool quit = false, running = false, win = false;
bool start;
HANDLE Handle;
int lod, bombCount, board[20][20], boardsize;
bool reviewed[20][20];

void SetWindow(int Width, int Height) {

    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size

}

void gotoxy(int x, int y) {

  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void BoardSelection(){

    char c = '0';
    int line = 0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    system("CLS");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

    gotoxy(40,9);
    cout<<char(24);
    gotoxy(40,11);
    cout<<"W";

    gotoxy(40,24);
    cout<<char(25);
    gotoxy(40,23);
    cout<<"S";

    gotoxy(38,15);
    cout << "10x10";
    gotoxy(38,17);
    cout << "15x15";
    gotoxy(38,19);
    cout << "20x20";

    while(c != char(13)){

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);

        gotoxy(28,15+line);
        cout<<"->    ";
        gotoxy(51,15+line);
        cout<<"  <-";
        gotoxy(0,0);

        c=getch();

        gotoxy(28,15+line);
        cout<<"  ";
        gotoxy(51,15+line);
        cout<<"    ";

        if (c=='s')
            if (line<4) line+=2;

        if (c=='w')
            if (line>0) line-=2;

    }
    if (line==0) lod = 1;
    if (line==2) lod = 2;
    if (line==4) lod = 3;

    boardsize = (lod == 1) ? 10 : (lod == 2) ? 15 : 20;

    line=0;
    c=' ';
    system("CLS");

}

void menu() {

    char c='0';
    int line=0;

    quit=false;
    system("CLS");

    while ((start==false) && (quit==false)) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

    gotoxy(40,9);
    cout<<char(24);
    gotoxy(40,11);
    cout<<"W";

    gotoxy(40,24);
    cout<<char(25);
    gotoxy(40,23);
    cout<<"S";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    gotoxy(35,15);
    cout<<" START GAME ";
    gotoxy(37,17);
    cout<<"  QUIT  ";

    while (c!=char(13))
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);

        gotoxy(28,15+line);
        cout<<"->    ";
        gotoxy(51,15+line);
        cout<<"  <-";
        gotoxy(0,0);

        c=getch();

        gotoxy(28,15+line);
        cout<<"  ";
        gotoxy(51,15+line);
        cout<<"    ";

        if (c=='s')
            if (line<2) line+=2;

        if (c=='w')
            if (line>0) line-=2;

    }
    if (line==0) {

        start=true;
        BoardSelection();

    }
    if (line==2) {

        start=false;
        quit=true;

    }

    line=0;
    c=' ';
    system("CLS");

    }

}

void randomizebombs(){

    srand(time(0));

    for(int i = 0; i < bombCount; i++) {

        bool contained = true;
        int x, y;

        while(contained){

            x = rand() % boardsize;
            y = rand() % boardsize;

            contained = false;

            for(int j = 0; j < i; j++) if( board[x][y] == -1 ) contained = true;
        }

        board[x][y] = -1;

    }

}

int countadjacentbombs(){

    for(int i = 0; i < boardsize; i++)
        for(int j = 0; j < boardsize; j++){

            int count = 0;

            if(board[i][j] == -1) continue;

            if(board[i - 1][j - 1] == -1) count++;
            if(board[i - 1][j] == -1) count++;
            if(board[i - 1][j + 1] == -1) count++;
            if(board[i][j - 1] == -1) count++;
            if(board[i][j + 1] == -1) count++;
            if(board[i + 1][j - 1] == -1) count++;
            if(board[i + 1][j] == -1) count++;
            if(board[i + 1][j + 1] == -1) count++;

            board[i][j] = count;

        }

}

void drawboard(){

    string out = " # ";

    if(lod == 1){

        for(int i = 0; i < 10; i++){

            gotoxy(25,10 + i);

            for(int j = 0; j < 10; j++) cout << out;

        }

        bombCount = 7;

    }

    if(lod == 2){

        for(int i = 0; i < 15; i++){

            gotoxy(17,8 + i);

            for(int j = 0; j < 15; j++) cout << out;

        }

        bombCount = 15;

    }

    if(lod == 3){

        for(int i = 0; i < 20; i++){

            gotoxy(10,5 + i);

            for(int j = 0; j < 20; j++) cout << out;

        }

        bombCount = 25;

    }

    randomizebombs();
    countadjacentbombs();

}

bool checkIJ(int i, int j){

    int MAX;

    if(lod == 1) MAX = 9;

    if(lod == 2) MAX = 14;

    if(lod == 3) MAX = 19;

    if(i >= 0 && i <= MAX && j >= 0 && j <= MAX) return true;

    return false;

}

void checksquares(int i, int j){

    int x,y;

    if(lod == 1){

        x = 26 + j * 3;
        y = 10 + i;

    }

    if(lod == 2){

        x = 18 + j * 3;
        y = 8 + i;

    }

    if(lod == 3){

        x = 11 + j * 3;
        y = 5 + i;

    }

    reviewed[i][j] = true;

    gotoxy(x,y);
    cout << board[j][i];

    if(board[j][i]!=0) return;

    if(board[j - 1][i - 1] != -1 && !reviewed[i - 1][j - 1] && checkIJ(i-1, j-1)==true) checksquares(i - 1, j - 1);
    if(board[j][i - 1] != -1 && !reviewed[i - 1][j] && checkIJ(i-1, j)==true) checksquares(i - 1, j);
    if(board[j + 1][i - 1] != -1 && !reviewed[i - 1][j + 1] && checkIJ(i-1, j+1)==true) checksquares(i - 1, j + 1);
    if(board[j - 1][i] != -1 && !reviewed[i][j - 1] && checkIJ(i, j-1)==true) checksquares(i, j - 1);
    if(board[j + 1][i] != -1 && !reviewed[i][j + 1] && checkIJ(i, j+1)==true) checksquares(i, j + 1);
    if(board[j - 1][i + 1] != -1 && !reviewed[i + 1][j - 1] && checkIJ(i+1, j-1)==true) checksquares(i + 1, j - 1);
    if(board[j][i + 1] != -1 && !reviewed[i + 1][j] && checkIJ(i+1, j)==true) checksquares(i + 1, j);
    if(board[j + 1][i + 1] != -1 && !reviewed[i + 1][j + 1] && checkIJ(i+1, j+1)==true) checksquares(i + 1, j + 1);

}

bool DONE(){

    bool done = true;

    for(int i = 0; i < boardsize; i++)
        for(int j = 0; j < boardsize; j++)
            if(reviewed[j][i]==false && board[i][j]!=-1) done = false;

    return done;
}

void RESET(){

    running = false;
    start = false;
    win = false;
    memset(reviewed, false, sizeof(reviewed));

}

void ENDGAME(){

    system("cls");

    gotoxy(35, 15);

    cout << "GAME OVER";

    gotoxy(23,16);

    cout << "PRESS ENTER TO GO BACK TO THE MENU";

    cin.get();

}

void Game(){

    while(!running){

        CONSOLE_SCREEN_BUFFER_INFO cinf;

        GetConsoleScreenBufferInfo(Handle, &cinf);
        int x, y;

        x = cinf.dwCursorPosition.X;
        y = cinf.dwCursorPosition.Y;

        bool input = true;
        char c;

        while(input){

            c = getch();

            switch(c) {

                case 'w':{

                    y -= 1;

                    gotoxy(x, y);

                }  //key up
                break;

                case 's':{

                    y += 1;

                    gotoxy(x, y);

                }   // key down
                break;

                case 'd':{

                    x += 1;

                    gotoxy(x, y);

                }  // key right
                break;

                case 'a':{

                    x -= 1;

                    gotoxy(x, y);

                }   // key left
                break;

                default :null:{

                    input = false;

                }
                break;

            }

        }

        int i, j;

        if(lod == 1){

            i = (x - 26) / 3;
            j = y - 10;

        }

        if(lod == 2){

            i = (x - 18) / 3;
            j = y - 8;

        }

        if(lod == 3){

            i = (x - 11) / 3;
            j = y - 5;

        }

        if(board[i][j] == -1) running = true;
        if(!reviewed[j][i]) checksquares(j,i);
        if(DONE()) { running = true; win = true; }

    }

    if(win) {

        gotoxy(33,3);

        cout << "!!!YOU WON!!!";

        cin.get();

    }

    if(running) ENDGAME();

}

int main(){

    SetConsoleTitle("MineSweeper");
    SetWindow(81,31);
    while(!quit){

        menu();
        if(quit) continue;
        drawboard();
        Game();
        RESET();

    }

}
