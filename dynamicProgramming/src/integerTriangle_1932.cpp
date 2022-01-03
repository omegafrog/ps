#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int *cache;
int cacheSize;
int count = 0;

int biggest(int n, vector<pair<int, int>> &a)
{
    count++;
    if (n > cacheSize)
    {
        return 0;
    }
    int &ret = cache[n];
    if (ret != -1)
        return ret;

    ret = max(biggest(n + a[n].first, a), biggest(n + a[n].first + 1, a)) + a[n].second;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    cacheSize = n * (n + 1) / 2;
    cache = new int[cacheSize + 1];

    for (int i = 0; i <= cacheSize; ++i)
    {
        cache[i] = -1;
    }
    vector<pair<int, int>> a;

    a.push_back(make_pair(0, -1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            int k;
            cin >> k;
            a.push_back(make_pair(i + 1, k));
        }
    }
    int ret = biggest(1, a);
    cout << ret;
}