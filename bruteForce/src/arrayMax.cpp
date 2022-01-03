#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int getVal(vector<int>& v){
	int ret = 0;
	for(auto it = v.begin(); it!=v.end()-1; ++it)
		ret += abs(*it-*(it+1));
	
	return ret;
}

void max(vector<int>& input){
	sort(input.begin(),input.end());
	int biggest = getVal(input);
	while(next_permutation(input.begin(), input.end())>0){
		if(biggest < getVal(input))
			biggest = getVal(input);
	}
	cout << biggest << endl;
}

int main(){
	int n;
	cin >> n;
	vector<int> input;
	for(int i = 0;i<n;++i){
		int j;
		cin >> j;
		input.push_back(j);
		
	}
	max(input);
}