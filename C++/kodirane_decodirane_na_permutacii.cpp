#include<iostream>
#include<vector>

using namespace std;

vector <int> p;

int main(){
    int n, k, c;
    cin >> n >> k;
    c = k;
    n -= 1;
    int solution[k], fact[k + 1], j = 0;
    fact[0] = 1;
    p.push_back(0);
    for(int i = 1; i <= k; i++){
        p.push_back(i);
        fact[i] = fact[i - 1] * i;
    }
    while(n > 0){
        int  r = n / fact[k - 1];
        solution[j] = p[r + 1];
        p.erase(p.begin() + r + 1);
        j++;
        n -= r * fact[k - 1];
        k--;
    }
    solution[j] = p[1];
    for(int i = 0; i < c; i++)
        cout << solution[i] << " ";
}
