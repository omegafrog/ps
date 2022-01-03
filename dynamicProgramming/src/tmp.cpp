#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
vector<int> A;
vector<int> nums;
vector<bool> ans;

int main(){
    cin >> N;
    int p;
    for(int i = 0; i < N; ++i){
        cin >> p;
        A.push_back(p);
    }
    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> p;
        nums.push_back(p);
    }
    for(auto it = nums.begin(); it!=nums.end(); ++it){
        bool flag = false;
        for(auto it2 = A.begin(); it2!=A.end(); ++it2){
            if(*it == *it2) {flag = true; break; }
        }
        if(flag == true) cout << 1 << endl;
        else cout << 0 << endl;
    }
}