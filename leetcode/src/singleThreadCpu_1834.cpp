#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

struct task{
        int enqueueTime;
        int processingTime;
        int index;
    };
bool cmp(struct task a, struct task b){
        return a.enqueueTime < b.enqueueTime;
    }
bool operator<(struct task a, struct task b){
        if(a.processingTime > b.processingTime){
            return true;
        }else if(a.processingTime == b.processingTime){
            return a.index > b.index;
        }else{
            return false;
        }
    }
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        long long curTime = 1;
        priority_queue<struct task> q;
        int idx = 0;
        vector<struct task> v;
        for(int i = 0 ; i < tasks.size(); ++i){
            struct task task = {tasks[i][0], tasks[i][1], i};
            v.push_back(task);
        }
        sort(v.begin(), v.end(), cmp);
        curTime = v[0].enqueueTime;
  
        int i = 0;
        while(i< v.size()){
            if(v[i].enqueueTime <= curTime){
                q.push(v[i]);
                i++;
                continue;
            }
            if(q.empty()){
                curTime=v[i].enqueueTime;
                continue;
            }
            struct task newTask = q.top();
            curTime += newTask.processingTime;
            res.push_back(newTask.index);
            q.pop();
        }
        
        while(!q.empty()){
            res.push_back(q.top().index);
            q.pop();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v({{5,2},{7,2},{9,4},{6,3},{5,10}, {1,1}});
    Solution s;
    vector<int> ret = s.getOrder(v);
    for( auto it = ret.begin(); it != ret.end(); ++it )
    {
    
       cout << *it << " ";
    
    }
    return 0;
}
