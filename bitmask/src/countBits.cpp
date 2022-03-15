#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1);
        res[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            res[i] = res[i / 2] + i % 2;
        }
        return res;
    }
    vector<int> countBits2(int n)
    {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int tmp = 0;
            int cur = i;
            while (cur > 1)
            {
                if (cur % 2 == 1)
                {
                    tmp++;
                }
                cur /= 2;
            }
            if (cur == 1)
            {
                tmp++;
            }
            res[i] = tmp;
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution a;
    auto i = a.countBits(n);
    auto i2 = a.countBits2(n);
    for (auto res : i)
    {
        cout << res << "\n";
    }
    cout << "\n";
    for (auto res : i2)
    {
        cout << res << "\n";
    }
}