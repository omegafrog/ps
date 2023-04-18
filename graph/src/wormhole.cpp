#include <iostream>
#include <vector>
#include <stack>
using namespace std;


bool velman_ford(int node, int start, vector<vector<vector<int>>> edges){
    long* shortest = (long*)malloc(sizeof(long)*node);

    for (int i = 0; i < node; i++)
    {
        shortest[i] = INT32_MAX;
    }
    for(int i = 0; i < node-1; ++i){
        for(int s = 0; s < edges.size(); ++s){
            for(int j = 0; j < edges[s].size(); ++j){
                int nextNode = edges[s][j][0];
                int nextWeight = edges[s][j][1];
                if(shortest[nextNode] > shortest[s]+nextWeight){
                    shortest[nextNode] = shortest[s]+nextWeight;
                }
            }
        }
    }
    for(int s = 0; s < edges.size(); ++s){
        for(int i = 0; i < edges[s].size(); ++i){
            int nextNode = edges[s][i][0];
            int nextWeight = edges[s][i][1];
            if(shortest[nextNode] > shortest[s]+nextWeight){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        int n,m,w;
        cin >> n >> m >> w;
        vector<vector<vector<int>>> edges;
        for(int k = 0; k < n; ++k){
            edges.push_back(vector<vector<int>>());
        }
        int s,e,t;
        for (int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            edges[s-1].push_back(vector<int>({e-1, t}));
            edges[e-1].push_back(vector<int>({s-1, t}));
        }
        for(int j = 0; j < w; ++j){
            cin >> s >> e >> t;
            edges[s-1].push_back(vector<int>({e-1, -t}));
        }
        if(velman_ford(n,1,edges)){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }
    
    return 0;
}
