#include<iostream>

int main() {

    int n;
    std :: cin >> n;

    int a[n], s[n];

    for(int i = 0; i < n; i++){
        std :: cin >> a[i];
    }

    s[0] = 1;

    for(int i = 1; i < n; i++){
        int max = 0;
        for(int j = i; j >= 0; j--){
            if(a[j] < a[i]){
                if(max < s[j]) max = s[j];
            }
        }
        s[i] = max + 1;
    }

    int max = 0;

    for(int i = 0; i < n; i++){
        if(max < s[i]) max = s[i];
    }

    std :: cout << max;
}
