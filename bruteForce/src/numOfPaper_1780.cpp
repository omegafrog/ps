#include <iostream>
using namespace std;
int n;
int **paper;
int numOfPapers[3]={0,};


bool checkPaper(int n, int size, int y, int x){
	for(int i = 0; i<size; ++i){
		for(int j = 0; j<size; ++j){
			if(paper[y+i][x+j]!=n) return false;
		}
	}
	return true;
}

void cut(int size,int y, int x){
	if(checkPaper(-1, size, y, x)==1){
		numOfPapers[0]++;
		return;
	}
	else if(checkPaper(0,size,y,x)==1){
		numOfPapers[1]++;
		return;
	}
	else if(checkPaper(1, size, y, x)==1){
		numOfPapers[2]++;
		return;
	}
	
	size/=3;
	for(int i = 0;i<3;++i){
		for(int j = 0;j<3;++j){
			cut(size, y+size*i, x+size*j);
		}
	}
}


int main(){
	cin >> n;
	paper = new int*[n];
	for(int i = 0;i<n;++i){
		paper[i] = new int[n];
	}
	for(int i = 0;i<n;++i){
		for(int j = 0; j<n; ++j){
			int tmp;
			scanf("%d",&tmp);
			getchar();
			paper[i][j]=tmp;
		}
	}
	cut(n,0,0);
	cout << numOfPapers[0] << '\n' << numOfPapers[1] << '\n' << numOfPapers[2];
}