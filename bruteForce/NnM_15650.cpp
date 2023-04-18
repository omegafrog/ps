#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;

void solution(int n, int m, int idx, int start, vector<int> &v)
{
    if (idx == m)
    {
        res.push_back(v);
        return;
    }
    for (int i = start; i <= n; i++)
    {
        v.push_back(i);
        solution(n, m, idx + 1, i + 1, v);
        v.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    solution(n, m, 0, 1, v);
    for (auto it = res.begin(); it != res.end(); ++it)
    {
        vector<int> vv = *it;
        for (auto iter = vv.begin(); iter != vv.end(); ++iter)
        {

            cout << *iter << " ";
        }
        cout << "\n";
    }
    return 0;
}
