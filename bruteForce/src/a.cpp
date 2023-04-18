#include <iostream>
#include <string>
#include <vector>

using namespace std;
int bfs(int *visited, int n, int m, vector<int> section, int start)
{
    bool allVisited = true;
    for (int a : section)
    {
        if (visited[a - 1] == -1)
        {
            allVisited = false;
            break;
        }
    }
    if (allVisited)
        return 0;

    int res = 987654321;
    for (int i = start; i < n; ++i)
    {
        if (i + m - 1 < n)
        {
            for (int j = 0; j < m; ++j)
            {
                if (visited[j + i] == -1)
                    visited[j + i] = 1;
            }
            int next = 0;
            for(next; next < n; ++next){
                if(visited[next]==-1)
                    break;
            }
            res = min(res, bfs(visited, n, m, section, next-m+1) + 1);
            for (int j = 0; j < m; ++j)
            {
                if (visited[j + i] == 1)
                    visited[j + i] = -1;
            }
        }
    }
    return res;
}
int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    int *visited = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;
    for (int a : section)
    {
        visited[a - 1] = -1;
    }

    answer = bfs(visited, n, m, section, 0);
    return answer;
}



int main()
{
    int n = 8;
    int m = 4;
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(6);
    int res = solution(n, m, a);
    cout << res;
}