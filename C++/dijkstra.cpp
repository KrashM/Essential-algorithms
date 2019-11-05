#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector <pair<int, int> > v[100];
int n,m,h,x,y,l,dist[100],r,Min = (1<<30),cur;
bool hospital[100];
priority_queue <pair<int, int> > q;

void Optimize(int x)
{
    for(int i = 0; i < v[x].size(); i++)
        if(dist[ v[x][i].second ] > dist[x] + v[x][i].first)
            {
                dist[v[x][i].second] = dist[x] + v[x][i].first;
                q.push(make_pair(-1 * dist[v[x][i].second], v[x][i].second));
            }
}

int main()
{
    cin >> n >> m >> h;
    for(int i = 0; i < h; i++)
    {
        cin >> r;
        hospital[r] = true;
    }

    for(int j = 0; j < m; j++)
    {
        cin >> x >> y >> l;
        v[x].push_back(make_pair(l,y));
        v[y].push_back(make_pair(l,x));
    }

    for(int x = 1; x <= n; x++)

    if(hospital[x])
    {
        for(int i = 1; i <= n; i++)
        {
            dist[i] = (1<<30);
        }
        dist[x] = 0;
        q.push(make_pair(-dist[x],x));
        while(!q.empty())
        {
            x = q.top().second;
            q.pop();
            Optimize(x);
        }
        cur = 0;
        for(int i = 1; i <= n; i++)
            if(!hospital[i])
                cur += dist[i];
        if(cur < Min) Min = cur;
    }
    cout << Min << endl;
}
/*
6 9
1 2 7
1 6 14
1 3 9
2 4 15
3 4 11
6 5 9
5 4 6
3 6 2
2 3 10
*/
