#include <iostream>
using namespace std;

int N;
int K;
int cache[201][201];

int main(){
    cin >> N >> K;
    
    for(int i = 0; i < 201; ++i){
        cache[i][1] = 1;
    }
    for(int n = 0; n <= N; ++n){
        for(int k = 2; k <= K; ++k){
            int tmpN = n;
            while(tmpN>=0) {
                cache[n][k] += (cache[tmpN--][k-1]%1000000000);
                cache[n][k]%=1000000000;
            }
        }
    }
    cout << cache[N][K];
}