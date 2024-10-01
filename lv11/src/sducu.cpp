#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rectStartPoint[9][2] = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};

int board[9][9] = {
    0,
};
int row[9][9];
int col[9][9];
int rect[9][9];

bool flag = false;

void getNumsFromVertical(pair<int, int> &cur, vector<int> &candidate)
{
    int x = cur.second;
    for (int y = 0; y < 9; y++)
    {
        auto it = find(candidate.begin(), candidate.end(), board[y][x]);
        if (it != candidate.end())
        {
            candidate.erase(it);
        }
    }
}
void getNumsFromHorizontal(pair<int, int> &cur, vector<int> &candidate)
{
    int y = cur.first;
    for (int x = 0; x < 9; x++)
    {
        auto it = find(candidate.begin(), candidate.end(), board[y][x]);
        if (it != candidate.end())
        {
            candidate.erase(it);
        }
    }
}

void getNumsFromRect(pair<int, int> &cur, vector<int> &candidate)
{
    int y = cur.first;
    int x = cur.second;
    int pointY, pointX;

    for (int i = 8; i >= 0; --i)
    {
        pointY = rectStartPoint[i][0];
        pointX = rectStartPoint[i][1];
        if (pointY <= y && pointX <= x)
        {
            break;
        }
    }
    for (int dy = 0; dy < 3; dy++)
    {
        for (int dx = 0; dx < 3; dx++)
        {
            auto it = find(candidate.begin(), candidate.end(), board[dy + pointY][dx + pointX]);
            if (it != candidate.end())
            {
                candidate.erase(it);
            }
        }
    }
}

void fillBlank(vector<pair<int, int>> &blank)
{
    if (blank.size() == 0 && flag == false)
    {
        flag = true;
        for (int y = 0; y < 9; y++)
        {
            for (int x = 0; x < 9; x++)
            {
                cout << board[y][x] << " ";
            }
            cout << "\n";
        }
    }
    if (flag == true)
    {
        return;
    }

    pair<int, int> cur = blank.back();
    vector<int> candidate;

    int rectNum;
    for (rectNum = 8; rectNum >= 0; --rectNum)
    {
        int pointY = rectStartPoint[rectNum][0];
        int pointX = rectStartPoint[rectNum][1];
        if (pointY <= cur.first && pointX <= cur.second)
        {
            break;
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        if (row[cur.first][i] == 1 || col[cur.second][i] || rect[rectNum][i] == 1)
            continue;
        else
            candidate.push_back(i);
    }

    if (candidate.size() == 0)
    {
        return;
    }
    for (int next : candidate)
    {
        board[cur.first][cur.second] = next + 1;
        blank.pop_back();
        row[cur.first][next] = 1;
        col[cur.second][next] = 1;
        rect[rectNum][next] = 1;

        fillBlank(blank);
        blank.push_back(cur);
        board[cur.first][cur.second] = 0;
        row[cur.first][next] = 0;
        col[cur.second][next] = 0;
        rect[rectNum][next] = 0;
    }
    return;
}

int main(int argc, char const *argv[])
{
    vector<pair<int, int>> blank;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            int c;
            cin >> c;
            board[y][x] = c;

            if (c == 0)
            {
                blank.push_back({y, x});
            }
            else
            {
                row[y][c - 1] = 1;
                col[x][c - 1] = 1;
                int rectNum;
                for (rectNum = 8; rectNum >= 0; --rectNum)
                {
                    int pointY = rectStartPoint[rectNum][0];
                    int pointX = rectStartPoint[rectNum][1];
                    if (pointY <= y && pointX <= x)
                    {
                        break;
                    }
                }
                rect[rectNum][c - 1] = 1;
            }
        }
    }
    fillBlank(blank);

    return 0;
}
