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
};
int main()
{
    int n;
    cin >> n;
    Solution a;
    auto i = a.countBits(n);
    for (auto res : i)
    {
        cout << res << "\n";
    }
}