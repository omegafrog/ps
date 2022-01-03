#include <iostream>
#include <vector>
using namespace std;
#define ZERO 100000

int N;
vector<int> A[ZERO+100000];

void merge(int left, int mid, int right, int x){
    int l = left;
    int m = mid+1; 
    
    vector<int> tmp;
    
    while( l <= mid && m <= right){
        if(A[x][l]>A[x][m]) tmp.push_back(A[x][m++]);
        else tmp.push_back(A[x][l++]);
    }
    
    while( l <= mid) tmp.push_back(A[x][l++]);
    while( m <= right) tmp.push_back(A[x][m++]);
    for(left; left <= right; ++left){
        A[x][left] = tmp[left];
    }
}

void mergeSort(int start, int end, int x){
    int mid = (start+end)/2;
    
    if(start>end) return;
    if(start == end) return;
    mergeSort(start, mid, x);
    mergeSort(mid+1, end, x);
    merge(start, mid, end, x);
}


int main(){
    int biggest=0;
    cin >> N;
    for(int i = 0; i < N; ++i){
        int x,y;
        cin >> x >> y;
        A[ZERO+x].push_back(y);
        biggest = max(biggest, x);
    }
    for(int i = 0; i < ZERO+100000; ++i){
        if(A[i].size()<=1) continue;
        mergeSort(0,A[i].size()-1,i);
    }
    if(N>1)
    {for(int i = 0; i < ZERO+biggest; ++i){
        if(!A[i].empty()){
            for(auto it = A[i].begin(); it!=A[i].end(); ++it)
                cout << i-ZERO << " " << *it << "\n";
        }
    }
    if(A[ZERO+biggest].size()==1) cout << biggest << " " << A[ZERO+biggest][0];
    else{
        for(auto it = A[biggest+ZERO].begin(); it!=A[ZERO+biggest].end()-1; ++it)
                cout << biggest << " " << *it << "\n";
    }}
    cout << biggest << " " << *(A[ZERO+biggest].end()-1);
}