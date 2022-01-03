#include <iostream>
using namespace std;

enum color
{
    RED,
    GREEN,
    BLUE
};

int **cost;
int **cache;

int color(int k, int c)
{
    int &ret = cache[k][c];
    if (ret != 0)
    {
        return ret;
    }
    if (k == 1)
    {
        return cost[1][c];
    }
    switch (c)
    {
    case RED:
        ret = min(color(k - 1, GREEN), color(k - 1, BLUE)) + cost[k][RED];
        break;
    case GREEN:
        ret = min(color(k - 1, RED), color(k - 1, BLUE)) + cost[k][GREEN];
        break;
    case BLUE:
        ret = min(color(k - 1, RED), color(k - 1, GREEN)) + cost[k][BLUE];
        break;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    cost = new int *[n + 1];
    cache = new int *[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cache[i] = new int[3];
        cache[i][0] = 0;
        cache[i][1] = 0;
        cache[i][2] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cost[i] = new int[3];
        for (int k = 0; k < 3; ++k)
        {
            int c;
            cin >> c;
            cost[i][k] = c;
        }
    }
    cout << min(color(n, RED), min(color(n, GREEN), color(n, BLUE)));
}