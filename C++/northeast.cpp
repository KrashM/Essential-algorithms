#include <iostream>

int a[20][20], b[20][20];

int main() {
    int n;
    std :: cin >> n;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            std :: cin >> a[i][k];
        }
    }

    b[0][0] = a[0][0];
    for(int i = 1; i < n; i++) b[i][0] = b[i - 1][0] + a[i][0];

    for(int k = 1; k < n; k++) b[0][k] = b[0][k - 1] + a[0][k];

    for(int i = 1; i < n; i++) {
        for(int k = 1; k < n; k++) {
            int east = a[i][k] + b[i][k - 1];
            int north = a[i][k] + b[i - 1][k];
            if(east < north) b[i][k] = east;
            else b[i][k] = north;
        }
    }
    std :: cout << b[n - 1][n - 1] << '\n';
}
/*
4
1 3 5 6
0 1 6 7
9 4 6 2
1 3 4 0
*/
