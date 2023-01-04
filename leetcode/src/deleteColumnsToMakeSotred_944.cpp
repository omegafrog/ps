#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> s;
        for(int i = 0; i < strs[0].size(); ++i){
            string str="";
            for(int j = 0; j < strs.size(); ++j){
                str+=strs[j][i];
            }
            s.push_back(str);
        }
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            string s2 = s[i];
            for(int j = 0; j < s2.size()-1; ++j){
                int before = s2[j];
                int after = s2[j+1];
                if(before > after){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    vector<string> s({"cba","daf","ghi"});
    Solution sol;
    cout << sol.minDeletionSize(s);

    return 0;
}

