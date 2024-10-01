#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long long x;
    int n;
    int a, b;

    cin >> x;
    cin >> n;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        res += a * b;
    }
    cout << ((res == x) ? "Yes" : "No");

    return 0;
}
