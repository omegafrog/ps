#include <iostream>
#include <cstring>
using namespace std;

#define INF 10000000

long int *cache;

long int calc(long int n){
	if(n==1) return 0;
	
	long int &ret = cache[n-1];
	long int cand1=INF,cand2=INF,cand3=INF;
	if(ret!=-1) return ret;
	if(n%3==0) cand1 = calc(n/3);
	if(n%2==0) cand2 = calc(n/2);
	cand3 = calc(n-1);
	
	ret = 1+min(cand1, min(cand2, cand3));
	return ret;
}

int main(){
	int n;
	cin >> n;
	
	cache = new long int[n+1];
	for(int i = 0;i<n+1;++i){
		cache[i]=-1;
	}
	long int ret = calc(n);
	cout << ret;
}