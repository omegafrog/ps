#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    stack<pair<int, int>> s;
    vector<pair<int, int>> ret;
    int time = 0;
    s.push(make_pair(time, prices[time]));
    for (time = 1; time < prices.size(); ++time)
    {
        pair<int, int> top = s.top();
        if (top.second > prices[time])
        {
            s.pop();
            ret.push_back(make_pair(top.first, time - top.first));
        }
        s.push(make_pair(time, prices[time]));
    }
    time--;
    while (!s.empty())
    {
        pair<int, int> top = s.top();
        ret.push_back(make_pair(top.first, time - top.first));
        s.pop();
    }
    sort(ret.begin(), ret.end(), compare);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        answer.push_back(it->second);
    }
    return answer;
}

int main()
{
    vector<int> input = {1, 2, 3, 2, 3};
    vector<int> output = solution(input);
}