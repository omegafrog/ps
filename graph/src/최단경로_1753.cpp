#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> Pair;
#define INF 987654321

int main()
{
    // num of node
    int v;
    // num of edge
    int e;
    // start node
    int startNode;
    cin >> v >> e;
    cin >> startNode;
    // graph[v] = (e,w)
    vector<Pair> graph[v];
    // relative weight between start node and v's node
    int weights[v];

    for (int i = 0; i < e; ++i)
    {
        int n1;
        int n2;
        int w;
        cin >> n1 >> n2 >> w;

        graph[n1 - 1].push_back(make_pair(w, n2));
    }
    bool selected[v];
    for (int i = 0; i < v; ++i)
    {
        selected[i] = false;
        weights[i] = INF;
    }
    selected[startNode - 1] = true;
    weights[startNode - 1] = 0;
    priority_queue<Pair> pq;
    pq.push(make_pair(0, startNode - 1));
    while (!pq.empty())
    {
        // find smallest weight edge
        // smallest edge value
        // find smallest edge in selected node group
        int current = pq.top().second;
        int distance = -pq.top().first;

        pq.pop();

        if (weights[current] < distance)
            continue;

        // after find next edge
        // check selected
        selected[current] = true;
        // sync weights[]
        // it : next selected node's connected nodes
        // next : next selkected node
        for (auto it = graph[current].begin(); it != graph[current].end(); ++it)
        {
            if (weights[it->second - 1] > weights[current] + it->first)
            {
                weights[it->second - 1] = weights[current] + it->first;
                pq.push(make_pair(-(weights[current] + it->first), it->second - 1));
            }
        }
    }
    for (int i = 0; i < v; ++i)
    {
        if (weights[i] == 987654321)
            cout << "INF"
                 << "\n";
        else
            cout << weights[i] << "\n";
    }
}