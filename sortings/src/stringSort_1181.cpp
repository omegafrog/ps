#include <iostream>
#include <vector>
using namespace std;

int N;

vector<string> input[50];

void merge(int left, int mid, int right, int len){
    int l = left;
    int k = mid+1;
    int r = right;
    
    vector<string> tmp;
    while(l <= mid && k <= right){
        if(input[len][l] > input[len][k]){
            tmp.push_back(input[len][k++]);
        }
        else tmp.push_back(input[len][l++]);
    }
    
    while(l <= mid) tmp.push_back(input[len][l++]);
    while(k <= right) tmp.push_back(input[len][k++]);
    
    int p = 0;
    for(int i = left; i <= right; ++i){
        input[len][i] = tmp[p++];
    }
}

void mergeSort(int start, int end, int len){
    int mid = (start+end)/2;
    if(start>end) return;
    if(start==end) return;
    
    mergeSort(start,mid, len);
    mergeSort(mid+1,end, len);
    merge(start, mid, end, len);
}


int main(){
    // input array init
    for(int i = 0; i < 50; ++i){
        vector<string> tmp;
        input[i] = tmp;
    }
    
    // get N
    cin >> N;
    
    // get input and save by length
    for(int i = 0; i < N; ++i){
        string s;
        cin >> s;
        int len = s.length()-1;
        input[len].push_back(s);
    }
    
    // for(int i = 0; i < N; ++i){
    //     for(auto it = input[i].begin(); it!=input[i].end(); ++it){
    //         cout << *it << endl;
    //     }
    // }
    
    // sort input by ascending
    for(int i = 0; i < 50; ++i){
        mergeSort(0,input[i].size()-1,i);
    }
    
    for(int i = 0; i < 50; ++i){
        if(input[i].size()>0)
        {
            cout << input[i][0] << endl;
            for(auto it = input[i].begin()+1; it!=input[i].end(); ++it){
                if(*it != *(it-1))
                    cout << *it << endl;
            }
        }
    }    
}