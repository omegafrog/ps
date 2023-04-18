#include <iostream>

#include <string>
#include <vector>
#define INF 987654321

using namespace std;

int smallest(int x, int y, int n, int *mem)
{

    if (x == y)
    {
        return 0;
    }

    mem[x] = 0;
    for (int i = x; i < y + 1; ++i)
    {
        if (mem[i] == INF)
            continue;
        if (i * 3 <= y)
            mem[i * 3] = min(mem[i] + 1, mem[i * 3]);
        if (i * 2 <= y)
            mem[i * 2] = min(mem[i] + 1, mem[i * 2]);
        if (i + n <= y)
            mem[i + n] = min(mem[i] + 1, mem[i + n]);
    }
    if (mem[y] == INF)
        return -1;

    return mem[y];

}

int solution(int x, int y, int n)
{
    int answer = 0;
    int *mem = (int *)malloc(sizeof(int) * (y + 1));
    for (int i = 0; i < y + 1; ++i)
    {
        mem[i] = INF;
    }
    answer = smallest(x, y, n, mem);
    if (answer >= INF)
    {
        answer = -1;
    }
    if (x == y)
    {
        return 0;
    }
    return answer;
}

int main()
{
    cout << solution(1, 1000000, 1);
}