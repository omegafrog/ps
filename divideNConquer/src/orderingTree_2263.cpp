#include <iostream>
#include <vector>
using namespace std;

vector<int> inOrder;
vector<int> postOrder;
vector<int> preOrder;

void getPreOrder(int post_l, int post_r, int in_l, int in_r){
	if(post_l==post_r) {preOrder.push_back(postOrder[post_l]); return;}
	if(post_l>post_r || in_l>in_r) return;
	
	int mid = postOrder[post_r];
	preOrder.push_back(mid);
	
	for(int i = 0; i<=in_r-in_l; ++i){
		if(mid == inOrder[in_l+i]) {mid = i; break;}
	}
	
	getPreOrder(post_l, post_l+mid-1, in_l, in_l+mid-1);
	getPreOrder(post_l+mid, post_r-1, in_l+mid+1, in_r);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int tmp;
		scanf("%d",&tmp);
		getchar();
		inOrder.push_back(tmp);
	}
	for(int i = 0; i < n; ++i){
		int tmp;
		scanf("%d",&tmp);
		getchar();
		postOrder.push_back(tmp);
	}
	getPreOrder(0,postOrder.size()-1, 0, inOrder.size()-1);
	
	for(auto it = preOrder.begin(); it!=preOrder.end(); ++it){
		printf("%d",*it);
		if( it < preOrder.end()-1) printf(" ");
	}
}