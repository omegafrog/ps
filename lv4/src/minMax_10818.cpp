#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int minVal = 987654321;
    int maxVal = -987654321;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        minVal = min(tmp, minVal);
        maxVal = max(tmp, maxVal);
    }
    cout << minVal << " " << maxVal;
    return 0;
}
