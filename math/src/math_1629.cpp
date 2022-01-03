#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    long long A;
    long long B;
    long long C;
    cin >> A >> B >> C;
    bitset<32> bit_B(B);
    long long dup_B = B;
    // B의 최대 비트 크기 (len)
    int len_B = 0;
    while (dup_B > 0)
    {
        dup_B = dup_B >> 1;
        len_B++;
    }
    // moded[0] => A^1
    // moded[i] => A^(i+1)
    long long moded[len_B];
    moded[0] = A % C;
    for (int i = 1; i < len_B; ++i)
    {
        moded[i] = (moded[i - 1] * moded[i - 1]) % C;
    }
    long long ret = 1;
    for (int i = 0; i < len_B; ++i)
    {
        if (bit_B[i] == 1)
        {
            ret = (ret * moded[i]) % C;
        }
    }
    cout << ret;
}