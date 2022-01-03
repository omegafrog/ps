// 1002

#include<iostream>
#include<math.h>
using namespace std;

int find_point(int x1,int y1,int x2,int y2,int r1,int r2);
int main(){
    int x1,y1;
    int x2,y2;
    int r1,r2;

    int tcase;
    cin>>tcase;
    getchar();
    for(int i=0;i<tcase;i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        cout<<find_point(x1,y1,x2,y2,r1,r2)<<endl;
        getchar();
    }
}

int find_point(int x1,int y1,int x2,int y2,int r1,int r2){
    double pow_r = pow(x1-x2,2)+pow(y1-y2,2);
    if( x1 == x2 && y1 == y2 && r1 == r2)
        return -1;
    //두 원이 외접할 때
    else if(pow_r==pow(r1+r2,2))
        return 1;
    // 두 원이 내접할 때
    else if(pow(r2-r1,2)==pow_r)
        return 1;
    //두 원이 밖에서 만나지 않을 때
    else if(pow_r>pow(r1+r2,2))
        return 0;
    
    // 한 원이 다른 원 안에 있을 때
    else if(pow_r<pow(r2-r1,2))
        return 0;
    // 두 원이 두 점에서 만날 때
    else 
        return 2;
}