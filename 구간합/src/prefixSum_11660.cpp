#include <iostream>
#define pair pair<int, int>
using namespace std;

void comulativeSum(int **table, long **sum, int n)
{
    sum[0][0] = table[0][0];
    for (int y = 1; y < n; y++)
    {
        sum[y][0] = table[y][0] + sum[y - 1][0];
    }
    for (int x = 1; x < n; x++)
    {
        sum[0][x] = table[0][x] + sum[0][x - 1];
    }
    for (int y = 1; y < n; y++)
    {
        for (int x = 1; x < n; x++)
        {
            sum[y][x] = sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1] + table[y][x];
        }
    }
}

long solution(long **sum, int startY, int startX, int endY, int endX)
{
    long sum1 = sum[endY][endX];
    long sum2 = 0;
    if (startY - 1 >= 0)
        sum2 = sum[startY - 1][endX];
    long sum3 = 0;
    if (startX - 1 >= 0)
        sum3 = sum[endY][startX - 1];
    long sum4 = 0;
    if (startX - 1 >= 0 && startY - 1 >= 0)
        sum4 = sum[startY - 1][startX - 1];
    return sum1 - sum2 - sum3 + sum4;
}

int main(int argc, char const *argv[])
{

    int n, m;
    cin >> n >> m;

    int **table = (int **)malloc(sizeof(int *) * n);
    for (int y = 0; y < n; y++)
    {
        table[y] = (int *)malloc(sizeof(int) * n);
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> table[y][x];
        }
    }
    long **sum = (long **)malloc(sizeof(long *) * n);
    for (int i = 0; i < n; i++)
    {
        sum[i] = (long *)malloc(sizeof(long) * n);
    }
    comulativeSum(table, sum, n);

    for (int i = 0; i < m; i++)
    {
        int x1, x2, y1, y2;
        int startY, startX;
        int endY, endX;
        cin >> y1 >> x1;
        cin >> y2 >> x2;
        if (y1 > y2)
        {
            startY = y2;
            endY = y1;
        }
        else
        {
            startY = y1;
            endY = y2;
        }
        if (x1 > x2)
        {
            startX = x2;
            endX = x1;
        }
        else
        {
            startX = x1;
            endX = x2;
        }
        startX--;
        endX--;
        startY--;
        endY--;
        if (startX == endX && startY == endY)
        {
            cout << table[endY][endX];
        }
        else
        {
            long sum1 = sum[endY][endX];
            long sum2 = 0;
            if (startY - 1 >= 0)
                sum2 = sum[startY - 1][endX];
            long sum3 = 0;
            if (startX - 1 >= 0)
                sum3 = sum[endY][startX - 1];
            long sum4 = 0;
            if (startX - 1 >= 0 && startY - 1 >= 0)
                sum4 = sum[startY - 1][startX - 1];
            printf("%d\n", sum1 - sum2 - sum3 + sum4);
        }
    }
    return 0;
}
