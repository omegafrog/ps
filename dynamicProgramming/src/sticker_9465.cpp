#include <iostream>
#include <vector>
using namespace std;

int **sticker;
int **cache;
int N;
vector<int> res;
int main()
{
    int tcase;
    cin >> tcase;
    for (int z = 0; z < tcase; ++z)
    {
        cin >> N;
        sticker = new int *[2];
        cache = new int *[2];
        cache[0] = new int[N + 1];
        cache[1] = new int[N + 1];

        for (int row = 0; row < 2; ++row)
        {
            sticker[row] = new int[N + 1];
            for (int i = 1; i <= N; ++i)
            {
                int input;
                cin >> input;
                sticker[row][i] = input;
                cache[row][i] = -1;
            }
        }
        cache[1][0] = 0;
        cache[0][0] = 0;
        cache[0][1] = sticker[0][1];
        cache[1][1] = sticker[1][1];
        int ret = 0;
        for (int i = 2; i <= N; ++i)
        {
            cache[0][i] = max(cache[1][i - 2], cache[1][i - 1]) + sticker[0][i];
            cache[1][i] = max(cache[0][i - 2], cache[0][i - 1]) + sticker[1][i];
        }
        ret = max(cache[0][N], cache[1][N]);
        res.push_back(ret);
    }
    for (int a : res)
    {
        cout << a << "\n";
    }
}