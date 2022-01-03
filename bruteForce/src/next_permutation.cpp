#include <iostream>
#include <vector>
using namespace std;

void next_permutation(vector<int>& v){
	if(v.size() == 1 ) cout << -1 << endl;
	if(v.size() == 2 ){
		if(v.size[0]<v.size[1]){
			cout << v.size[1] << " " << v.size[0] << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	// 순열의 맨 마지막부터 내림차순이 깨지는 곳을 찾는다.
	for(int i = v.size()-1; i>0; --i){ 
		int j = i-1;
		if(v[j]>v[i]) continue;
		// v[j]보다 크면서 그들 중에서는 가장 작은(=인덱스가 가장 큰) 값을 찾는다.
		// 그리고 그 값을 v[j]와 변경한다.
		for(int k = v.size()-1; k>j; ++k){
			if(v[k] > v[j]){
				int tmp = v[j];
				v[j] = v[k];
				v[k] = tmp;
			}
		}
		// v[j]이후의 값들을 오름차순으로 정렬하면 된다.
		// bubblesort로 정렬하였다.
		// j++;
		// for(j; j<v.size()-1;++j){
		// 	int smallest = v[j];	
		// 	for(int k = j+1 ; k < v.size(); ++k){
		// 		if(smallest > v[k]) smallest = v[k];
		// 	}
		// 	v[j] = smallest;
		// }
		// 이렇게 하면 원래 데이터인 v가 손상되어 원하는 값이 안나옴.
		// 또 마지막 인덱스를 순회하지 않아서 잘못된 코드임.
		vector<int> sotred;
		for(int l = j+1; l<v.size();++l){
			// for(int start = 0; start<v.size(); ++start){
			// 	cout << v[start];
			// }
			// cout << endl;
			for(int k = j+1; k<v.size()-1; ++k){
				if(v[k] < v[k+1]){
					int tmp = v[k+1];
					v[k+1] = v[k];
					v[k] = tmp;
				}
			}
			// for(int start = 0; start<v.size(); ++start){
			// 	cout << v[start];
			// }
			// cout << endl;
		}
		for(int k = 0; k<sorted.size(); ++k){
			v[++j] = sorted[k];
		}
		for(auto it = v.begin(); it!=v.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << -1 << endl;
}

int main() {
  int n = 0;
  cin >> n;
  vector<int> input;
  int j = 0;
  for (int i = 0; i < n; i++) {
    cin >> j;
    input.push_back(j);
  }
  nextPermutation(input, n);
}