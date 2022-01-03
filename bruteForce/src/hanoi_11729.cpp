#include <iostream>
#include <vector>
using namespace std;


vector<struct moved> ret;

struct moved{
	int from;
	int to;
};

int movingCount=0;

void hanoi(int n,int start, int pass, int end){
	struct moved move;
	if(n==1) {
		move.from = start;
		move.to = end;
		ret.push_back(move);
		movingCount++;
		return;
	}
	
	hanoi(n-1,start,end,pass);
	move.from = start;
	move.to = end;
	ret.push_back(move);
	movingCount++;
	hanoi(n-1,pass, start, end);
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	
	hanoi(n,1,2,3);
	
	printf("%d\n",movingCount);
	for(auto it = ret.begin(); it!=ret.end(); ++it){
		printf("%d %d",it->from, it->to);
		if(it<ret.end()) printf("\n");
	}
}