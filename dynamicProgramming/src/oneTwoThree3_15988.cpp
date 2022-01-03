#include <iostream>
using namespace std;

int n;
long long* cache;

long long oneTwoThree(int n){
	cache[0] = 1;
	cache[1] = 2;
	cache[2] = 4;
	for(int i = 3; i<=n; ++i){
		cache[i] = (cache[i-1]+cache[i-2]+cache[i-3])%1000000009;
	}
	return cache[n];
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(int i = 0;i<tcase;++i){
		int n;
		cin >> n;
		cache = new long long[n];
		for(int i = 0;i<n;++i) cache[i]=-1;
		
		cout << oneTwoThree(n-1);
		if(i<tcase-1) cout << "\n";
		delete [] cache;
	}
}