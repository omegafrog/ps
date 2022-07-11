#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <utility>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    unordered_map<string, set<string>> reportedMap;

    for (auto it = report.begin(); it != report.end(); ++it)
    {
        int idx = 0;
        idx = it->find(' ');
        string reporter = it->substr(0, idx);
        idx++;
        string reportee = it->substr(idx, (it->size() - idx));
        set<string> s;
        if (reportedMap.count(reportee) == 0)
        {
            s.insert(reporter);
            reportedMap[reportee] = s;
        }
        else
        {
            reportedMap[reportee].insert(reporter);
        }
    }
    unordered_map<string, int> answerList;
    for (string name : id_list)
    {
        answerList[name] = 0;
    }
    for (auto it = reportedMap.begin(); it != reportedMap.end(); ++it)
    {
        if (it->second.size() >= k)
        {
            for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            {
                answerList[*it2] += 1;
            }
        }
    }
    for (string name : id_list)
    {
        answer.push_back(answerList[name]);
    }
    return answer;
}

// int main()
// {
//     vector<string> input = {"muzi", "frodo", "apeach", "neo"};
//     vector<string> input2 = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
//     vector<int> output = solution(input, input2, 2);
// }