#include <iostream>
#include <queue>
using namespace std;

int N;
int V;
bool g[1001][1001];
bool visited[1001];
queue<int> q;
int start;

void bfs(int index){
    visited[index]=true;
    q.push(index);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= N; ++i){
            if(g[cur][i]==true && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

bool all_visited(){
    for(int i = 1; i <= N; ++i){
        if(visited[i] == false ) {start = i; return false;}
    }
    return true;
}

int main(){
    cin >> N >> V;
    
    for(int i = 1; i < 1001; ++i){
        for(int j = 1; j < 1001; ++j){
            g[i][j] = false;
        }
    }
    for(int i = 0; i <= 1001; ++i){
        visited[i] = false;
    }
    for(int i = 0 ; i < V; ++i){
        int a,b;
        cin >> a >> b;
        g[a][b]=true;
        g[b][a]=true;
    }
    int count = 0;
    
    while(!all_visited()){
        bfs(start);
        count++;
    }
    cout << count;
}