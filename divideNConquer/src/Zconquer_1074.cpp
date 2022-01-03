#include <iostream>
#include <vector>
using namespace std;

bool found = false;
int n,r,c;
int count = 0;
// time over
void ZConquer_1(int y, int x, int size){
	if(size == 1) {
		if(y==r && x==c) {
			cout << count;
			found = true;
		}
		count++;
		return;
	}
	if(found == true) return;
	size/=2;
	ZConquer_1(y,x,size);
	ZConquer_1(y,x+size,size);
	ZConquer_1(y+size,x,size);
	ZConquer_1(y+size,x+size,size);
}

int pow(int base, int exponent){
	int ret=1;
	for(int i = 0;i <exponent; ++i){
		ret*=base;
	}
	return ret;
}

void ZConquer_2(int y, int x, int size){
	if(size<1){ cout << count; return;}
	int multiply = 0;
	if( (y <= r && r <y+size/2) && ( x <= c && c< x+size/2))
		multiply = 0;
	else if( (y <= r && r < y+size/2) && ( x+size/2 <= c && c < x+size)) 
		{multiply = 1;
		x+=size/2;}
	else if( (y+size/2 <= r && r< y+size) && ( x <= c && c< x+size/2)) 
		{multiply = 2;
		y+=size/2;}
	else if( (y+size/2 <= r && r< y+size) && ( x+size/2 <= c && c< x+size)) 
		{multiply = 3;
		x+=size/2;
		y+=size/2;}
	
	count = count+ multiply*(size/2*size/2);
	ZConquer_2(y,x,size/2);
}

int main(){
	cin >> n >> r >> c;
	// ZConquer(0,0,pow(2,n));
	ZConquer_2(0,0,pow(2,n));
}