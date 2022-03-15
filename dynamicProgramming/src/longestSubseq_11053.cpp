#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int *cache;
vector<int> sequence;

int subseq(int n)
{
    if (n >= N)
        return 0;
    int &ret = cache[n];
    if (ret != -1)
    {
        return ret;
    }
    ret = 1;
    int next = 0;
    for (int i = n + 1; i < N; ++i)
    {
        if (sequence[i] > sequence[n])
        {
            next = max(next, subseq(i));
        }
    }
    ret = ret + next;
    return ret;
}
int main()
{
    cin >> N;
    int k;
    cache = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        sequence.push_back(k);
        cache[i] = -1;
    }
    int res = 0;
    for (int i = 0; i < N; ++i)
    {
        res = max(res, subseq(i));
    }
    cout << res;
}