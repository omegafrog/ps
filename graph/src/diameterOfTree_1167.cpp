#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

typedef pair<int, int> P;
// 노드 사이의 연결 가중치 저장
vector<vector<P>> matrix;
// 각 노드 사이의 거리를 저장
int *distances;
// bfs시 방문 여부 저장
int *visited;
// bfs에 쓰일 스택
stack<int> s;
// 노드의 개수
int v;

int bfs(int root)
{
    s.push(root);
    visited[root] = 1;
    while (!s.empty())
    {
        // 스택에서 뺀 노드
        int cur = s.top();
        s.pop();
        visited[cur] = 1;
        // node.first : 노드의 번호
        // node.second : cur노드와 node사이간의 거리
        for (P node : matrix[cur])
        {
            if (visited[node.first] == 0)
            {
                s.push(node.first);
                // 넣으려는 노드의 번호의 거리 = 현재 스택에서 뺀 노드의 거리 + cur노드와 node사이간의 거리
                distances[node.first] = distances[cur] + node.second;
            }
        }
    }
    int biggest = 0;
    int biggestIdx = 0;
    for (int i = 1; i <= v; ++i)
    {
        if (biggest < distances[i])
        {
            biggest = distances[i];
            biggestIdx = i;
        }
    }
    return biggestIdx;
}
int main()
{
    cin >> v;
    cin.clear();
    cin.ignore();
    visited = new int[v + 1];
    distances = new int[v + 1];
    for (int i = 1; i <= v; ++i)
    {
        visited[i] = 0;
        distances[i] = 0;
        vector<P> a;
        matrix.push_back(a);
    }
    vector<P> a;
    matrix.push_back(a);
    for (int i = 1; i <= v; ++i)
    {
        string s;
        getline(cin, s);
        int index = 0;
        int cur;
        int next;
        int distance;
        cur = stoi(s.substr(index, s.find(' ', index) - index));
        index = s.find(' ', index) + 1;
        while (true)
        {
            next = stoi(s.substr(index, s.find(' ', index) - index));
            index = s.find(' ', index) + 1;
            distance = stoi(s.substr(index, s.find(' ', index) - index));
            index = s.find(' ', index) + 1;
            matrix[cur].push_back(make_pair(next, distance));
            if (s[index] == '-')
                break;
        }
        // cout << cur << next << distance;
    }
    int w1 = bfs(1);
    for (int i = 1; i <= v; ++i)
    {
        visited[i] = 0;
        distances[i] = 0;
    }
    int w2 = bfs(w1);
    cout << distances[w2];
}