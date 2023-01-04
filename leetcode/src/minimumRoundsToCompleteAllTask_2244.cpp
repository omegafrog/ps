#include <iostream>
#include <vector>
#include <map>

#define INF 987654321

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        pair<int, int> mem[100001];
        map<int, int> m;
        for(int item : tasks){
            if(m.find(item) == m.end()){
                m[item] = 1;
            }else{
                m[item]+=1;
            }
        }
        for(int i = 0; i < 100001; ++i){
            mem[i] = {-1,0};
        }
        mem[0] = {0,0};
        mem[1] = {0,0};
        mem[2] = {1,1};
        mem[3] = {1,1};
        for(int i = 4; i<100001; ++i){
            if(mem[i-2].first == 0 && mem[i-3].first == 0)
                mem[i]={0,0};
            else if(mem[i-2].first != 1){
                mem[i] = {mem[i-3].first, mem[i-3].second+1};
            }else if(mem[i-3].first !=1){
                mem[i] = {mem[i-2].first, mem[i-2].second+1};
            }else{
                if(mem[i-2].second < mem[i-3].second){
                    mem[i] = {mem[i-2].first, mem[i-2].second+1};
                }else
                    mem[i] = {mem[i-3].first, mem[i-3].second+1};
            }
        }
        int res = 0;
        for(auto it = m.begin(); it!= m.end(); ++it){
            pair<int, int> p = *it;
            if(mem[p.second].first==1){
                res+=mem[p.second].second;
            }else{
                res = -1;
                break;
            }
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
    vector<int> v({2,3,3});
    Solution s;
    cout << s.minimumRounds(v);
    return 0;
}

