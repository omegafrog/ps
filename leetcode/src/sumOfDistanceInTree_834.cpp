#include <iostream>
#include <vector>
#include <stack>
using namespace std;

    
class Solution {
public:
    int dfs(int startVertex, int n, vector<vector<int>>& edges){
        int* visited= (int*)malloc(sizeof(int)*n);
        int* depth = (int*)malloc(sizeof(int)*n);
        for(int i = 0 ;i  <n; ++i){
            visited[ i] = 0;
            depth[i] = 0;
        }
        stack<pair<int, int>> s;
        s.push({startVertex,0});
        visited[startVertex] =1;
        depth[startVertex] = 0;
        while(!s.empty()){
            int currentVertex = s.top().first;
            int currentDepth = s.top().second;
            s.pop();
            for(int v : edges[currentVertex]){
                if(visited[v]==0){
                    visited[v] = 1;
                    depth[v] = currentDepth+1;
                    s.push({v,currentDepth+1});
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            res+=depth[i];
        }
        return res;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge;
        for(int i = 0; i < n; ++i){
            edge.push_back(vector<int>());
        }
        for( auto it = edges.begin(); it != edges.end(); ++it )
        {
        
           vector<int> v = *it;
           edge[v[0]].push_back(v[1]);
           edge[v[1]].push_back(v[0]);
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(dfs(i, n, edge));
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<vector<int>> edges;
    edges.push_back(vector<int>({0,1}));
    edges.push_back(vector<int>({0,2}));
    edges.push_back(vector<int>({2,3}));
    edges.push_back(vector<int>({2,4}));
    edges.push_back(vector<int>({2,5}));
    Solution s;
    s.sumOfDistancesInTree(n, edges);
    return 0;
}
