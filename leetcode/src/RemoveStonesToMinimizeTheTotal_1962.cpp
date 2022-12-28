#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto it = piles.begin(); it!=piles.end(); ++it){
            q.push(*it);
        }
        for(int i = 0; i < k; ++i){
            int cur = q.top();
            q.pop();
            cur = (cur%2==0)?cur/2:cur/2+1;
            q.push(cur);
        }
        int res = 0;
        while(!q.empty()){
            res+=q.top();
            q.pop();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v({4,3,6,7});
    Solution s;
    int ret = s.minStoneSum(v, 3);
    cout << ret;
    return 0;
}
