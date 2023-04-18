#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct Compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

int dijkstra(int n, int k)
{

    int *elapsed = (int *)malloc(sizeof(int) * 200001);
    for (int i = 0; i < 200001; i++)
    {
        elapsed[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    q.push({0, n});
    elapsed[n] = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.top();
        q.pop();

        if (cur.first > elapsed[cur.second])
        {
            continue;
        }

        if (cur.second == 0)
        {
            pair<int, int> next = {1, cur.second + 1};
            {
                if (elapsed[next.second] > elapsed[cur.second] + 1)
                {
                    elapsed[next.second] = elapsed[cur.second] + 1;
                    q.push({elapsed[next.second], next.second});
                }
            }
        }
        else
        {
            pair<int, int> next = {1, cur.second + 1};
            if (next.second <= 100000)
            {
                if (elapsed[next.second] > elapsed[cur.second] + 1)
                {
                    elapsed[next.second] = elapsed[cur.second] + 1;
                    q.push({elapsed[next.second], next.second});
                }
            }
            next = {1, cur.second - 1};
            if (next.second <= 100000)
            {
                if (elapsed[next.second] > elapsed[cur.second] + 1)
                {
                    elapsed[next.second] = elapsed[cur.second] + 1;
                    q.push({elapsed[next.second], next.second});
                }
            }
            next = {0, cur.second * 2};
            if (next.second <= 100000)
            {
                if (elapsed[next.second] > elapsed[cur.second])
                {
                    elapsed[next.second] = elapsed[cur.second];
                    q.push({elapsed[next.second], next.second});
                }
            }
        }
    }
    return elapsed[k];
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int res = dijkstra(n, k);
    cout << res;
    return 0;
}
