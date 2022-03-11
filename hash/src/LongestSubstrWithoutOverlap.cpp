#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int sLength;
    int lengthOfLongestSubstring(string s)
    {
        sLength = s.size();
        unordered_map<char, int> ss;
        int ret = 0;
        for (int i = 0; i < sLength; ++i)
        {
            ss[s[i]] = 0;
        }
        for (int i = 0; i < sLength; ++i)
        {
            unordered_map<char, int> copy_ss(ss);
            copy_ss[s[i]] = 1;
            int res = 1;
            int start = i;
            int end = i + 1;

            bool canNextLeft = false;
            bool canNextRight = false;
            do
            {
                canNextLeft = false;
                canNextRight = false;
                if (end < s.size())
                {
                    if (copy_ss[s[end]] != 1)
                    {
                        end++;
                        copy_ss[s[end - 1]] = 1;
                        res++;
                        canNextRight = true;
                    }
                }
                if (start - 1 >= 0)
                {
                    if (copy_ss[s[start - 1]] != 1)
                    {
                        start--;
                        copy_ss[s[start]] = 1;
                        res++;
                        canNextLeft = true;
                    }
                }
            } while (canNextLeft || canNextRight);
            ret = max(ret, res);
        }
        return ret;
    }
    //     int getMaxSubstr(int start, int end, unordered_map<char, int> ss, string &s)
    //     {
    //         if (end - start == sLength)
    //         {
    //             return 0;
    //         }
    //         int ret = 0;
    //         int added = 0;
    //         bool canNextRight = false;
    //         bool canNextLeft = false;
    //         if (end < s.size())
    //         {
    //             if (ss[s[end]] != 1)
    //             {
    //                 end++;
    //                 ss[s[end - 1]] = 1;
    //                 added++;
    //                 canNextRight = true;
    //             }
    //         }
    //         if (start - 1 >= 0)
    //         {
    //             if (ss[s[start - 1]] != 1)
    //             {
    //                 start--;
    //                 ss[s[start]] = 1;
    //                 added++;
    //                 canNextLeft = true;
    //             }
    //         }
    //         if (!canNextRight & !canNextLeft == true)
    //         {
    //             return 0;
    //         }
    //         ret = added + getMaxSubstr(start, end, ss, s);
    //         return ret;
    //     }
};

int main()
{
    string s = "anviaj";
    Solution s1;
    cout << s1.lengthOfLongestSubstring(s);
}