#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// node, weight
typedef pair<int, int> Pair;

int N;
int *weights;
bool *visited;
vector<Pair> *nodes;

int bfs(int n)
{
    stack<Pair> s;
    s.push(make_pair(n, 0));
    weights[n] = 0;
    visited[n] = true;
    while (!s.empty())
    {
        int current = s.top().first;
        int distance = s.top().second;
        visited[current] = true;
        s.pop();
        for (Pair p : nodes[current])
        {
            int next = p.first;
            int nextDistance = p.second;
            if (visited[next] == false)
            {
                weights[next] = weights[current] + nextDistance;
                s.push(p);
            }
        }
    }
    int res = 0;
    int idx;
    for (int i = 1; i < N + 1; ++i)
    {
        if (res < weights[i])
        {
            idx = i;
            res = weights[i];
        }
    }
    return idx;
}

int main()
{
    cin >> N;
    weights = new int[N + 1];
    nodes = new vector<Pair>[N + 1];
    visited = new bool[N + 1];
    for (int i = 0; i < N + 1; ++i)
    {
        weights[i] = 0;
        visited[i] = false;
    }
    int parent, child, weight;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> parent >> child >> weight;
        nodes[parent].push_back(make_pair(child, weight));
        nodes[child].push_back(make_pair(parent, weight));
    }
    int from = bfs(1);

    for (int i = 0; i < N + 1; ++i)
    {
        weights[i] = 0;
        visited[i] = false;
    }
    int to = bfs(from);

    cout << weights[to];
}