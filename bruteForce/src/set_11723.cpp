#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// #ifdef DEBUG
// ifstream myInputFile("input.txt");
// ofstream myOutputFile("output.txt");
// #endif
// 집합에 숫자가 들어갔는지 확인한다.
vector<bool> hasNum(21,false);

int check(int x){ return hasNum[x]==true;}
void add(int x){ if(check(x)==0) hasNum[x]=true; }
void remove(int x){ if(check(x)==1) hasNum[x]=false;}
void toggle(int x){ hasNum[x]=(check(x)==1)?false:true;}
void all(){for(int i =1;i<=20; ++i) hasNum[i]=true;}
void empty(){for(int i=1; i<=20; ++i) hasNum[i]=false;}

int main(){
	int m;
	cin >> m;
	cin.ignore();
	int index = 0;
	for(int i=0;i<m;++i){
		#ifndef DEBUG
			char temp[1000];
			scanf("%[^\n]s",temp);
			getchar();
			string input = temp;
		#else
			getline(myInputFile,input);
		#endif
		
		index = 0;
		index = input.find(" ",index);
		string op = input.substr(0,input.begin()+index-input.begin());
		string operand = input.substr(index+1,input.size()-index+1);
		#ifndef DEBUG
			if(op.compare("add")==0) add(stoi(operand));
			else if(op.compare("remove")==0) remove(stoi(operand));
			else if(op.compare("check")==0) printf("%d\n",check(stoi(operand)));
			else if(op.compare("toggle")==0) toggle(stoi(operand));
			else if(op.compare("all")==0) all();
			else if(op.compare("empty")==0) empty();
		#else
			cout << op << " " << operand << "\n";
			if(op.compare("add")==0) add(stoi(operand));
			else if(op.compare("remove")==0) remove(stoi(operand));
			else if(op.compare("check")==0) myOutputFile << check(stoi(operand)) << '\n';
			else if(op.compare("toggle")==0) toggle(stoi(operand));
			else if(op.compare("all")==0) all();
			else if(op.compare("empty")==0) empty();
		#endif
	}
}
