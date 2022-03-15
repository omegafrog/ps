#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<char> bracketStack;
        vector<char> stringVector;
        vector<vector<char>::iterator> itVector;
        for (char c : s)
        {
            stringVector.push_back(c);
        }
        for (auto it = stringVector.begin(); it < stringVector.end(); ++it)
        {
            if (*it == '(')
            {
                bracketStack.push('(');
                itVector.push_back(it);
            }
            else if (*it == ')')
            {
                if (!bracketStack.empty())
                {
                    bracketStack.pop();
                }
                else
                {
                    stringVector.erase(it);
                    stringVector.insert(it, ' ');
                }
            }
        }
        while (!bracketStack.empty())
        {
            auto openBracketIt = itVector.back();
            stringVector.erase(openBracketIt);
            stringVector.insert(openBracketIt, ' ');
            itVector.pop_back();
            bracketStack.pop();
        }
        string res = "";
        for (char c : stringVector)
        {
            if (c == ' ')
                continue;
            res += c;
        }
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = ")";
    string s2 = s.minRemoveToMakeValid(s1);
    cout << s2;
}