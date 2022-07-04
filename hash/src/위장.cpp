#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int getComb(vector<int> &clothnums, int before, int depth)
{
    if (depth == 1)
    {
        for (int i : clothnums)
        {
            if (i != -1)
            {
                return i;
            }
        }
    }
    int ret = 0;
    int tmp = 1;
    for (auto it = clothnums.begin(); it != clothnums.end(); ++it)
    {
        if (*it == -1)
        {
            continue;
        }
        tmp *= *it;
    }
    ret += tmp;
    tmp = 0;
    for (int i = before; i < clothnums.size(); ++i)
    {
        tmp = clothnums[i];
        clothnums[i] = -1;
        ret += getComb(clothnums, i + 1, depth - 1);
        clothnums[i] = tmp;
    }
    return ret;
}

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    int type = 0;
    unordered_map<string, int> clothmap;
    for (vector<string> cloth : clothes)
    {
        if (clothmap.count(cloth[1]) == 0)
        {
            clothmap[cloth[1]] = 0;
            type++;
        }
        clothmap[cloth[1]] += 1;
    }
    vector<int> clothnums;
    for (auto it = clothmap.begin(); it != clothmap.end(); ++it)
    {
        clothnums.push_back(it->second);
    }
    answer = getComb(clothnums, 0, clothnums.size());

    return answer;
}

int main()
{
    vector<vector<string>> input = {{"a", "ab"},
                                    {"b", "ab"},
                                    {"c", "abc"},
                                    {"d", "abc"},
                                    {"e", "abc"},
                                    {"f", "a"}};
    cout << solution(input);
}
