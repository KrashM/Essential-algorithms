#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <random>
#include <direct.h>

std :: fstream newfile;

bool flag;

void Menu();
std :: string Name();
std :: string OpenFile();
void Create();
void Add();
void Read();

int main(){

    mkdir("D:/Dictionaries");

    int n;

    do{

        Menu();

        std :: cin >> n;

        if(n == 1) Create();
        if(n == 2) Add();
        if(n == 3) Read();
        if(n == 4) return 0;

    }while(n > 0 && n < 5);

}

void Menu(){

    std :: cout << "1.Create\n2.Add\n3.Read\n4.Exit\nPress any number: ";

}

std :: string RandomName(){

    std :: string string = "D:\\Dictionaries\\";

    for(int i = 0; i < 10; i++){

        int rnd = rand() % 62;

        if(rnd < 26) string += 'a' + rnd;
        else if(rnd < 52) string += 'A' + rnd - 26;
        else string += '0' + rnd - 52;

    }

    string += ".txt";

    return string;

}

std :: string OpenFile(){

    std :: string fileName;

    std :: cout << "Open File: ";

    std :: cin >> fileName;

    system("cls");

    return fileName;

}

void Create(){

    system("cls");

    std :: cout << "File Name: ";

    std :: string name;

    std :: cin >> name;

    //Switch between random name and user input
    //name = RandomName();
    name = "D:\\Dictionaries\\" + name;

    newfile.open(name, std :: ios :: out);

    std :: cout << "File Created\n";

    system("pause");

    flag = true;

    Add();

}

void Add(){

    system("cls");

    if(!flag){

        std :: string dir;

        dir = "D:\\Dictionaries\\" + OpenFile();

        newfile.open(dir, std :: ios :: in);

    }

    while(true){
        std :: string number, firstname, secondname;

        std :: cout << "Name: ";
        std :: cin >> firstname;
        std :: cout << "Family: ";
        std :: cin >> secondname;
        std :: cout << "Number: ";
        std :: cin >> number;

        newfile << firstname << ' ' << secondname << ' ' << number << '\n';

        std :: cout << "Add more?(Y/N): ";

        char x;

        std :: cin >> x;

        if(x == 'n' || x == 'N') break;

    }

    flag = false;

    newfile.close();

    system("cls");


}

void Read(){

    system("cls");

    std :: string dir;

    dir = "D:\\Dictionaries\\" + OpenFile();

    newfile.open(dir, std :: ios :: in);

    std :: string rand;

    int n = 0;

    while(newfile >> rand){

        n++;

        if(n != 3) std :: cout << rand << ' ';
        else {
            std :: cout << rand << '\n';
            n = 0;
        }

    }

    newfile.close();

    system("pause");

    system("cls");

}
