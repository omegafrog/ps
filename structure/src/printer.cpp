#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return true;
    }
    return a.second > b.second;
}
int solution(vector<int> priorities, int location)
{
    int answer = 0;
    vector<pair<int, int>> v;
    int idx = 0;
    for (int a : priorities)
    {
        v.push_back(make_pair(idx++, a));
    }

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].first == location)
        {
            answer = i;
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> input = {2, 1, 3, 2};
    int output = solution(input, 2);
}