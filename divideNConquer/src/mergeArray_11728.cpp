#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, vector<int>& b,vector<int>& ret){
	int i=0,j=0;
	while(i<a.size() && j <b.size()){
		if(a[i]<b[j]){
			ret.push_back(a[i]);
			i++;
		} 
		else {
			ret.push_back(b[j]);
			j++;
		}
	}
	while(i<a.size()) ret.push_back(a[i++]);
	while(j<b.size()) ret.push_back(b[j++]);
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> a;
	vector<int> b;
	getchar();
	
	int tmp;
	for(int i=0;i<n;++i){
		scanf("%d",&tmp);
		getchar();
		a.push_back(tmp);
	}
	for(int i = 0;i<m;++i){
		scanf("%d",&tmp);
		getchar();
		b.push_back(tmp);
	}
	vector<int> ret;
	merge(a,b,ret);
	for(auto it = ret.begin(); it!=ret.end(); ++it){
		printf("%d",*it);
		if(it<ret.end()) printf(" ");
	}
}