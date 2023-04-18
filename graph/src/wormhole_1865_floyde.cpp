#include <iostream>
#include <vector>
#define MINF -987654321
#define INF 987654321
using namespace std;

bool floyd_warshall(int n, int m, int w, int **edges)
{
    int **weight = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        weight[i] = (int *)malloc(sizeof(int) * n);
    }
    // weight 초기화
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            // 직접적으로 연결되지 않음
            if (edges[y][x] == INF)
            {
                weight[y][x] = INF;
            }
            // 직접적으로 연결된 도로가 없고 시작과 끝이 같은 경우
            else if (y == x)
            {
                weight[y][x] = 0;
            }
            // 연결된 도로나 웜홀이 있는 경우
            else
            {
                weight[y][x] = edges[y][x];
            }
        }
    }
    for (int checkNode = 0; checkNode < n; checkNode++)
    {
        for (int start = 0; start < n; start++)
        {
            for (int end = 0; end < n; end++)
            {
                if (weight[start][checkNode] != INF && weight[checkNode][end] != INF)
                {
                    if (weight[start][end] > weight[start][checkNode] + weight[checkNode][end])
                    {
                        weight[start][end] = weight[start][checkNode] + weight[checkNode][end];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (weight[i][i] < 0)
        {
            for (int j = 0; j < n; j++)
            {
                free(weight[j]);
            }
            free(weight);
            return true;
        }
    }
    for (int j = 0; j < n; j++)
    {
        free(weight[j]);
    }
    free(weight);
    return false;
}

int main(int argc, char const *argv[])
{
    int tc;
    cin >> tc;
    for (int cnt = 0; cnt < tc; cnt++)
    {
        int n, m, w;
        cin >> n >> m >> w;
        int **edges = (int **)malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            edges[i] = (int *)malloc(sizeof(int) * n);
        }
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                edges[y][x] = INF;
            }
        }
        for (int j = 0; j < m; j++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges[s - 1][e - 1] = min(edges[s - 1][e - 1], t);
            edges[e - 1][s - 1] = min(edges[e - 1][s - 1], t);
        }
        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges[s - 1][e - 1] = min(edges[s - 1][e - 1], -1 * t);
        }
        for (int i = 0; i < n; i++)
        {
            if (edges[i][i] == INF)
            {
                edges[i][i] = 0;
            }
        }

        bool res = floyd_warshall(n, m, w, edges);
        for (int j = 0; j < n; j++)
        {
            free(edges[j]);
        }
        free(edges);
        cout << (res) ? "YES" : "NO";
    }

    return 0;
}
