#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;
#define CIPHER_COUNT 18
static const long long CIPHER = pow(10, CIPHER_COUNT);
typedef struct bigInt
{
    long long high;
    long long low;
} bigInt;
bigInt **cache;

bigInt addBigInt(bigInt a, bigInt b)
{

    long long tlow = (a.low % CIPHER + b.low % CIPHER) % CIPHER;
    long long thigh = 0;
    if (a.low + b.low >= CIPHER)
    {
        thigh = (a.low + b.low) / CIPHER;
    }
    thigh += a.high + b.high;
    return {thigh, tlow};
}
bigInt combination(int n, int m)
{
    if (m > n - m)
    {
        m = n - m;
    }
    if (m == 0)
    {
        return {0, 1};
    }
    bigInt &ret = cache[n][m];
    if (ret.low != -1)
    {
        return ret;
    }
    ret = addBigInt(combination(n - 1, m - 1), combination(n - 1, m));

    return ret;
}

int main()
{
    int N;
    int M;
    cin >> N >> M;
    cache = new bigInt *[101];
    for (int i = 0; i <= 100; ++i)
    {
        cache[i] = new bigInt[101];
        for (int j = 0; j <= 100; ++j)
        {
            cache[i][j] = {0, -1};
        }
    }

    bigInt ret = {0, 0};
    ret = combination(N, M);
    if (ret.high != 0)
    {
        cout << ret.high;
        cout.width(18);
        cout.fill('0');
    }

    cout << ret.low;
}