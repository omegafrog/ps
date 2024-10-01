#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }
    vector<int> res(v);
    for (int i = 0; i < m; i++)
    {
        int begin, mid, end;
        cin >> begin >> end >> mid;
        begin--;
        mid--;
        end--;
        v.clear();
        vector<int> v1(res.begin() + begin, res.begin() + mid);
        vector<int> v2(res.begin() + mid, res.begin() + end + 1);
        for (auto it = res.begin(); it != res.begin() + begin; ++it)
        {
            v.push_back(*it);
        }
        for (int j : v2)
        {
            v.push_back(j);
        }
        for (int j : v1)
        {
            v.push_back(j);
        }
        for (auto it = res.begin() + end + 1; it != res.end(); ++it)
        {
            v.push_back(*it);
        }
        res = vector<int>(v);
        v.clear();
    }
    for (int j : res)
    {
        cout << j << " ";
    }
    return 0;
}
