#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

void solution(vector<int> &input, int m, int level, int *visited, vector<int> &v)
{
    if (level == m)
    {
        res.push_back(v);
        return;
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (visited[i] == 0)
        {
            v.push_back(input[i]);
            visited[i] = 1;
            solution(input, m, level + 1, visited, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    vector<int> input;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());

    vector<int> v;
    int *visited = (int *)malloc(sizeof(int) * 8);

    solution(input, m, 0, visited, v);
    for (auto it = res.begin(); it != res.end(); ++it)
    {
        vector<int> vv = *it;
        for (auto iter = vv.begin(); iter != vv.end(); ++iter)
        {

            cout << *iter << " ";
        }
        cout << "\n";
    }
    return 0;
}
