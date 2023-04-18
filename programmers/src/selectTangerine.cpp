#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Comp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    map<int, int> m;
    for (int a : tangerine)
    {
        if (m.count(a) == 0)
        {
            m[a] = 1;
        }
        else
        {
            m[a] += 1;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        q.push({it->first, it->second});
    }
    int sub = tangerine.size() - k;
    while (sub > 0)
    {
        pair<int, int> cur = q.top();
        if (cur.second > sub)
        {
            break;
        }
        else
        {
            q.pop();
            sub -= cur.second;
        }
    }
    answer = q.size();
    return answer;
}

int main(int argc, char const *argv[])
{
    int k = 6;
    vector<int> v({1, 3, 2, 5, 4, 5, 2, 3});
    cout << solution(k, v);
    return 0;
}
