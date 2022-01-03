#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int N; // num of vertex
int M; // num of edge
int start;
bool* visited[2];
bool g[1001][1001];
queue<int> q;

void dfs(int index){
    cout << index;
    visited[0][index]=true;
    
    for(int i = 1; i <= N; ++i){
        if(g[index][i]==true)
        {
            if(visited[0][i] != true){
                cout << " ";
                dfs(i);
            }
        }
    }
}

void bfs(int index){
    vector<int>tmp;
    q.push(index);
    visited[1][index]=true;
    
    while(!q.empty()){
        int cur = q.front();
        tmp.push_back(cur);
        q.pop();
        for(int i = 1; i <= N; ++i){
            if(g[cur][i]==true){
                if(visited[1][i] != true){
                    q.push(i);
                    visited[1][i]=true;
                }
            }
        }
    }
    for(auto it = tmp.begin(); it!=tmp.end()-1; ++it){
        cout << *it <<" ";
    }
    cout << *(tmp.end()-1);
}

int main(){
    for(int i = 0; i < 2; ++i){
        visited[i]=new bool[1001];
        for(int j = 0; j < 1001; ++j){
            visited[i][j] = false;
        }
    }
    
    cin >> N >> M >> start;
    
    int a, b;
    for(int i = 1; i <= 1000; ++i){
        for(int j = 1; j <= 1000; ++j)
            g[i][j]=false;
    }
    for(int i = 1; i <= M; ++i){
        cin >> a >> b;
        g[a][b] = true;
        g[b][a] = true;
    }
    dfs(start);
    cout << "\n";
    bfs(start);
}
