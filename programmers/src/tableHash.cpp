#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, vector<int>> &a, pair<int, vector<int>> &b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second[0] > b.second[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int solution1(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    vector<pair<int, vector<int>>> d;
    int answer = 0;
    int row = 1;
    for (vector<int> v : data)
    {
        d.push_back({v[col - 1], v});
    }

    sort(d.begin(), d.end(), comp);
    for (int idx = 1; idx <= d.size(); ++idx)
    {
        if (row_begin <= idx && idx <= row_end)
        {
            int tmp = 0;
            for (int a : d[idx - 1].second)
            {
                tmp += a % idx;
            }
            answer = answer ^ tmp;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Comp
{
    bool operator()(pair<int, vector<int>> &a, pair<int, vector<int>> &b)
    {
        if (!(a.first < b.first))
        {
            return true;
        }
        else if (a.first == b.first)
        {
            return a.second[0] < b.second[0];
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v({{3, 4, 5}, {3, 4, 5}});
    int row = 2;
    int row_begin = 1;
    int row_end = 2;

    cout << solution(v, row, row_begin, row_end);
    return 0;
}
