#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<vector<string>> actions;
    map<string, string> user;

    for (auto it = record.begin(); it != record.end(); ++it)
    {
        string id;
        string nickname;
        string action;
        string raw = *it;
        vector<string> tmp;

        int size = 0;
        int idx = 0;
        size = raw.find(" ") - idx;
        action = raw.substr(0, size);
        idx += size + 1;
        size = raw.find(" ", idx) - idx;
        id = raw.substr(idx, size);
        idx += size + 1;
        tmp.push_back(action);
        tmp.push_back(id);
        if (action.compare("Enter") == 0 || action.compare("Change") == 0)
        {
            size = raw.size() - idx;
            nickname = raw.substr(idx, size);
            tmp.push_back(nickname);
            user[id] = nickname;
        }
        actions.push_back(tmp);
    }
    for (auto it = actions.begin(); it != actions.end(); ++it)
    {
        vector<string> tmp = *it;
        string action = tmp[0];
        string id = tmp[1];
        string nickname = user[id];
        if (tmp.size() == 3)
        {
        }
        if (action.compare("Enter") == 0)
        {
            answer.push_back(nickname + "님이 들어왔습니다.");
        }
        else if (action.compare("Leave") == 0)
        {
            answer.push_back(nickname + "님이 나갔습니다.");
        }
        else
        {
            continue;
        }
    }
    return answer;
}
int main()
{
    vector<string> input = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    vector<string> output = solution(input);
}