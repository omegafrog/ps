#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int k;
ofstream myFile("out.txt");
// void getLotto(vector<int>& v){
// 	// -1을 삭제한다.
// 	v.erase(v.begin());
	
// 	do{
// 		for(auto it = v.begin();it!=v.end();++it){
// 			cout << *it << " ";
// 		}
// 		cout << '\n';
// 	}while(next_permutation(v.begin(),v.end()));
// }

void getS(vector<int>& input, vector<int>& selected){
	// -1을 포함한 selected의 크기가 7이면 가능한 순열을 출력한다.
	if(selected.size() == 7) {
		for(auto it = selected.begin()+1;it!=selected.end();++it) {
			myFile << *it;
			if(it!=selected.end()-1) myFile << " ";
			/*getLotto(selected);*/
		}
		myFile << '\n';
	}
	
	// k개의 숫자들중에서 6개를 오름차순으로 뽑는다.
	for(int i=0;i<input.size();++i){
		// 이 뽑는 순열은 숫자에 관계가 없어서 오름차순으로 강제해서 얻는다.
		// selected에 아무것도 선택 안했을 때에는 -1이 들어가 있기 때문에 문제없다.
		if(selected.back()>input[i]) continue;
		// 1개의 숫자를 선택한다.
		selected.push_back(input[i]);
		// 숫자 후보 벡터에서 선택한 숫자를 삭제한다.
		input.erase(input.begin()+i);
		// debug
		// cout << selected.back() << " ";
		// 다음 차례의 숫자를 재귀적으로 뽑느다.
		getS(input,selected);
		// 조작한 벡터를 원래대로 되돌린다.
		input.insert(input.begin()+i, selected.back());
		selected.pop_back();
	}
}
int main(){
	vector<int> v;
	vector<int> selected;
	selected.push_back(-1);
	string input;
	while(1)
	{
		getline(cin, input);
		int index = 0;
		int start = 0;
		while(input.find(" ",index)!=-1){
			index = input.find(" ",index);
			string substring = input.substr(start,index-start);
			int i = stoi(substring);
			v.push_back(i);
			start = index+1;
			index++;
		}
		v.push_back(stoi(input.substr(start)));
		k = v[0];
		v.erase(v.begin());
		if(v.back() == 0) break;
		getS(v,selected);
		v.clear();
		selected.erase(selected.begin()+1,selected.end());
		cout << '\n';
	}
}