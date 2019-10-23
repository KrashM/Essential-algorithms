#include<iostream>
#include<vector>

using namespace std;

vector <int> p;

int main(){
    int n;
    cin >> n;
    int fact[n] = {1}, solution = 0, r;
    bool used[n] = {false};
    for(int i = 1; i < n; i++){
        fact[i] = fact[i - 1] * i;
        cin >> r;
        p.push_back(r);
    }
    for(int i = 1; i < n; i++){
        int br = p[i - 1] - 1;
        used[p[i - 1]] = true;
        for(int j = p[i - 1] - 1; j > 0; j--) if(used[j]) br--;
        solution += br * fact[n - i];
    }
    cout << solution + 1 << '\n';
}
