#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

struct Comp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
int toMinute(string time)
{
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');

    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time)
{
    int answer = 0;
    vector<pair<int, int>> times;
    for (vector<string> v : book_time)
    {
        string startTime = v[0];
        string endTime = v[1];
        times.push_back({toMinute(startTime), toMinute(endTime)});
    }
    sort(times.begin(), times.end(), comp);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;

    for (pair<int, int> time : times)
    {
        if (q.empty())
        {
            q.push(time);
        }
        else
        {
            pair<int, int> curTime = q.top();
            if (curTime.second + 10 <= time.first)
            {
                q.pop();
            }
            q.push(time);
        }
    }
    answer = q.size();

    return answer;
}

int main()
{
    vector<vector<string>> v;
    v.push_back(vector<string>({"15:00", "17:00"}));
    v.push_back(vector<string>({"16:40", "18:20"}));
    v.push_back(vector<string>({"14:20", "15:20"}));
    v.push_back(vector<string>({"14:10", "19:20"}));
    v.push_back(vector<string>({"18:20", "21:20"}));
    cout << solution(v);
}