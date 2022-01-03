#include <iostream>
using namespace std;

// test case
int T;
// n
int N;

//memoization
// 출력시 3개의 수를 더하기 때문에 long long int가 필요하다.
long long cache[100001][4];

void sum123(int cur)
{
    // 4부터 100000의 수까지 구함
    for (int i = 4; i <= cur; ++i)
    {
        for (int last = 1; last < 4; ++last)
        {
            // 구하려는 숫자가 마지막이 1로 끝나는 경우
            if (last == 1)
            {
                cache[i][last] = (cache[i - last][2] + cache[i - last][3]) % 1000000009;
            }
            // 구하려는 숫자가 마지막이 2로 끝나는 경우
            else if (last == 2)
            {
                cache[i][last] = cache[i - last][1] % 1000000009 + cache[i - last][3] % 1000000009;
            }
            // 구하려는 숫자가 마지막이 3으로 끝나는 경우
            else if (last == 3)
            {
                cache[i][last] = cache[i - last][2] % 1000000009 + cache[i - last][1] % 1000000009;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 100001; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cache[i][j] = 0;
        }
    }
    cache[1][1] = 1;
    cache[1][2] = 0;
    cache[1][3] = 0;

    cache[2][1] = 0;
    cache[2][2] = 1;
    cache[2][3] = 0;

    cache[3][1] = 1;
    cache[3][2] = 1;
    cache[3][3] = 1;

    sum123(100000);
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cout << (cache[N][1] + cache[N][2] + cache[N][3]) % 1000000009 << "\n";
    }
}