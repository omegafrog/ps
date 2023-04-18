#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool comp1(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

bool comp2(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;
    vector<pair<int, int>> enemy2;
    for (int i = 0; i < enemy.size(); ++i)
    {
        enemy2.push_back({i, enemy[i]});
    }
    sort(enemy2.begin(), enemy2.end(), comp1);
    map<int, int> m;
    for(int i =0 ; i < k; ++i){
        m[enemy2[i].first] = 1;
    }
    int i = 0;
    for (i;i < enemy.size(); ++i)
    {
        if (enemy[i] > n)
        {
            if (m.count(i) > 0)
            {
                k--;
                continue;
            }
            answer = i;
            break;
        }
        else
        {
            if (m.count(i) > 0)
            {
                k--;
                continue;
            }
            else
            {
                n -= enemy[i];
            }
        }
    }

    return i;
}

int main(int argc, char const *argv[])
{
    vector<int> v({3,3,3,3});
    cout << solution(2,4, v);
    return 0;
}
