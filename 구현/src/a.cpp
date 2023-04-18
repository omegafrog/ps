#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int biggest = -1;
    int res;
    cin >> a >> b >> c;
    if (a == b&&b == c&&c==a )
    {
        res = 10000 + a * 1000;
    }
    else if (a == b || b == c || c == a)
    {
        if (a == b)
            res = 1000 + a * 100;
        if (b == c)
            res = 1000 + b * 100;
        if (c == a)
            res = 1000 + c * 100;
    }
    else
    {
        biggest = max(a, max(b, c));
        res = biggest * 100;
    }
    cout << res;
}
