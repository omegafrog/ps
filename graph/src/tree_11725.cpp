#include <iostream>
#include <vector>
using namespace std;

int N;
int *res;
bool *visited;
vector<int> *nodes;

void findParent(int n)
{
    for (auto it = nodes[n].begin(); it != nodes[n].end(); ++it)
    {
        if (visited[*it] == false)
        {
            res[*it] = n;
            visited[*it] = true;
            findParent(*it);
        }
    }
}

int main()
{
    cin >> N;
    res = new int[N + 1];
    nodes = new vector<int>[N + 1];
    visited = new bool[N + 1];
    for (int i = 0; i < N + 1; ++i)
    {
        visited[i] = false;
    }
    int first, second;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> first >> second;
        nodes[first].push_back(second);
        nodes[second].push_back(first);
    }
    visited[1] = true;
    findParent(1);
    for (int i = 2; i <= N; ++i)
    {
        cout << res[i] << "\n";
    }
}