#include<iostream>

int main(){

    std :: string a, b;

    std :: cin >> a >> b;

    int x = a.length();
    int y = b.length();

    int dinamic[x][y];

    if(a[0] == b[0]) dinamic[0][0] = 1;
    else dinamic[0][0] = 0;

    for(int i = 1; i < x; i++){
        if(a[i] == b[0]){
            dinamic[0][i] = 1;
            continue;
        }
        if(dinamic[0][i - 1] != 0){
            dinamic[0][i] = 1;
        }

    }

    for(int j = 1; j < y; j++){
        if(b[j] == a[0]){
            dinamic[j][0] = 1;
            continue;
        }
        if(dinamic[j - 1][0] != 0){
            dinamic[j][0] = 1;
        }
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            std :: cout << dinamic[j][i] << ' ';
        }
        std :: cout << '\n';
    }
}
