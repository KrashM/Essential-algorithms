#include<iostream>
#include<stack>
using namespace std;
long long a[1000][1000],dp[1000][1000];
char put[1000][1000];

stack <char> answer;
int main ()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    put[0][0] = 'X';
    dp[0][0] = a[0][0];

    for(int i = 1; i < n; i++)
    {
        put[i][0] = 'D';
        dp[i][0] = a[i][0] + dp[i - 1][0];
    }
    for(int j = 1; j < m; j++)
    {
        put[0][j] = 'R';
        dp[0][j] = a[0][j] + dp[0][j - 1];
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if(dp[i - 1][j] > dp[i][j - 1])
            {
                put[i][j] = 'D';
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
            else
            {
                put[i][j] = 'R';
                dp[i][j] = dp[i][j - 1] + a[i][j];
            }
        }
    cout << dp[n - 1][m - 1] << endl;

    int i = n - 1, j = m - 1;
    while(put[i][j]!='X')
    {
        //cout << put[i][j] << " ";
        answer.push(put[i][j]);

        if(put[i][j]=='D') i--;
        else j--;
    }

    while(answer.empty()==false)
    {
        cout << answer.top() << " ";
        answer.pop();
    }
    cout << '\n';
}
/*
3 4
1 1 2 1
2 2 1 1
2 1 2 1
*/
