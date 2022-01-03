#include <iostream>
#include <vector>
using namespace std;

void prevPermutation(vector<int>& v){
	
	
	// 순열의 맨 끝에서부터 오름차순이 끊어지는 부분을 찾는다.
	if(v.size() == 1 ) {cout << -1 << endl; return;}
	if(v.size() == 2 ){
		if(v[0] < v[1]) cout << -1 << endl;
		else cout << v[1] << " " << v[0] << endl;
		return;
	}
	for(int i = v.size()-1; i>0; --i){
		int j = i-1;
		if(v[j] < v[i]) continue;
		
		// v[j]보다 작고 인덱스가 가장 작은 값을 찾는다.
		// 이전 순열이기 때문에 v[j]는 값이 작아져야 하고, 애랑 가장 가까운 작은 값은
		// 이후 순열이 오름차순이므로 인덱스가 가장큰 값을 찾으면된다.
		
		for( int k = v.size()-1; k>0; --k){
			if(v[j] > v[k]){
				int tmp = v[k];
				v[k] = v[j];
				v[j] = tmp;
				break;
			}
			
		}
		
		// v[j]이후로는 아직도 오름차순이므로, 내림차순으로 바꿔야 한다.
		vector<int> sorted;
		
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
		// 출력
		for(auto it = v.begin(); it!=v.end(); ++it){
			cout << *it << " ";
		}
		return;
	}
	cout << -1 << endl;
}

int main(){
	int n = 0;
  cin >> n;
  vector<int> input;
  int j = 0;
  for (int i = 0; i < n; i++) {
    cin >> j;
    input.push_back(j);
  }
 prevPermutation(input);
}