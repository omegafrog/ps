#include <iostream>
#include <queue>
#define  pair pair<int,int>
#define INF 987654321
using namespace std;


pair direction[4]={{-1,0}, {1,0}, {0,-1}, {0,1}};

void bfs(int** input, int** shortest, int n, int m, int startY, int startX){
    queue<pair> q;
    int** visited = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = (int*)malloc(sizeof(int)*m);
    }

    q.push({startY, startX});
    shortest[startY][startX] = 0;
    visited[startY][startX] = 1;
    while(!q.empty()){
        pair cur = q.front();
        int curY = cur.first;
        int curX = cur.second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nextY = curY + direction[dir].first;
            int nextX = curX + direction[dir].second;

            if( 0 <= nextY && nextY < n && 0 <= nextX && nextX < m ){
                if(input[nextY][nextX] == 0){
                    if( visited[nextY][nextX] == 0){
                        q.push({nextY, nextX});
                        visited[nextY][nextX] = 1;
                        shortest[nextY][nextX] = shortest[curY][curX]+1;
                    }
                }
            }
        }
    }
    free(visited);
    
}

int solution(int n, int m, int** input){

    //shortest[0][n][m] : 0,0부터 bfs
    // shortest[1][n][m] : n,m부터 bfs
    int*** shortest=(int***)malloc(sizeof(int**)*2);
    for (int i = 0; i < 2; i++)
    {
        shortest[i] = (int**)malloc(sizeof(int*)*n);
        for (int j = 0; j < n; j++)
        {
            shortest[i][j] = (int*)malloc(sizeof(int)*m);
            for (int k = 0; k < m; k++)
            {
                shortest[i][j][k] = INF;
            }
        }
        
        
        
        
    }
    bfs(input, shortest[0], n, m, 0, 0);
    bfs(input, shortest[1], n, m, n-1, m-1);

    int res = INF;
    res = min(res, shortest[0][n-1][m-1]);
    res = min(res, shortest[1][0][0]);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if(shortest[0][y][x] !=INF){
                int nextY = y+1;
                int nextX = x+1;
                if(0<= nextY && nextY < n && 0 <= nextX && nextX < m){
                    if(shortest[1][nextY][nextX] !=INF){
                        res = min(res, shortest[0][y][x] + shortest[1][nextY][nextX]+1);
                    }
                }
                nextY = y;
                nextX = x+2;
                if(0<= nextY && nextY < n && 0 <= nextX && nextX < m){
                    if(shortest[1][nextY][nextX] !=INF){
                        res = min(res, shortest[0][y][x] + shortest[1][nextY][nextX]+1);
                    }
                }
                nextY = y+2;
                nextX = x;
                if(0<= nextY && nextY < n && 0 <= nextX && nextX < m){
                    if(shortest[1][nextY][nextX] !=INF){
                        res = min(res, shortest[0][y][x] + shortest[1][nextY][nextX]+1);
                    }
                }
                nextY = y-1;
                nextX = x+1;
                if(0<= nextY && nextY < n && 0 <= nextX && nextX < m){
                    if(shortest[1][nextY][nextX] !=INF){
                        res = min(res, shortest[0][y][x] + shortest[1][nextY][nextX]+1);
                    }
                }
                nextY = y-1;
                nextX = x-1;
                if(0<= nextY && nextY < n && 0 <= nextX && nextX < m){
                    if(shortest[1][nextY][nextX] !=INF){
                        res = min(res, shortest[0][y][x] + shortest[1][nextY][nextX]+1);
                    }
                }
                nextY = y+1;
                nextX =x-1;
                if(0<= nextY && nextY < n && 0 <= nextX && nextX < m){
                    if(shortest[1][nextY][nextX] !=INF){
                        res = min(res, shortest[0][y][x] + shortest[1][nextY][nextX]+1);
                    }
                }
            }
        }
        
    }
    
    return res;
}

int main(int argc, char const *argv[])
{   
    int n;
    int m;
    cin >> n >> m;
    int** input= (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        input[i] = (int*)malloc(sizeof(int)*m);
    }
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            input[i][j] = s[j]-'0';
        }
     }
     int res =  solution(n,m,input);
     if(res == INF){
        cout << -1;
     }else if(n==1 && m == 1){
        cout << 1;
     }
     else{
     cout << res+2;

     }
    
    return 0;
}
