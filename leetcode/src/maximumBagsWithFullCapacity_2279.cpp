#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int> q;
        vector<int> v;
        for(int i = 0; i < capacity.size(); ++i){
            q.push(rocks[i]-capacity[i]);
        }
        int ret = 0;
        while(!q.empty()){
            int cur = q.top() *-1;
            q.pop();
            if(additionalRocks == 0)
                break;
            if(cur==0){
                ret++;
            }else{
                if(cur <= additionalRocks){
                    additionalRocks-=cur;
                    ret++;
                }else{
                    break;
                }
            }
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> capacity({2,3,4,5});
    vector<int> rocks({1,2,4,4});
    Solution s;
    int ret = s.maximumBags(capacity, rocks, 2);
    cout << ret;
    return 0;
}
