#include <iostream>
using namespace std;

int *board;
int N;
int cnt = 0;

void nQueen(int numOfQueen)
{
    if (numOfQueen == N)
    {
        cnt += 1;
        return;
    }
    int ret = 0;
    for (int x = 0; x < N; ++x)
    {
        int flag = 1;
        for (int i = 0; i < numOfQueen; ++i)
        {
            if (board[i] == x)
            {
                flag = 0;
                break;
            }
            if (abs(numOfQueen - i) == abs(board[i] - x))
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            board[numOfQueen] = x;
            nQueen(numOfQueen + 1);
        }
    }
}
int main()
{
    while (true)
    {
        cin >> N;
        cnt = 0;
        board = new int[N];
        for (int i = 0; i < N; ++i)
        {
            board[i] = -1;
        }
        nQueen(0);
        cout << cnt;
    }
}