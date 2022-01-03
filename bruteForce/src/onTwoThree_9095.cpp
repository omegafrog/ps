
#include <iostream>
#include <vector>
using namespace std;

int addNums[3] = {1,2,3};
int bt = 0;

int sum(vector<int>& nums){
	int ret = 0;
	for(auto it = nums.begin(); it!=nums.end();++it){
		ret+=*it;
	}
	return ret;
}

int oneTwoThree(vector<int>& nums, int number){
	// cout << "bt : " << bt << endl;
	if(sum(nums)==number) return 1;
	else if(sum(nums)>number) return 0;
	
	// for(auto it = nums.begin(); it!=nums.end();++it){
	// 	cout << *it << " ";
	// }
	// cout << endl;
	int ret = 0;
	for(int i=0;i<3;++i){
		if(sum(nums)<number){
			nums.push_back(addNums[i]);
			// bt++;
			// cout << "I : " << i<<endl;
			ret+=oneTwoThree(nums, number);
			// bt--;
			nums.pop_back();
		}
	}
	// cout << "ret:"<< ret << endl;
	
	return ret;
}

int main(){
	int tcase=0;
	cin >> tcase;
	vector<int> nums;
	for(int i=0;i<tcase;++i){
		int num = 0;
		cin >> num;
		cout << oneTwoThree(nums,num) <<endl;
	}
	// cout << oneTwoThree(nums,7) << endl;
}