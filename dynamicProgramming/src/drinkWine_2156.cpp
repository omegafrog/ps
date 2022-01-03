#include <iostream>
using namespace std;


int N;
int A[10001];
int dp[10001];

int main(){
    cin >> N;
    
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    for(int i = 1; i <= 10001; ++i){
        dp[i] = 0;
    }
    
    dp[1] = A[1];
    dp[2] = A[1]+A[2];
    dp[3] = max(A[1]+A[2], max(A[2]+A[3],A[1]+A[3]));
    
    int maxVal = 0;
    for(int i = 4; i <= N; ++i){
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], dp[i-2]+A[i]);
        dp[i] = max(dp[i], dp[i-3]+A[i-1]+A[i]);
        
    }
    
    cout << dp[N];
    
}