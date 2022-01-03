#include <iostream>
#include <vector>
using namespace std;

int relativeX[4]={-1,0,0,1};
int relativeY[4]={0,-1,1,0};

bool ** visited;
int ** board;
int n =4;
int m =4;


int biggestTet(int y, int x, int index, int** board, int ret){
	if(index == 3 ) return ret;
		// cout << "ok" << endl;
	// cout << y << " " << x << endl;
	
	int ret2=0;
	for(int i=0;i<4;++i){
		int nextY = y + relativeY[i];
		int nextX = x + relativeX[i];
		if(y + relativeY[i] < 0 || y + relativeY[i] > n-1) continue;
		if(x + relativeX[i] < 0 || x + relativeX[i] > m-1) continue;
		if(visited[nextY][nextX] == true) continue;
		// cout << nextY << nextX << endl;
		// cout << "ret : " << ret2+board[nextY][nextX] << endl;
		visited[nextY][nextX]=true;
		int cand = biggestTet(nextY,nextX,index+1,board,ret+board[nextY][nextX]);
		ret2 = max(cand,ret2);
		visited[nextY][nextX]=false;
	}
	// cout << "ret : "<< ret2<< endl;
	return ret2;
}

int main(){
	
	cin >> n >> m;
	
	board = new int* [n];
		// cout << "ok" << endl;
	visited = new bool* [n];
	for(int i=0;i<n;i++){
		board[i] = new int [m];
		visited[i] = new bool[m];
	}
	// cout << "ok" << endl;
	
	for(int i=0;i<n;++i){
		for(int j = 0; j < m ; ++j){
			cin >> board[i][j];
			visited[i][j]=false;
		}
	}
	// for(int i = 0;i<n;++i){
	// 	for(int j =0;j< m; ++j){
	// 		cout << board[i][j];
	// 	}
	// }
		// cout << "ok" << endl;
	
	int ret = 0;
	for(int i = 0;i<n;++i){
		for(int j =0;j<m;++j){
			visited[i][j]=true;
			ret = max(ret, biggestTet(i,j,0, board, board[i][j]));
			visited[i][j]=false;
		}
	}
		// cout << "ok" << endl;

	cout << ret;
}