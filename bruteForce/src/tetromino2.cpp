#include <iostream>
#include <vector>
using namespace std;

int shape[19][2][4]={
	// --- 
	 { {0,1,2,3},{0,0,0,0}}, { { 0,0,0,0 }, { 0,1,2,3 } },
	// ㅁ
	{ {0,0,1,1},{0,1,0,1} },
	// ㄴ
	{ {0,0,0,1 }, {0,1,2,2} }, { {0,0,1,2}, {0,1,0,0 } }, {{0,1,1,1}, {0,0,-1,-2}},
	{ {0,1,2,2}, {0,0,0,1} }, {{0,1,1,1}, {0,0,1,2}}, {{0,1,2,2},{0,0,0,-1}}, {{0,0,0,1},{0,1,2,0}},
	{ { 0,0,1,2}, {0,1,1,1} },
	// |
	// -
	//  |
	 {{0,0,1,1}, {0,1,1,2}},{{0,0,1,1},{1,0,0,-1}}, {{0,1,1,2},{0,0,-1,-1}}, {{0,1,1,2},{0,0,1,1}},
	// ㅗ
	{{0,1,1,2},{0,0,1,0}}, {{-1,0,0,0},{1,0,1,2}}, {{0,1,1,2},{0,0,-1,0}}, {{0,0,0,1},{0,1,2,1}}
};

int** board;
int n,m;

int biggestSum(int y, int x){
	int ret = 0;
	for(int i=0;i<19;++i){
		int cand=0;
		for(int j = 0;j<4;++j){
			int tetrominoX=x+shape[i][0][j];
			int tetrominoY=y+shape[i][1][j];
			if(tetrominoY<0 || tetrominoY > n-1 ) continue;
			if(tetrominoX<0 || tetrominoX > m-1 ) continue;
			cand += board[tetrominoY][tetrominoX];
		}
		ret = max(ret,cand);
	}
	return ret;
}

int main(){
	cin >> n >> m;
	
	board = new int* [n];
	for(int i=0;i<n;i++){
		board[i] = new int [m];
	}
	
	for(int i=0;i<n;++i){
		for(int j = 0; j < m ; ++j){
			cin >> board[i][j];
		}
	}
	int ret = 0;
	for(int i=0;i<n;++i){
		for(int j =0;j<m;++j){
			ret = max(ret, biggestSum(i,j));
		}
	}
	cout << ret;
}