// 1934
// 유클리드 호제법을 이용한 최대공약수 구하기
// 그리고 최소공배수의 성질을 이용해서 최소공배수 구하기
#include<iostream>

using namespace std;

int main(){
    int tcase;
    cin>>tcase;
    getchar();


    int gcd;
    int a,b;
    int n1, n2;
    for(int i=0;i<tcase;i++){
        cin>>n1>>n2;
        a = n1;
        b = n2;
        if(a>b){
            // gcd
            while(a%b!=0){
                int r = a%b;
                a=b;
                b=r;
            }
            gcd = b;
        }
        else{
            //gcd
            while(b%a!=0){
                int r = b%a;
                b=a;
                a=r;
            }
            gcd = a;
        }
        // n1 = gcd * N1
        // n2 = gcd * N2
        // lcm = gcd * N1 * N2


        int lcm = gcd * n1/gcd * n2/gcd;
        cout<<lcm<<endl;
    }



}