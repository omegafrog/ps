#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M;
vector<int> A(0,100000);
vector<int> B(0,100000);
int N;

bool binSearch(int start, int end, int find){
    int mid = (start+end)/2;
    
    if(start>end) return false;
    if(A[start]>find || A[end]<find) return false;
    if(A[mid]==find) return true;
    
    if(find<A[mid]) return binSearch(start, mid-1,find);
    if(find>A[mid]) return binSearch(mid+1,end,find);    
}

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i){
        int c;
        cin >> c;
        A.push_back(c);
    }
    
    cin >> M;
    for(int i = 0; i < M; ++i){
        int c;
        cin >> c;
        B.push_back(c);
    }
    
    sort(A.begin(), A.end());
    // for(auto it = A.begin(); it!=A.end(); ++it){
    //     cout << *it <<'\n';
    // }
    
    for(auto it = B.begin(); it!=B.end(); ++it){
        // cout << *it << '\n';
        cout << binSearch(0, N-1, *it) << '\n';
    }
}