#include <iostream>
using namespace std;
#include <vector>

int main(int argc, char const *argv[])
{
    vector<int> v(42, 0);
    for (int i = 0; i < 10; i++)
    {
        int tmp;
        cin >> tmp;
        int idx = tmp % 42;
        v[idx] += 1;
    }
    int cnt = 0;
    for (int i : v)
    {
        if (i != 0)
            cnt++;
    }
    cout << cnt;

    return 0;
}
