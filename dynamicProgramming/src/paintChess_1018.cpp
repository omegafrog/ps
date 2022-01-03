#include <iostream>
using namespace std;


int N;
int M;
char ans1[8][8]={'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',};
char ans2[8][8]={'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',};
char input[50][50];
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> input[i][j];
        }
    }
    int ret = 987654321;
    for(int i = 0; i < N-7; ++i){
        for(int j = 0; j < M-7; ++j){
            int count1=0;
            int count2=0;
            for(int y = 0; y < 8; ++y){
                for(int x = 0; x < 8; ++x){
                    if(ans1[y][x]!=input[i+y][j+x]) ++count1;
                    if(ans2[y][x]!=input[i+y][j+x]) ++count2;
                }
            }
            
            ret = min(ret, min(count1,count2));
        }
    }
    // cout << ret1 << ret2;
    cout << ret;
}