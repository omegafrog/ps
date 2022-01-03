#include <iostream>
#include <vector>
using namespace std;

struct work{
	int time;
	int pay;
};

vector<struct work> calender;
int biggest = 0;

void biggestPay(vector<struct work>::iterator it, int currentPay){
	if(it >= calender.end()) return;
	// cout << it->time << " " << it->pay;
	// 만약 지금 하고 있는 일이 퇴사일 이후에도 해야 하는 일이라면 추가하지 않아야 한다.
	// 이 경우를 체크해 준다.
	if(it + it->time-1 < calender.end()) {
		currentPay+=it->pay;
		if(biggest < currentPay) biggest = currentPay;
		biggestPay(it+1, currentPay-it->pay);
	}
	// 퇴사일 이후에 해야 하는 일인 경우 추가되지 않았기 때문에
	// currentPay그대로 넘겨준다.
	else biggestPay(it+1, currentPay);
	biggestPay(it+it->time, currentPay);
}

int main(){
	int N;
	cin >> N;
	int tmp1,tmp2;
	for(int i =0;i<N;++i){
		struct work newWork = {0,0};
		cin >> tmp1 >> tmp2;
		newWork.time = tmp1;
		newWork.pay = tmp2;
		calender.push_back(newWork);
	}
	biggestPay(calender.begin(),0);
	cout << biggest;
}