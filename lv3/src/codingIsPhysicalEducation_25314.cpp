#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int res = 0;
    if (n % 4 != 0)
    {
        res = n / 4 + 1;
    }
    else
    {
        res = n / 4;
    }
    for (int i = 0; i < res; i++)
    {
        cout << "long ";
    }
    cout << "int";

    return 0;
}
