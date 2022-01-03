#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
int A[1000];
int cache1[1000];
int cache2[1000];
stack<int> s;
int maxlen=0;
// 책 방식
int getLIS1(int index){
    int& ret = cache1[index];
    if(ret!=-1) return ret;
    
    ret = 1;
    for(int i = index+1; i < N; ++i){
        if(A[index]<A[i]){
            ret = max(getLIS1(i)+1, ret);
        }
    }
    return ret;
}

int getLIS2(){
    
    // get A[i]'s lis
    for(int i = 0; i < N; ++i){
         
        for(int j = 0; j < i; ++j){ 
            if(A[j]<A[i] && cache2[j]+1>cache2[i]){
                cache2[i] = cache2[j]+1;
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < N; ++i){
        if(cache2[i]>ret) ret = cache2[i];
    }
    int tmp = ret;
    for(int i = N-1; i >=0; --i){
        if(tmp == cache2[i]){
            s.push(A[i]);
            tmp--;
        }
        if(tmp==0) break;
    }
    return ret;
}
int main(){
    
    for(int i = 0; i < 1000; ++i){
        cache1[i]=-1;
        cache2[i]=1;
    }
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    int ret = 0;
    // for(int i = 0; i < N; ++i){
    //     ret = max(ret,getLIS1(i));
    // }
    ret = getLIS2();
    cout << ret << '\n';
    if(s.size()>1){
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
            if(s.size()==1) break;
       }
    }
   
    cout << s.top();
    
}