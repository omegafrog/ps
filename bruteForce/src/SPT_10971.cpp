#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321;

int n;
int *visited;
int **w;

int Tsp(vector<int>& way, vector<int>& result, int currentDist){
	// base case : visit all cities, success
	if(way.size() == n ){
		if(w[way.back()][way[0]!=0])
			return currentDist + w[way.back()][way[0]];
		else
			return INF;
	 }
	
	int ret = INF;
	int shortestCity = -1;
	if(way.size() == 0) {visited[0] = 1; way.push_back(0); }
	
	int current = way.back();
	for(int next = 0; next < n; ++next ){
		if(visited[next] == 1) continue;
		if(w[current][next]!=0)
		{
			visited[next]=1;
			way.push_back(next);

			int cand = Tsp(way, result, currentDist + w[current][next]);
			visited[next] = 0;
			way.pop_back();
			if(ret>cand) shortestCity = next;
			ret = min(ret, cand);
		}
	}
	if(shortestCity>-1) result.push_back(shortestCity);
	return ret;
}

int main(){
	cin >> n;
	cin.ignore();
	visited = new int[n];
	for(int i =0;i<n;++i) visited[i]=0;
	
	w = new int* [n];
	for(int i =0 ;i<n; ++i){
		w[i] = new int [n];
	}
	
	for(int i = 0; i<n;++i){
		for(int j = 0; j<n; ++j){
			cin >> w[i][j];
		}
	}
	
	vector<int> way;
	vector<int> ret;
	int answer = Tsp(way, ret, 0);
	cout << answer;
}