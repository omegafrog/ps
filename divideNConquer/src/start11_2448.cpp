#include <iostream>
#include <fstream>
using namespace std;

/*ofstream myFile("out.txt");*/
bool **board;

void pattern(int y, int x, int size){
	int exponent=0;
	int thisSize=size/3;
	while(thisSize>1){
		exponent++;
		thisSize/=2;
	}
	int k=exponent;
	
	if(size == 3){
		board[y][x]=true;
		board[y+1][x-1]=true;
		board[y+1][x+1]=true;
		board[y+2][x-2]=true;
		board[y+2][x-1]=true;
		board[y+2][x]=true;
		board[y+2][x+1]=true;
		board[y+2][x+2]=true;
		return;
	}
	
	size/=2;
	pattern(y,x,size);
	pattern(y+size,x-(size),size);
	pattern(y+size,x+(size),size);
}

int main(){
	int n;
	cin >> n;
	int exponent=0;
	int thisN=n/3;
	while(thisN>1){
		exponent++;
		thisN/=2;
	}
	int k = exponent;
	board = new bool*[n];
	for(int i = 0;i<n;++i){
		board[i] = new bool[n*2-1];
	}
	for(int i = 0;  i<n;++i){
		for(int j = 0;j<n*2-1;++j){
			board[i][j]=false;
		}
	}
	pattern(0,n-1,n);
	for(int i = 0;i<n; ++i){
		for(int j = 0;j<n*2-1;++j){
			if(board[i][j]==true) {printf("*"); /*myFile << "*";*/}
			else {printf(" "); /*myFile << " ";*/}
		}
		if(i<n-1) {printf("\n"); /*myFile << "\n";*/}
	}
}