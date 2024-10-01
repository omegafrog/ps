#include <iostream>
using namespace std;
#define MINF -987654321

int matrix[9][9];

int main(int argc, char const *argv[])
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cin >> matrix[y][x];
        }
    }

    int res = MINF;
    int maxY, maxX;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (res < matrix[y][x])
            {
                maxY = y;
                maxX = x;
                res = matrix[y][x];
            }
        }
    }

    cout << res << "\n"
         << maxY + 1 << " " << maxX + 1;
    return 0;
}
