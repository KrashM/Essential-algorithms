#include <iostream>
using namespace std;

int x, y;

int extEuclid(int a, int b){

    //a = a*x1 + b*y1
    //b = a*x2 + b*y2

    int x1 = 1, y1 = 0, x2 = 0, y2 = 1, q, r, t;
    while(b != 0){

        q = a / b;
        //a%b = a - [a/b]*b;

        r = a % b;
        a = b;
        b = r;

        t = x1 - q * x2;
        x1 = x2;
        x2 = t;

        t = y1 - q * y2;
        y1 = y2;
        y2 = t;
    }

    x = x1;
    y = y1;
    return a;
}

int main(){

    int x0, y0;
    int a, b, c, d;
    cin >> a >> b >> c;

    d = extEuclid(a, b);
    //cout << x << ' ' << y << ' ' << d << '\n';

    if(c%d==0)
    {
        a /= d;
        b /= d;
        c /= d;

        x0 = x*c;
        y0 = y*c;
        for(int k = -c;k<=c;k++)
        {
            cout << x0 + b*k << " " << y0 - a*k << '\n';
        }
    }
}
