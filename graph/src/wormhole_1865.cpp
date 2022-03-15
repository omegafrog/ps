#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> Pair;
#define INF 987654321
bool *visited;
long long *weights;
int N, M, W;
vector<Pair> *graph;

bool velman_ford(int n)
{
    weights[n] = 0;
    visited[n] = true;
    int copied[N + 1];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (auto it = graph[j + 1].begin(); it != graph[j + 1].end(); ++it)
            {
                if (visited[j + 1] == true)
                {
                    if (weights[it->first] >= weights[j + 1] + it->second)
                    {
                        weights[it->first] = weights[j + 1] + it->second;
                        visited[it->first] = true;
                    }
                }
            }
        }
        if (i == N - 2)
        {
            copy(weights, weights + N , copied);
        }
        if (i == N - 1)
        {
            for (int k = 1; k <= N; ++k)
            {
                if (weights[k] != copied[k])
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        cin >> N >> M >> W;
        graph = new vector<Pair>[N + 1];
        weights = new long long[N + 1];
        visited = new bool[N + 1];
        for (int j = 0; j < N; ++j)
        {
            weights[j + 1] = INF;
            visited[j + 1] = false;
        }
        for (int j = 0; j < M; ++j)
        {
            int s, e, t;
            cin >> s >> e >> t;
            graph[s].push_back(make_pair(e, t));    
            graph[e].push_back(make_pair(s, t));
        }
        for (int j = 0; j < W; ++j)
        {
            int s, e, t;
            cin >> s >> e >> t;
            graph[s].push_back(make_pair(e, -t));
        }
        if (velman_ford(1))
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
        delete[] graph;
        delete[] weights;
        delete[] visited;
    }
}