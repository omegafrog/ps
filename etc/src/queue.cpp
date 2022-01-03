//10845
#include<iostream>
#include<string>
using namespace std;

class queue{
    int data[10010];
    int front;
    int rear;
    public:
        queue(){front=rear=0;};
        void push(int element);
        int pop();
        int size();
        bool empty();
        int start();
        int end();
};


 void queue::push(int element){
         data[++rear]=element;
 }

 int queue::pop(){
     if(!empty()){
         return data[++front];
     }
     else{
         return -1;
     }
 }

 int queue::size(){
     return rear-front;
 }

 bool queue::empty(){
     return front==rear;
 }

int queue::start(){
    if(!empty())
        return data[front+1];
    else
    {
            return -1;
    }
    
}

int queue::end(){
    if(!empty())
        return data[rear];
    else
    {
        return -1;
    }
    
}

int main(){
    queue q = queue();
    int inputnum;
    cin>>inputnum;
    getchar();
    string command;
    for(int i=0;i<inputnum;i++){
        getline(cin, command);
        if(command.substr(0,4).compare("push")==0){
            q.push(stoi(command.substr(5)));
        }
        else if(command.substr(0,3).compare("pop")==0){
            cout<<q.pop()<<endl;
        }
        else if(command.compare("size")==0){
            cout<<q.size()<<endl;
        }
        else if(command.compare("empty")==0)
            cout<<q.empty()<<endl;
        else if(command.compare("front")==0)
            cout<<q.start()<<endl;
        else if(command.compare("back")==0)
            cout<<q.end()<<endl;
    }
}