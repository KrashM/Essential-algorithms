#include<iostream>
using namespace std;

int CNK[101][101], n, k, perm[101];
bool used[101];

void print(int x)
{
    for(int i = 1; i <= x; i++)
        cout << perm[i];
    cout << '\n';
}

void combinations(int n, int k)
{
    for(int i = 0; i <= n; i++)
    {
        CNK[i][0] = 1;
        CNK[i][i] = 1;
    }
    for(int i = 1; i <=n; i++)
        for(int j = 1; j <= n; j++)
            CNK[i][j] = CNK[i - 1][j - 1] + CNK[i - 1][j];
    //cout << CNK[n][k] << '\n';
}

void permutations(int j)
{
    for (int i = 1; i <= n; i++)
        if(!used[i])
        {
            perm[j] = i;
            used[i] = 1;
            if(j == n) print(n);
            else permutations(j + 1);
            used[i] = 0;
        }
}

void variations(int j)
{
    for (int i = 1; i <= n; i++)
        if(!used[i])
        {
            perm[j] = i;
            used[i] = 1;
            if(j == k) print(k);
            else variations(j + 1);
            used[i] = 0;
        }
}


int main()
{
    cin >> n >> k;
    //combinations(n,k);
    cout << '\n';
    //permutations(1);
    cout << '\n';
    //variations(1);
}
