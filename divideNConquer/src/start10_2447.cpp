#include <iostream>
using namespace std;

bool **board;

void pattern(int y, int x, int size){
	if(size == 3){
		board[y][x]=true;
		board[y][x+1]=true;
		board[y][x+2]=true;
		board[y+1][x]=true;
		board[y+1][x+2]=true;
		board[y+2][x]=true;
		board[y+2][x+1]=true;
		board[y+2][x+2]=true;
		return;
	}
	size/=3;
	pattern(y,x,size);
	pattern(y,x+size,size);
	pattern(y,x+size*2,size);
	pattern(y+size,x,size);
	pattern(y+size,x+size*2,size);
	pattern(y+size*2,x,size);
	pattern(y+size*2,x+size,size);
	pattern(y+size*2,x+size*2,size);
}
int pow(int base, int exponent){
	int ret=1;
	for(int i = 0;i <exponent; ++i){
		ret*=base;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	board = new bool* [n];
	for(int i = 0;i<n; ++i){
		board[i] = new bool [n];
	}
	
	pattern(0,0,n);
	for(int i = 0;i<n; ++i){
		for(int j = 0; j<n; ++j){
			if(board[i][j]==true) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}