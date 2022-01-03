#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

ofstream myFile("out.txt");
void up(vector<int>& numArr){
	
	if(numArr.empty()==1) {cout << -1; exit(0);}
	
	if(numArr.back()==1){
		numArr.pop_back();
		up(numArr);
		numArr.push_back(4);
	}
	else if(numArr.back()==2){
		numArr.pop_back();
		up(numArr);
		numArr.push_back(3);
	}
	else if(numArr.back()==3)
		numArr[numArr.size()-1]=2;
	else
		numArr[numArr.size()-1]=1;
}

void down(vector<int>& numArr){
	if(numArr.empty()==1) {cout << -1;  exit(0);}
	
	if(numArr.back()==3){
		numArr.pop_back();
		down(numArr);
		numArr.push_back(2);
	}
	else if(numArr.back()==4){
		numArr.pop_back();
		down(numArr);
		numArr.push_back(1);
	}
	else if(numArr.back()==1)
		numArr[numArr.size()-1]=4;
	else
		numArr[numArr.size()-1]=3;
}

void right(vector<int>& numArr){
	if(numArr.empty()==1) {cout << -1; exit(0);}
	
	if(numArr.back()==1){
		numArr.pop_back();
		right(numArr);
		numArr.push_back(2);
	}
	else if(numArr.back()==4){
		numArr.pop_back();
		right(numArr);
		numArr.push_back(3);
	}
	else if(numArr.back()==2)
		numArr[numArr.size()-1]=1;
	else
		numArr[numArr.size()-1]=4;

}
void left(vector<int>& numArr){
	if(numArr.empty()==1) {cout << -1;exit(0);}
	
	if(numArr.back()==2){
		numArr.pop_back();
		left(numArr);
		numArr.push_back(1);
	}
	else if(numArr.back()==3){
		numArr.pop_back();
		left(numArr);
		numArr.push_back(4);
	}
	else if(numArr.back()==1)
		numArr[numArr.size()-1]=2;
	else
		numArr[numArr.size()-1]=3;
	
}
long int pow(int base, long int exponent){
	long int ret=1;
	for(int i = 0;i <exponent; ++i){
		ret*=base;
	}
	return ret;
}
void moveX(vector<int>& numArr, long int x){
	if(abs(x)<20){
		if(x>0)
			while(x>0){
				right(numArr);
				x--;
			}
		else if(x<0){
			while(x<0){
				left(numArr);
				x++;
			}
		}
		return;
	}
	
	long int exponent=0;
	long int thisX=x;
	while(abs(thisX)>1){
		exponent++;
		thisX/=2;
	}
	vector<int> tmpArr(numArr.begin(), numArr.end()-exponent);
	
	if(x>0)right(tmpArr);
	else left(tmpArr);
	for(auto it = numArr.end()-exponent; it!=numArr.end(); ++it){
		tmpArr.push_back(*it);
	}
	if(x>0)
		x-=pow(2,exponent);
	else 
		x+=pow(2,exponent);
	numArr = tmpArr;
	moveX(numArr,x);
}

void moveY(vector<int>& numArr, long int y){
	if(abs(y)<20){
		if(y>0)
			while(y>0){
				up(numArr);
				y--;
			}
		else{
			while(y<0){
				down(numArr);
				y++;
			}
		}
		return;
	}
	
	long int exponent=0;
	long int thisY=y;
	while(abs(thisY)>1){
		exponent++;
		thisY/=2;
	}
	vector<int> tmpArr(numArr.begin(), numArr.end()-exponent);
	
	if(y>0)up(tmpArr);
	else down(tmpArr);
	for(auto it = numArr.end()-exponent; it!=numArr.end(); ++it){
		tmpArr.push_back(*it);
	}
	if(y>0)
		y-=pow(2,exponent);
	else 
		y+=pow(2,exponent);
	numArr = tmpArr;
	moveY(numArr,y);
}

void quadrant(long int y, long int x, vector<int>& numArr){
	moveX(numArr,x);
	moveY(numArr,y);
}

int main(){
	int d;
	string numbers;
	cin >> d >> numbers;
	long int y,x;
	cin >> x >> y;
	vector<int> numArr;
	for(int i = 0; i<numbers.size(); ++i){
		numArr.push_back(stoi(numbers.substr(i,1)));
	}

	quadrant(y,x,numArr);
	for(auto it = numArr.begin(); it!=numArr.end(); ++it){
		cout << *it;
		myFile << *it;
	}
}