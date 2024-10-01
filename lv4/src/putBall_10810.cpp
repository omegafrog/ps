#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < m; i++)
    {
        int start, end, num;
        cin >> start >> end >> num;
        for (int j = start-1; j < end; j++)
        {
            v[j] = num;
        }
    }

    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}
