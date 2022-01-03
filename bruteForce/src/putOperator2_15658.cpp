#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321;
#define MINUSINF -987654321;

int operators[4]={0,};
int smallest = INF;
int biggest = MINUSINF;
int *ret;
int *cand;
int puttedOperatorNum=0;

int* PutOperator(vector<int>&, int, int);
void selectOperators(int op, vector<int>& n,int currentVal, int index){
	if(operators[op]>0){
		--operators[op];
		puttedOperatorNum++;
		// smallest
		if(op == 0) cand=PutOperator(n,currentVal+n[index+1],index+1);
		else if(op == 1) cand=PutOperator(n,currentVal-n[index+1],index+1);
		else if(op == 2) cand=PutOperator(n,currentVal*n[index+1],index+1);
		else cand=PutOperator(n,currentVal/n[index+1],index+1);
		smallest = min(smallest, cand[0]);
		biggest = max(biggest, cand[1]);
		++operators[op];
		--puttedOperatorNum;
	}
}

int* PutOperator(vector<int>& n, int currentVal, int index){
	if(puttedOperatorNum == n.size()-1)
	{
		ret[0] = currentVal;
		ret[1] = currentVal;
		return ret;
	}
	
	for(int i = 0;i<4;++i){
		selectOperators(i, n, currentVal, index);
		// cout << i << ":okay"<<'\n';
	}
	ret[0] = smallest;
	ret[1] = biggest;
	return ret;
}

int main(){
	cand = new int[2];
	ret = new int[2];
	int n;
	cin >> n;
	vector<int> input;
	for(int i = 0; i<n; ++i){
		int k;
		cin >> k;
		input.push_back(k);
	}
	for(int i = 0; i < 4; ++i){
		int k;
		cin >> k;
		operators[i]=k;
	}
	ret = PutOperator(input, input[0], 0);
	cout << ret[1] << '\n' << ret[0];
}