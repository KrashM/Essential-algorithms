#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector <pair <int,int> > a[100];
int x,y,z,v,r,dist[100],ran;
priority_queue <pair <int, int> > q;

void optimize(int x)
{
    for(int i = 0; i < a[x].size(); i++)
        if(dist[a[x][i].second] > dist[x] + a[x][i].first)
        {
            dist[a[x][i].second] = dist[x] + a[x][i].first;
            q.push({-dist[a[x][i].second],a[x][i].second});
        }
}

int main()
{
    cin >> v >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> x >> y >> z;
        a[x].push_back(make_pair(z,y));
        a[y].push_back(make_pair(z,x));
    }

    for(int i = 1; i <= v; i++)
        dist[i] = (1<<30);

    cin >> x;

    dist[x] = 0;
    q.push({-dist[x], x});
    while(!q.empty())
        {
            ran = q.top().second;
            q.pop();
            optimize(ran);
        }



    for(int i = 1; i <= v; i++)
        cout << dist[i] << " ";
    cout << endl;
}
/*
6 9
1 2 7
2 3 10
1 3 9
1 6 14
2 4 15
3 4 11
3 6 2
6 5 9
4 5 6
*/
