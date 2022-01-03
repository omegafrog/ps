#include <iostream>
using namespace std;

int N;
int A[100001];
int dp[100001][2];

int main(){
    
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    
    dp[1][0] = A[1];
    dp[1][1] = 0;
    
    int ret=-100000000;
    int ret2;
    if(N==1) ret = A[1];
    else
    {
        for(int i = 2; i <= N; ++i){
            dp[i][0] = max(dp[i-1][0]+A[i], A[i]);
            ret = max(ret, dp[i][0]);
        }


        for(int i = 2; i <= N; ++i){
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]+A[i]);
            ret = max(ret, dp[i][1]);
        }
        
    }
    cout << ret;
}