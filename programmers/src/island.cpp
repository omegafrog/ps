#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int dfs(int startY, int startX, vector<vector<int>> v, int **visited, int maxY, int maxX)
{
    int res = 0;
    if (v[startY][startX] == -1 || visited[startY][startX] == 1)
        return 0;
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visited[startY][startX] = 1;
    res = v[startY][startX];
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nextY = cur.first + direction[dir][0];
            int nextX = cur.second + direction[dir][1];
            if (0 <= nextY && nextY < maxY && 0 <= nextX && nextX < maxX)
            {
                if (v[nextY][nextX] != -1)
                {
                    if (visited[nextY][nextX] == 0)
                    {
                        visited[nextY][nextX] = 1;
                        q.push({nextY, nextX});
                        res += v[nextY][nextX];
                    }
                }
            }
        }
    }
    return res;
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    vector<vector<int>> v;
    int maxY = maps.size();
    int maxX = maps[0].size();
    for (int i = 0; i < maxY; ++i)
    {
        v.push_back(vector<int>());
    }
    for (int y = 0; y < maxY; ++y)
    {
        for (int x = 0; x < maxX; ++x)
        {
            char c = maps[y][x];
            if (c == 'X')
            {
                v[y].push_back(-1);
                continue;
            }
            else
            {
                v[y].push_back(c - '0');
            }
        }
    }

    int **visited = (int **)malloc(sizeof(int *) * maxY);
    for (int i = 0; i < maxY; ++i)
    {
        visited[i] = (int *)malloc(sizeof(int) * maxX);
    }
    for (int y = 0; y < maxY; ++y)
    {
        for (int x = 0; x < maxX; ++x)
        {
            visited[y][x] = 0;
        }
    }
    int res = 0;
    for (int y = 0; y < maxY; ++y)
    {
        for (int x = 0; x < maxX; ++x)
        {
            int result = dfs(y, x, v, visited, maxY, maxX);
            if (result != 0)
            {
                answer.push_back(result);
            }
        }
    }
    if (answer.size() == 0)
    {
        vector<int> res;
        res.push_back(-1);
        return res;
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main(int argc, char const *argv[])
{
    vector<string> s({"X591X", "X1X5X", "X231X", "1XXX1"});
    vector<int> res = solution(s);
    return 0;
}
