#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int getRes(vector<string> &sentense)
{
    stack<string> s;
    int res = 0;
    for (int i = 0; i < sentense.size(); i++)
    {
        if (sentense[i].compare(" ") == 0)
        {
            continue;
        }
        s.push(sentense[i]);
    }

    int tmp = 0;
    while (!s.empty())
    {
        string cur = s.top();
        s.pop();
        if (cur.compare("+") == 0)
        {
            res += tmp;
        }
        else if (cur.compare("-") == 0)
        {
            tmp *= -1;
            res += tmp;
        }
        else if (cur.compare(")") == 0)
        {
            cur = s.top();
            vector<string> bracketS;
            while (cur.compare("(") != 0)
            {
                bracketS.push_back(cur);
                s.pop();
                cur = s.top();
            }
            s.pop();
            reverse(bracketS.begin(), bracketS.end());
            tmp = getRes(bracketS);
        }
        else
        {
            tmp = stoi(cur);
        }
    }
    res += tmp;
    return res;
}

int setBracket(vector<string> &sentense, int openIdx)
{
    if (sentense.size() == 3)
    {
        return stoi(sentense[1]);
    }
    int res = 987654321;
    if (openIdx == -1)
    {
        int idx = 0;
        for (int i = 0; i < sentense.size(); i += 4)
        {
            sentense[i] = "(";
            res = min(res, setBracket(sentense, idx));
            idx += 4;
            sentense[i] = " ";
        }
    }
    else
    {
        bool closed = false;
        for (int i = openIdx + 6; i < sentense.size(); i += 4)
        {
            sentense[i] = ")";
            for (string c : sentense)
            {
                cout << c << " ";
            }
            int tmpRes = getRes(sentense);
            cout << "res : " << tmpRes;
            cout << "\n";
            res = min(res, tmpRes);
            sentense[i] = " ";
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    string num = "";
    vector<string> sentense;
    sentense.push_back(" ");
    for (char c : s)
    {
        if (c != '+' && c != '-')
        {
            num += c;
        }
        else
        {
            string op = "";
            op += c;
            sentense.push_back(num);
            sentense.push_back(" ");
            sentense.push_back(op);
            sentense.push_back(" ");
            num = "";
        }
    }
    sentense.push_back(num);
    sentense.push_back(" ");

    cout << setBracket(sentense, -1);

    return 0;
}
