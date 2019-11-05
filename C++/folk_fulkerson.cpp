#include<bits/stdc++.h>
using namespace std;
int a[100][100], flow[100][100];
int used[100], n, m, x, y, z;
bool f1 = true;
vector <int> v;

void dfs(int node);

int main(){

    cin >> n >> m;
    for(int i = 1; i <= m; i++){

        cin >> x >> y >> z;
        a[x][y] = z;

    }

    while(f1){

        memset(used, 0, sizeof(used));
        v.clear();
        f1 = false;
        dfs(1);

    }

    int p = 0;

    for(int i = 1; i <= n; i++) p = p + flow[i][n];

    cout << p << '\n';

}

void dfs(int node){

    v.push_back(node);
    used[node] = 1;
    if(node == n){

        int min = a[v[0]][v[1]];

        f1 = true;

        for(int i = 1; i < v.size(); i ++){

            a[v[i - 1]][v[i]] -= min;
            a[v[i]][v[i - 1]] += min;
            flow[v[i - 1]][v[i]] += min;

        }

    }

    if(f1) return;

    for(int i = 1; i <= n; i++){

        if(a[node][i] != 0 && !used[i]){

            dfs(i);
            used[i] = 0;
            v.pop_back();

        }

    }
}
/*
6 10
1 2 16
1 3 13
2 3 10
3 2 4
2 4 12
3 5 14
4 3 9
5 4 7
4 6 20
5 6 4
*/
