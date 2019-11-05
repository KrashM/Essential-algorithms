#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

bool check(std :: string str)
{
    int n = str.length();

    if (n == 0 && n == 1)
        return false;

    if (n == 2)
        return (((str[n-2]-'0')*10 +
                 (str[n-1]-'0'))%16 == 0);

    if(n == 3)
         return ( ((str[n-3]-'0')*100 +
                   (str[n-2]-'0')*10 +
                   (str[n-1]-'0'))%16 == 0);


    int last = str[n-1] - '0';
    int second_last = str[n-2] - '0';
    int third_last = str[n-3] - '0';
    int fourth_last = str[n-4] - '0';
    return ((fourth_last*1000 + third_last*100 +
             second_last*10 + last) % 16 == 0);
}
int main(){

    int n, ind = 0, maxind = 0;
    unsigned long long br = 0;
    std :: cin >> n;

    std :: string numbers;

    int vurt = 10;

    for(int i = 0; i <= n / 10; i++){
        if(i == n / 10) vurt = n % 10;
        for(int j = 1; j <= vurt; j++){
            if(i == 0 && j < 10) numbers += '0' + j;
            else if(i == 0 && j == 10) {
                numbers += '0' + i + 1;
                numbers += '0';
            }
            else {
                if(j < 10) {
                    numbers += '0' + i;
                    numbers += '0' + j;
                }
                else {
                    numbers += '0' + i + 1;
                    numbers += '0';
                }
            }
        }
    }

    do{

        if(check(numbers)) br++;

    } while(std :: next_permutation(numbers.begin(), numbers.end()));


        std :: cout << br << '\n';

}
