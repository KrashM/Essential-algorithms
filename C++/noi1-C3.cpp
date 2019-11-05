#include<iostream>
#include<algorithm>

int main(){

    const long long mod = 1e9 + 7;
    long long answer = 0, fact = 1;
    int n, array[4];

    std :: cin >> n;

    for(int i = 1; i <= n - 4; i++){
        fact = (fact * i) % mod;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                for(int l = k + 1; l <= n; l++){
                    array[0] = i;
                    array[1] = j;
                    array[2] = k;
                    array[3] = l;
                    do{
                        int rnd = 0;
                        for(int m = 0; m < 4; m++){
                            if(array[m] > 9) rnd = rnd * 100 + array[m];
                            else rnd = rnd * 10 + array[m];
                        }
                        if(rnd % 16 == 0) answer = (answer + fact) % mod;
                    }while(std :: next_permutation(array, array + 4));
                }
            }
        }
    }


    std :: cout << answer << '\n';

}
