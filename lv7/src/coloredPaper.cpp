#include <iostream>
using namespace std;

int board[100][100] = {
    0,
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        for (int dy = 0; dy < 10; ++dy)
        {
            for (int dx = 0; dx < 10; ++dx)
            {
                board[y + dy][x + dx] = 1;
            }
        }
    }
    int res = 0;
    for (int y = 0; y < 100; y++)
    {
        for (int x = 0; x < 100; x++)
        {
            res = res + board[y][x];
        }
    }
    cout << res;

    return 0;
}
