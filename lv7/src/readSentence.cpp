#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char board[5][15];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = '\0';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j)
        {
            board[i][j] = s[j];
        }
    }
    for (int i = 0; i < 15; i++)
    {
        if (board[0][15] == '\0')
            continue;
        string s2;
        for (int j = 0; j < 5; j++)
        {
            if (board[j][i] == '\0')
                continue;
            s2 += board[j][i];
        }
        if (s2.length() != 0)
            cout << s2;
    }

    return 0;
}
