#include <iostream>
using namespace std;
#define INF 987654321
int N;
int M;
int **graph;

void floyd()
{
    for (int passNode = 0; passNode < N; ++passNode)
    {
        for (int start = 0; start < N; ++start)
        {
            for (int end = 0; end < N; ++end)
            {
                if (start == end)
                    continue;
                if (graph[start][end] > graph[start][passNode] + graph[passNode][end])
                    graph[start][end] = graph[start][passNode] + graph[passNode][end];
            }
        }
    }
}
int main()
{
    cin >> N;
    cin >> M;
    graph = new int *[N];
    for (int i = 0; i < N; ++i)
    {
        graph[i] = new int[N];
        for (int j = 0; j < N; ++j)
        {
            graph[i][j] = INF;
        }
        graph[i][i] = INF;
    }
    for (int i = 0; i < M; ++i)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        if (graph[start - 1][end - 1] > weight)
            graph[start - 1][end - 1] = weight;
    }
    floyd();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (graph[i][j] == INF)
            {
                cout << 0;
            }
            else
            {
                cout << graph[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}