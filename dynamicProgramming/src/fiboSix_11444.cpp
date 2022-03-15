#include <iostream>
#include <math.h>
using namespace std;

// high, low의 최대 자릿수
#define CIPHER_COUNT 18
#define MOD_NUM 1000000007
static const long long CIPHER = pow(10, CIPHER_COUNT);
int N;

typedef struct BigInt
{
    long long high;
    long long low;
} BigInt;
BigInt operator%(const BigInt &oprand1, const long long a)
{
    long long ret = 0;
    ret += ((oprand1.high % a) * (CIPHER % a)) % a;
    ret += oprand1.low % a;
    return {0, ret % a};
}
BigInt operator+(const BigInt &oprand1, const BigInt &oprand2)
{
    long long newHigh = 0;
    long long newLow = 0;
    newLow = ((oprand1.low % CIPHER + oprand2.low % CIPHER) % CIPHER);
    if (oprand1.low + oprand2.low >= CIPHER)
    {
        newHigh = oprand1.low + oprand2.low / CIPHER;
    }
    newHigh += oprand1.high + oprand2.high;
    return {newHigh, newLow};
}

int main()
{

    cin >> N;
    BigInt first = {0, 0};
    BigInt second = {0, 1};
    BigInt res = {0, 0};
    for (int i = 2; i <= N; ++i)
    {
        res = (second % MOD_NUM + first % MOD_NUM) % MOD_NUM;
        first = second;
        second = res;
    }
    cout << res.low;
}