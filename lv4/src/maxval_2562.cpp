#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int maxVal = -987654321;
    for (int i = 0; i < 9; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        maxVal = max(maxVal, tmp);
    }
    cout << maxVal << "\n";
    for (int i = 0; i < 9; i++)
    {
        if (v[i] == maxVal)
            cout << i + 1;
    }

    return 0;
}
