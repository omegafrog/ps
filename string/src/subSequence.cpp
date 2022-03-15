#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int idx = 0;
        int sIdx = 0;
        if (s.empty() && t.empty())
        {
            return true;
        }
        for (int i = 0; i < t.size(); ++i)
        {

            if (s[idx] == t[i])
            {
                idx++;
            }
            if (idx == s.size())
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string s = "";
    string t = "";
    Solution a;
    cout << (a.isSubsequence(s, t) ? "true" : "false");
}