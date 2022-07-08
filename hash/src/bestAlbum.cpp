#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        if (a.first < b.first)
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
        return a.second > b.second;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> map1;
    map<int, string> genreMap;
    map<string, vector<pair<int, int>>> musicMap;
    for (int i = 0; i < genres.size(); ++i)
    {
        vector<pair<int, int>> a;
        if (map1.count(genres[i]) == 0)
        {
            map1[genres[i]] = plays[i];
        }
        else
        {
            map1[genres[i]] += plays[i];
        }
        if (musicMap.count(genres[i]) == 0)
        {
            musicMap[genres[i]] = a;
        }

        musicMap[genres[i]].push_back(make_pair(i, plays[i]));
    }

    for (auto it = map1.begin(); it != map1.end(); ++it)
    {
        genreMap[it->second] = it->first;
    }
    vector<string> DescGenres;
    for (auto it = genreMap.begin(); it != genreMap.end(); ++it)
    {
        DescGenres.push_back(it->second);
    }
    reverse(DescGenres.begin(), DescGenres.end());
    for (auto it = musicMap.begin(); it != musicMap.end(); ++it)
    {

        sort(it->second.begin(), it->second.end(), compare);
    }
    for (string genre : DescGenres)
    {
        answer.push_back(musicMap[genre][0].first);
        if (musicMap[genre].size() == 1)
        {
            continue;
        }
        answer.push_back(musicMap[genre][1].first);
    }
    return answer;
}

int main()
{
    vector<string> genre = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    vector<int> res = solution(genre, plays);
}