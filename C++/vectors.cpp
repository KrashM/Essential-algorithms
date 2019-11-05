#include<iostream>
using namespace std;

struct Points{
    int x, y;
};

int main(){
    Points p1, p2, q;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> q.x >> q.y;
    int s;
    if(p1.x * p1.y == p2.x * p2.y && p2.x * p2.y == q.x * q.y) {
        s = (p1.x * p2.y + p2.x * q.y + q.x * p1.y - p1.x * q.y - p2.y * p1.y - q.x * q.y) / 2; cout << s << '\n'; cout << s * 2 / (p2.x - p1.x * p2.y - p1.y) << '\n';
    }
}
