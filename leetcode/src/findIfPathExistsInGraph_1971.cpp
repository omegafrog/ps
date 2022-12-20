#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int findRoot(int* unionArr, int v){
        int cur = v;
        while(cur!=unionArr[cur]){
            cur = unionArr[cur];
        }
        return cur;
    }
    void doUnion(int* unionArr, int v1, int v2){
        int root1 = findRoot(unionArr,v1);
        int root2 = findRoot(unionArr, v2);
        if(root1 != root2){
            unionArr[root1] = root2;
        }
    }
    bool isUnion(int* unionArr, int v1, int v2){
        int root1 = findRoot(unionArr,v1);
        int root2 = findRoot(unionArr,v2);
        return root1==root2;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size()==0){
            return true;
        }
        int* unionArr = (int*)malloc(sizeof(int*)*n);
        for(int i = 0; i < n; ++i){
            unionArr[i] = i;
        }
        vector<vector<int>> E;
        for(int i =0; i < n; ++i){
            E.push_back(vector<int>());
        }
        for(auto it = edges.begin(); it!=edges.end(); ++it){
            vector<int> edge = *it;
            E[edge[0]].push_back(edge[1]);
            E[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; ++i){
            for(auto it = E[i].begin(); it!=E[i].end(); ++it){
                
                if(!isUnion(unionArr, i, *it)){
                    doUnion(unionArr, i, *it);
                }
            }
        }
        int root1 = findRoot(unionArr, source);
        int root2 = findRoot(unionArr, destination);
        return root1 == root2;

        
    
    }
};



int main(int argc, char const *argv[])
{
    
    return 0;
}
