// 1026
// 재배열 부등식
#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<sstream>

using namespace std;

list<int> tokenize_getline(const string& data, const char delimiter = ' ');
int main(){
    // 몇개의 숫자를 입력받을래?
    int inputnum;
    cin>>inputnum;
    getchar();

    // a 입력받음
    string tmp;
    getline(cin,tmp);
    list<int> a = tokenize_getline(tmp,' ');
    
  
    getline(cin,tmp);
    list<int> b = tokenize_getline(tmp, ' ');
    list<int> c(b);

    

    a.sort();
    c.sort();


    int result = 0;
    list<int>::iterator it1;
    list<int>::iterator it2;
    it2 = c.end();
    it2--;
    for(it1 = a.begin();it1!=a.end();it1++){
        int v1 = *it1;
        int v2 = *it2;
        result+=v1*v2;
        it2--;
    }
    cout<<result;
}    

list<int> tokenize_getline(const string& data, const char delimiter) {
	list<int> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(stoi(token));
	}
	return result;
}
