#include <iostream>
#include <vector>
// #include <fstream>
using namespace std;
#define MAX_VAL 10000000

// ofstream myFile("out.txt");

vector<int> n(20000001,0);
vector<int> m;
vector<int> ret(20000001,0);

void check(int num){
	ret[num+MAX_VAL]=n[num+MAX_VAL];
}

void compare(int start, int end){
	// myFile << start << " " << end << '\n';
	int size = end-start;
	
	if(size==1) {check(m[start]); return;}
	
	compare(start,start+size/2);
	compare(start+size/2,end);
}

int main(){
	int nNum;
	cin >> nNum;
	for(int i=0;i<nNum;++i){
		int tmp;
		scanf("%d",&tmp);
		n[tmp+MAX_VAL]++;
	}

	int mNum;
	cin >> mNum;
	for(int i=0;i<mNum;++i){
		int tmp;
		scanf("%d",&tmp);
		m.push_back(tmp);
	}
	// for(int i =0;i<m.size();++i){
	// 	cout << m[i] << " ";
	// }
	// cout << nNum << " " << mNum<<'\n';
	compare(0,mNum);
	for(auto it = m.begin(); it!=m.end(); ++it){
		if(ret[*it+MAX_VAL]>0) {printf("%d",ret[*it+MAX_VAL]);/*myFile<< 1;*/}
		else {printf("%d",0);/* myFile << 0;*/}
		if(it<m.end()-1) {printf(" ");/* myFile << " ";*/}
	}
}