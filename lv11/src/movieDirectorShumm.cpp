#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 666; i <= 66670000; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.length() - 2; j++)
        {
            int c1 = s[j];
            int c2 = s[j + 1];
            int c3 = s[j + 2];
            if (c1 == '6' && c2 == '6' && c3 == '6')
            {
                N = N - 1;
                if (N == 0)
                {
                    cout << i;
                    return 0;
                }
                break;
            }
        }
    }
}
