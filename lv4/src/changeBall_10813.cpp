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
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        int tmp;
        tmp = v[from - 1];
        v[from - 1] = v[to - 1];
        v[to - 1] = tmp;
    }
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}
