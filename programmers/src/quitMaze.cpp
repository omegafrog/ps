#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> adj[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int bfs(pair<int, int> start, pair<int, int> end, vector<vector<int>> map, int y, int x)
{
    int **visited = (int **)malloc(sizeof(int *) * y);
    int **shortest = (int **)malloc(sizeof(int *) * y);
    for (int i = 0; i < y; ++i)
    {
        visited[i] = (int *)malloc(sizeof(int) * x);
        shortest[i] = (int *)malloc(sizeof(int) * x);
    }

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            visited[i][j] = 0;
            shortest[i][j] = 0;
        }
    }
    visited[start.first][start.second] = 1;
    shortest[start.first][start.second] = 0;
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nextY = adj[direction].first + cur.first;
            int nextX = adj[direction].second + cur.second;
            if (0 <= nextY && nextY < y && 0 <= nextX && nextX < x)
            {
                if (map[nextY][nextX] != -1)
                {
                    if (visited[nextY][nextX] == 0)
                    {
                        visited[nextY][nextX] = 1;
                        shortest[nextY][nextX] = shortest[cur.first][cur.second] + 1;
                        q.push({nextY, nextX});
                    }
                }
            }
        }
    }
    int res = shortest[end.first][end.second];
    for (int i = 0; i < y; ++i)
    {
        free(visited[i]);
        free(shortest[i]);
    }
    free(visited);
    free(shortest);
    return res;
}

// start = 1, end = 2, lever = 3, wall= -1, space=0
int solution(vector<string> maps)
{
    int answer = 0;
    vector<vector<int>> map;

    int maxY = -1;
    int maxX = -1;
    int startY = 0;
    int startX = 0;
    int endY = 0;
    int endX = 0;
    int leverY = 0;
    int leverX = 0;

    for (string s : maps)
    {
        map.push_back(vector<int>());
        maxY++;
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'S':
            {
                map[maxY].push_back(1);
                startY = maxY;
                startX = i;
                break;
            }
            case 'E':
            {
                map[maxY].push_back(2);
                endY = maxY;
                endX = i;
                break;
            }
            case 'L':
            {
                map[maxY].push_back(3);
                leverY = maxY;
                leverX = i;
                break;
            }
            case 'O':
            {
                map[maxY].push_back(0);
                break;
            }
            case 'X':
            {
                map[maxY].push_back(-1);
                break;
            }
            }
        }
        maxX++;
    }
    maxX = map[0].size() - 1;

    int ans1 = bfs({startY, startX}, {leverY, leverX}, map, maxY + 1, maxX + 1);
    int ans2 = bfs({leverY, leverX}, {endY, endX}, map, maxY + 1, maxX + 1);
    answer = ans1 + ans2;
    if (ans1 == 0 || ans2 == 0 || answer == 0)
    {
        answer = -1;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> s = {"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};
    cout << solution(s) << "\n";
    return 0;
}
