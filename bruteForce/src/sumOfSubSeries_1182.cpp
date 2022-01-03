#include <iostream>
#include <vector>
using namespace std;

#define MAX_S 1000000

int N;
int S;


int sum(vector<int>& ret){
	int sumVal = 0;
	if(ret.empty()==1) return MAX_S+1;
	for(auto it = ret.begin(); it!=ret.end(); ++it){
		sumVal+=*it;
	}
	return sumVal;
}

int sumOfSubSeries(vector<int>& input, vector<int>& ret){
	int returnVal = 0;
	if(ret.size()!=0)
	{	
		int sumVal = sum(ret);
		if(sumVal==S) {return ++returnVal;}
		else if(abs(sumVal)>MAX_S) return returnVal;
		else if(input.empty() == 1) return returnVal;
	}
	
	for(auto it = input.begin(); it!=input.end(); ++it){
		ret.push_back(*it);
		input.erase(it);
		returnVal+=sumOfSubSeries(input, ret);
		input.insert(it, ret.back());
		ret.pop_back();
	}
	cout << returnVal << '\n';
	return returnVal;
}


int main(){
	cin >> N;
	cin >> S;
	vector<int> input;
	vector<int> ret;
	int tmp=0;
	for(int i = 0 ; i< N ; ++i){
		cin >> tmp;
		input.push_back(tmp);
	}
	// for(auto it = input.begin(); it!=input.end(); ++it){
	// 	cout << *it << " ";
	// }
	// cout << '\n';
	int answer = 0;
	answer=sumOfSubSeries(input,ret);
	cout << answer;
}