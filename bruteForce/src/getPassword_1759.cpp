#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int L;
int C;
int vnum=0;
int cnum=0;
char vowel[]={'a','i','o','u','e'};

bool compare(char i, char j) { return static_cast<int>(i) < static_cast<int>(j);}
void getPassword(vector<char>& input, vector<char>& ret){
	if(ret.size() == L+1) {
		if(vnum>=1 && cnum>=2)
		{
			ret.erase(ret.begin());
			for(auto it = ret.begin(); it!=ret.end();++it){
				if(it == ret.end()-1) {/*myFile << *it;*/ cout << *it; break;}
				cout << *it;
				/*myFile << *it << " ";*/
			}
			cout << '\n';
			/*myFile << '\n';*/
			ret.insert(ret.begin(),'0');
			return;
		}
	}
	
	sort(input.begin(),input.end(),compare);
	// cout << "input:";
	// for(auto it = input.begin(); it!=input.end();++it){
	// 		cout << *it << " ";
	// }
	// cout << '\n';
	// cout << "ret:";
	// for(auto it = ret.begin(); it!=ret.end();++it){
	// 		cout << *it << " ";
	// }
	// cout << '\n';
	
	for(int i = 0 ; i < input.size(); ++i){
		if(ret.back() < input[i] ){
			bool isVowel=false;
			for(int k = 0 ; k< 5; ++k){
				if(vowel[k] == input[i]) {vnum++; isVowel=true; break;}
			}
			if(isVowel == false) cnum++;
			ret.push_back(input[i]);
			input.erase(input.begin()+i);
			// for(auto it = input.begin(); it!=input.end();++it){
			// 	cout << *it << " ";
			// }
			// for(auto it = ret.begin(); it!=ret.end();++it){
			// 	cout << *it << " ";
			// }
			getPassword(input,ret);
			input.insert(input.begin()+i,ret.back());
			ret.pop_back();
			if(isVowel == true) vnum--;
			else cnum--;
		}
	}
}

int main(){
	vector<char> input;
	vector<char> ret;
	ret.push_back('0');
	cin >> L >> C;
	cin.ignore();
	string inputStr;
	getline(cin, inputStr);
	int index = 0;
	input.push_back(inputStr[0]);
	while(inputStr.find(" ",index)!=-1){
		index = inputStr.find(" ",index);
		// cout << index;
		// cout << inputStr[index+1];
		input.push_back(inputStr[index+1]);
		index+=1;
	}
	// for(auto it = ret.begin(); it!=ret.end();++it){
	// 	cout << *it << " ";
	// }
	// for(auto it = input.begin(); it!=input.end();++it){
	// 	cout << *it << " ";
	// }
	getPassword(input,ret);
}