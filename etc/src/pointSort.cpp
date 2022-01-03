#include <iostream>

using namespace std;

class Point{
    int point_x;
    int point_y;
    public:
        Point();
        Point(int x, int y);
        int getX();
        int getY();
        Point* getNext();
};

Point::Point():Point(0,0){};

Point::Point(int x, int y){
    point_x=x;
    point_y=y;
};

int Point::getX(){
    return point_x;
};

int Point::getY(){
    return point_y;
}

class PointHandler{
    int InstanceNum;
    int lastInstance=-1;
    public:
        Point* p;
    public:
        PointHandler(int num);
        void addPointInstance(int x, int y);
        void bubblesortPointInstance();
        int partition_X( int left, int right);
        void quick_sort(int left, int right);
        
        Point* printHandler();
};

PointHandler::PointHandler(int num){InstanceNum=num; p=new Point[InstanceNum];}

void PointHandler::addPointInstance(int x, int y){
    p[++lastInstance]=Point(x,y);
}
void PointHandler::bubblesortPointInstance(){
    for(int j=0;j<InstanceNum-2;j++){
        for(int i=0;i<InstanceNum-j;i++){
            if(p[i].getX()>p[i+1].getX()){
                Point tmp;
                tmp=p[i+1];
                p[i+1]=p[i];
                p[i]=tmp;
            }
        }
    }
    
}
Point* PointHandler::printHandler(){
    for(int i=0;i<InstanceNum;i++){
        int x=p[i].getX();
        int y =p[i].getY();
        cout<<x<<" "<<y<<"\n";
    }
}

int PointHandler:: partition_X(int left, int right){
  int pivot;
  Point tmp;
  int low, high;

  low = left;
  high = right + 1;
  pivot = p[left].getX(); // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

  /* low와 high가 교차할 때까지 반복(low<high) */
  do{
    /* list[low]가 피벗보다 작으면 계속 low를 증가 */
    do {
      low++; // low는 left+1 에서 시작
    } while (low<=right && p[low].getX()<pivot);
        
    /* list[high]가 피벗보다 크면 계속 high를 감소 */
    do {
      high--; //high는 right 에서 시작
    } while (high>=left && p[high].getX()>pivot);

    // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
    if(low<high){
        tmp=p[low],p[low]=p[high],p[high]=tmp;
    }
  } while (low<high);

  // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
     tmp=p[left];
     p[left]=p[right];
     p[right]=tmp;
    
  // 피벗의 위치인 high를 반환
  return high;
}

// 퀵 정렬
void PointHandler::quick_sort(int left, int right){

  /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
  if(left<right){
    // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
    int q = partition_X(left, right); // q: 피벗의 위치

    // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
    quick_sort(left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
    quick_sort(q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
  } 
  Point tmp;
    for(int i=0;i<InstanceNum-1;i++){
        if(p[i].getX()==p[i+1].getX()){
            if(p[i].getY()>p[i+1].getY()){
               
                tmp=p[i+1];
                p[i+1]=p[i];
                p[i]=tmp;
            }
        }
    }

}


int main(){
    int num;
    int x,y;
    cin>>num;
    PointHandler p =PointHandler(num);
    for(int i=0;i<num;i++){
        
        cin>>x>>y;
        p.addPointInstance(x, y);
    }
    p.quick_sort(0, num-1);
    p.printHandler();
    return 0;
}