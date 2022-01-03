#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> esm;
    esm.push_back(1);
    esm.push_back(1);
    esm.push_back(1);
    
    int e=1,s=1,m=1;
    cin >> e >> s >> m;
	// cout << e << s << m;
    int ret=1;
	// int i = 0;
    while(1){
		if(esm[0] == e && esm[1] == s && esm[2] == m) break;
        
        esm[0]+=1;
        esm[1]+=1;
        esm[2]+=1;
		if(esm[0]>15) esm[0] = 1;
        if(esm[1]>28) esm[1] = 1;
        if(esm[2]>19) esm[2] = 1;
		// cout << esm[0] << esm[1] << esm[2] << endl;
		// i++;
        ++ret;
    }
    cout << ret;
}