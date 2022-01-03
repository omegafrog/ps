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

int* PutOperator(vector<int>& n, int currentVal, int index){
	if(operators[0] == 0 && operators[1] == 0 && operators[2] == 0 && operators[3] == 0) {ret[0] = currentVal; ret[1] = currentVal;return ret;}
	
	for(int i = 0;i<4;++i){
		switch(i){
			case 0: // + 
			{
				if(operators[0]>0)
				{
					operators[0]--;
					// smallest
					cand=PutOperator(n, currentVal+n[index+1],index+1);
					smallest = min(smallest, cand[0]);
					biggest = max(biggest, cand[1]);
					operators[0]++;
				}
				break;
			}
			case 1: // - 
			{
				if(operators[1]>0)
				{
					operators[1]--;
					int* cand = new int[2];
					cand= PutOperator(n, currentVal-n[index+1],index+1);
					smallest = min(smallest, cand[0]);
					biggest = max(biggest, cand[1]);
					operators[1]++;
				}
				break;
			}
			case 2: // * 
			{
				if(operators[2]>0)
				{
					operators[2]--;
					cand= PutOperator(n, currentVal*n[index+1],index+1);
					smallest = min(smallest, cand[0]);
					biggest = max(biggest, cand[1]);
					operators[2]++;
				}
				break;
			}
			case 3: // / 
			{
				if(operators[3]>0)
				{
					operators[3]--;
					cand= PutOperator(n, currentVal/n[index+1],index+1);
					smallest = min(smallest, cand[0]);
					biggest = max(biggest, cand[1]);
					operators[3]++;
				}
				break;
			}
		}
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