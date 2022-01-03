// 10828
#include<iostream>
#include<string>
using namespace std;

class stack{
    int stack[10000];
    int top_point=-1;
    public:
        void push(int element);
        int pop();
        int size();
        bool empty();
        int top();    
};

int check_command(string s);

void stack::push(int element){
    stack[++top_point]=element;
}
int stack::pop(){
    if(!stack::empty()){
        return stack[top_point--];
    } else
        return -1;
}
int stack::size(){ return top_point+1; }
bool stack::empty(){
    if(top_point==-1) return 1;
    else return 0;
}
int stack::top(){
    if(!stack::empty()){
        return stack[top_point];
    }
    else
        return -1;
}

int main(){
    stack s=stack();
    int inputnum;
    cin>>inputnum;
    getchar();
    string command;
    for(int i=0;i<inputnum;i++){
        getline(cin, command);
        if(command.substr(0,4).compare("push")==0){
            s.push(stoi(command.substr(5)));
        }
        else if(command.substr(0,3).compare("pop")==0){
            cout<<s.pop()<<endl;
        }
        else if(command.compare("size")==0){
            cout<<s.size()<<endl;
        }
        else if(command.compare("empty")==0)
            cout<<s.empty()<<endl;
        else 
            cout<<s.top()<<endl;
    }
}