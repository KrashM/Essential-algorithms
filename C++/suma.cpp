#include<iostream>
#include<cmath>
using namespace std;

int a[3010][3010],b[3010][3010],m,n,u,v,ans = (1<<30);

int suma(int i, int j)
{
    if(i == u - 1 && j == v - 1) return b[i][j];
    if(i == u - 1 && j > v - 1) return b[i][j] - b[i][j - v];
    if(i > u - 1 && j == v - 1) return b[i][j] - b[i - u][j];
    return b[i][j] - b[i - u][j] - b[i][j - v] + b[i - u][j - v];
}

void subtab()
{
    b[0][0] = a[0][0];
    for(int i = 1; i < m; i++)
        b[i][0] = a[i][0] + b[i - 1][0];
    for(int j = 1; j < n; j++)
        b[0][j] = a[0][j] + b[0][j - 1];
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> u >> v;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    subtab();
    for(int i = u-1; i < m; i++)
        for(int j = v-1; j < n; j++)
            ans = min(ans, (int)abs(suma(i, j)));

    cout << ans << '\n';
}
/*
4 5 2 3
1 -2 3 8 0
4 6 0 5 7
-3 2 3 -3 3
1 -2 3 -5 2

2
*/
