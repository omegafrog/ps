#include <iostream>
using namespace std;


long long *cache;

long long tiling(int n){
	if(n==1) return 1;
	if(n==2) return 3;
	
	long long& ret = cache[n];
	if(ret!=-1) return ret;
	ret = (tiling(n-1)+tiling(n-2)+tiling(n-2))%10007;
	
	return ret;
}

int main(){
	int n;
	cin >> n;
	cache = new long long[n+1];
	for(int i = 0;i<n+1;++i){
		cache[i] = -1;
	}
	long long ret = tiling(n);
	cout << ret;
}