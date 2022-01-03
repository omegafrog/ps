#include <iostream>
using namespace std;

int *N;
int T;
int cache[41][2];



int main(){
    for(int i = 0; i < 41; ++i){
        cache[i][0] = 0;
        cache[i][1] = 0;
    }
    cache[0][0] = 1;
    cache[0][1] = 0;
    cache[1][0] = 0;
    cache[1][1] = 1;
    
    int biggest= -1;
    cin >> T;
    N = new int[T];
    for(int i = 0; i < T; ++i){
        cin >> N[i];
        biggest = max(biggest, N[i]);
    }
    for(int k = 2; k <= biggest; ++k){
        cache[k][0] = cache[k-1][0]+cache[k-2][0];
        cache[k][1] = cache[k-1][1]+cache[k-2][1];
    }
    for(int i = 0; i < T; ++i){
        // cout << N[i];
        cout << cache[N[i]][0] << " " << cache[N[i]][1];
        if(i != T-1) cout << "\n";
    }
}