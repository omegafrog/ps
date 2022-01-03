#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> duration;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        int k;
        cin >> k;
        duration.push_back(k);
    }
    sort(duration.begin(), duration.end());
    int res = 0;
    for (int i = num; i > 0; --i)
    {
        res += i * duration[num - i];
    }
    cout << res;
}