#include <iostream>
using namespace std;

int N;
int dp1[1001];
int dp2[1001];
int A[1001];
void getUpperLIS(){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < i; ++j){
            if(A[i]>A[j] && dp1[j]+1>dp1[i])
                dp1[i]=dp1[j]+1;
        }
    }
}
void getLowerLIS(){
    for(int i = N-1; i>=0; --i){
        for(int j = N-1; j > i; --j){
            if(A[i] > A[j] && dp2[j]+1>dp2[i])
                dp2[i] = dp2[j]+1;
        }
    }
}
int main(){
    for(int i = 0; i < 1001; ++i){
        dp1[i]=1;
        dp2[i]=1;
    }
    
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    getUpperLIS();
    getLowerLIS();
    
    int maxVal = 0;
    for(int i = 0; i < N; ++i){
        maxVal = max(maxVal,dp1[i]+dp2[i]-1);
    }
    cout << maxVal;
}