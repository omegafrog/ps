// 9012
#include<iostream>
#include<stack>

using namespace std;

bool check_vps(string s);  

int main(){
    //get number of test case
    int tcase;
    cin>>tcase;
    getchar();
    for(int i=0;i<tcase;i++){
        string input;
        getline(cin,input);
        if(check_vps(input))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}

// 입력받은 string이 vps라면 true, 아니면 false를 반환하는 함수.
bool check_vps(string input){
    // 빈 스택을 만듦.
    stack<char> s;
    
    // 모든 문자열을 순회함.
    int i=0;
    while(input.length()>i){
        //'('를 만나면 스택에 푸시
        if(input[i]=='('){
            s.push(input[i]);
        } // ')'를 만나면 스택이 비어있다면 짝이 안맞으므로 false반환.
        // 스택이 비어있지 않다면 팝
        else if(input[i]==')'){
            if(!s.empty())
                s.pop();
            else
                return false;
        }
        i++;
    }
    // 모든 문자열을 순회했는데 스택에 남아있다면 false. 
    if(!s.empty())
        return false;
    // 모든 false를 통과했다면 true
    return true;
}