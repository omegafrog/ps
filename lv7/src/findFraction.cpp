#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    for (int i = 0;; i++)
    {
        int n = (i * i - i) / 2 + 1;
        v.push_back(n);
        if (n > 10000000)
            break;
    }
    int x;
    cin >> x;
    int sum = 0;
    int start;
    bool leftBigger = false;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] <= x && x < v[i + 1])
        {
            sum = i + 1;
            start = v[i];
            if (i % 2 == 1)
            {
                leftBigger = true;
            }
        }
    }
    if (leftBigger)
    {
        cout << sum - (x - start + 1) << "/" << x - start + 1;
    }
    else
    {
        cout << x - start + 1 << "/" << sum - (x - start + 1);
    }

    return 0;
}
