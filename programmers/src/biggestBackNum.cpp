#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Comp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first < b.first;
    }
};
struct Comp2
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    int n = numbers.size();
    for (int i = 0; i < n; ++i)
    {
        answer.push_back(-1);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;
    for (int i = 0; i < n; ++i)
    {
        q.push({numbers[i], i});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp2> q2;
    q2.push(q.top());
    q.pop();
    while (!q.empty())
    {
        pair<int, int> cur = q.top();
        q.pop();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp2> tmp(q2);
        int ans = -1;
        while (!tmp.empty())
        {
            pair<int, int> compared = tmp.top();
            tmp.pop();
            if (compared.second > cur.second && compared.first > cur.first)
            {
                ans = compared.first;
                break;
            }
        }
        answer[cur.second] = ans;
        q2.push(cur);
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> numbers = {3, 7, 5, 9, 2, 1, 6, 4, 2, 6, 3, 8, 7};
    vector<int> res = solution(numbers);
    return 0;
}
