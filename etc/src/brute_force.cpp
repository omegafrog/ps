// 14501
// brute force : 무작정 다해보기
// dynamic programming : 반복되는 부분의 연산을 저장해놓고 사용하는 방식
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class worktable{

    public:
        void set_worktable(int d, int t, int p){
            this->d = d;
            this->t = t;
            this->p = p;
        }
        list<int> s;
        
        int p;
        // date
        int d;
        // elapsed time
        int t;
        // pay
};


class tableHandler{
    // pointer for worktable array
    worktable* wp;
    // end
    int end;
    public:
        tableHandler(int end){ 
            this->end = end ;
            wp = new worktable[end];   
        }
        int get_max();
        void set_table();
        int f(worktable* fp, worktable* wp, int start, int end);
        

};

int tableHandler::f(worktable* fp,worktable* wp, int start, int end){
    if(start+wp->t<=end-1||(wp->d==end-1&&wp->t==1)){
        fp->s.push_back(start);  
        for(int i=0;wp->d+wp->t+i<end;i++){
            if(f(fp,wp+wp->t+i,start+wp->t+i,end)==-1)
                continue;
            else
            {
                worktable* tmp = fp;
                while(tmp!=wp){
                    fp->s.push_back(tmp->d);
                    tmp++;
                }
            }   
        }
    } else
        return -1;
}


void tableHandler::set_table(){
    // input elapsed time, pay
    int t,p;
    for(int i=0;i<end;i++){
        cin>>t>>p;
        getchar();
        wp[i].set_worktable(i,t,p);
    }
}
int tableHandler::get_max(){
    
    int sum=0;
    
    list<int> result;
    for(int i=0;i<end;i++){
        f(wp+i,wp+i,i,end);
        int sum=0;
        list<int>::iterator iter=wp[i].s.begin();
        while(iter!=wp[i].s.end()){
            int c = *iter;
            sum+=wp[c].p;
            result.push_back(sum);  
        }
    result.sort();
    }
    return result.back();
}


int main(){
    int maxdate;
    cin>>maxdate;
    getchar();

    tableHandler h = tableHandler(maxdate);
    h.set_table();
    h.get_max();
}