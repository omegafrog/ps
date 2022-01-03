#include <iostream>
using namespace std;

int N;
int M;
int maze[1001][1001]; // start : [1][1]
int cache[1001][1001];
int count = 0;
int getCandy(int y, int x){
    count++;
    if(y == 0 || x == 0) return -1;
    
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    
    ret = max(getCandy(y-1, x), max(getCandy(y-1,x-1), getCandy(y, x-1))) + maze[y][x];
    
    return ret;
}

int main(){
    cin >> N >> M;
    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= M; ++x){
            cin >> maze[y][x];
        }
    }
    
    for(int y = 0; y <= 1001; ++y){
        for(int x = 0; x <= M; ++x){
            cache[y][x] = -1;
        }
    }
    

    cache[1][1] = maze[1][1];
    cache[2][1] = maze[1][1] + maze[2][1];
    cache[1][2] = maze[1][1] + maze[1][2];
    cache[2][2] = max( cache[1][1], max(cache[1][2],cache[2][1]))+maze[2][2];
    
    // for(int y = 1; y <= N; ++y){
    //     for(int x = 1; x <= M; ++x){
    //         if(y == 1 && x == 1) continue;
    //         if( y == 2 && x == 1 ) continue;
    //         if( y == 1 && x == 2 ) continue;
    //         if( y == 2 && x == 2 ) continue;
    //         // cache[y][x] = max( cache[y-1][x], max(cache[y-1][x-1], cache[y][x-1])) + maze[y][x];
    //         cache[y][x] = max( cache[y-1][x],  cache[y][x-1]) + maze[y][x];

    //     }
    // }
    // cout << cache[N][M];
    int ret = getCandy(N,M);
    cout << ret;
}