#include <iostream>
#include <vector>
using namespace std;

vector<int> input;

void merge(int left, int mid, int right){
	int l = left;
	int k = mid+1;
	int j = right;
	vector<int> tmp;
	while(l<=mid && k<=right){
		if(input[l]>input[k]) tmp.push_back(input[k++]);
		else tmp.push_back(input[l++]);
	}
	
	while(l<=mid)tmp.push_back(input[l++]);
	while(k<=right)tmp.push_back(input[k++]);
}

void mergeSort(int start, int end){
	int mid=(start+end)/2;
	
	if(start==end) return;
	
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	merge(left, mid, rignt);
}