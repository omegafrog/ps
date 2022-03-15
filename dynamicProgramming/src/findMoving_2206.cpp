#include <iostream>
using namespace std;
#define INF 987654321

int **cache;
int **maze;
bool **visited;
int N;
int M;
bool isDestroyed = false;
int direction[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int findMaze(int y, int x)
{
    if (y == N - 1 && x == M - 1)
    {
        return 1;
    }
    int &ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;
    int cand = INF;
    // 벽을 부수지 않았을 경우
    if (!isDestroyed)
    {
        //무조건 벽을 부수는 경우
        for (int i = 0; i < 4; ++i)
        {
            int nextY = y + direction[i][0];
            int nextX = x + direction[i][1];
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && visited[nextY][nextX] == false)
            {
                if (maze[nextY][nextX] == 1)
                {
                    maze[nextY][nextX] == 0;
                    isDestroyed == true;
                }
                visited[nextY][nextX] == true;
                cand = min(cand, findMaze(nextY, nextX));
                visited[nextY][nextX] == false;
                if (maze[nextY][nextX] == 1)
                {
                    maze[nextY][nextX] == 1;
                    isDestroyed == false;
                }
            }
        }
    }
    return ret;
}
int main()
{
    cin >> N >> M;
    string s;
    maze = new int *[N];
    cache = new int *[N];
    visited = new bool *[N];
    for (int i = 0; i < N; ++i)
    {
        maze[i] = new int[M];
        cache[i] = new int[M];
        visited[i] = new bool[M];
    }
    for (int y = 0; y < N; ++y)
    {
        cin >> s;
        for (int x = 0; x < M; ++x)
        {
            maze[y][x] = s[x] - 48;
            cache[y][x] = -1;
            visited[y][x] = false;
        }
    }
    int res = findMaze(0, 0);
}