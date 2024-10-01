#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int c;
    cin >> c;
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == c)
            res++;
    }
    cout << res;

    return 0;
}
