#include<iostream>

int indexes[100], a[100];

void Print(int i){
    if(indexes[i] != 0) Print(indexes[i]);
    std :: cout << a[i] << ' ';
}

int main() {

    int n;
    std :: cin >> n;

    int s[n];

    for(int i = 0; i < n; i++){
        std :: cin >> a[i];
    }

    s[0] = 1;

    for(int i = 1; i < n; i++){
        int max = 0;
        for(int j = 0; j < i; j++){
            if(a[j] <= a[i] && max < s[j]){
                max = s[j];
                indexes[i] = j;
            }
        }
        s[i] = max + 1;
    }

    int max = 0, ind = 0;

    for(int i = 1; i < n; i++){
        if(max < s[i]){
            max = s[i];
            ind = i;
        }
    }

    Print(ind);

    std :: cout << '\n';

}

/*
9
9 5 2 8 7 3 1 6 4
*/
