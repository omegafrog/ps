#include <iostream>
#include <vector>
using namespace std;

// cache
// int cache[1001];
vector<int> cache(1001,0);
int N;
// num of card
vector<int> P(10001,0);
// cost array 

int getMax(int n){
    // base case
    if(n<=1) return P[n];
    
    
    int &ret = cache[n];
    if(ret!=0) return ret;
    
    for(int i = 1; i <= n; ++i){
        ret = max(ret, P[i]+getMax(n-i));
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i = 1 ; i<= N; ++i){
        cin >> P[i];
    }
    
    int ret = getMax(N);
    cout << ret;
}