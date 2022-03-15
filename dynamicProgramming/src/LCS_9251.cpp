#include <iostream>
#include <vector>
using namespace std;

int **cache;
string s1, s2;
int getLCS(int n1, int n2)
{
    if (s1.size() <= n1 || s2.size() <= n2)
    {
        return 0;
    }
    int &ret = cache[n1][n2];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;
    if (s1[n1] == s2[n2])
    {
        ret = 1 + getLCS(n1 + 1, n2 + 1);
    }
    else
    {
        ret = max(getLCS(n1 + 1, n2), getLCS(n1, n2 + 1));
    }
    return ret;
}

int main()
{
    cin >> s1;
    cin >> s2;
    cache = new int *[s1.size()];
    for (int i = 0; i < s1.size(); ++i)
    {
        cache[i] = new int[s2.size()];
        for (int j = 0; j < s2.size(); ++j)
        {
            cache[i][j] = -1;
        }
    }
    int ret = getLCS(0, 0);
    cout << ret;
}