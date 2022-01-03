#include <iostream>
#include <vector>
using namespace std;

int N;
int K;

vector<int> result;
bool* selected;

// cur start from 0
int countCombination(int cur){
    // base case
    // after select K'th num
    if(cur == K){
        return 1;
    }

    // find the start value to recursion
    int smallest;
    // return value
    int ret = 0;
    // next selected number must be bigger than current number
    // so it prevents duplicate counting
    if(result.empty()){
        smallest = 0;
    }else smallest = result.back();

    // recursion
    for(smallest; smallest < N; ++smallest){
        if(!selected[smallest]){
            selected[smallest]=true;
            result.push_back(smallest);
            ret+=countCombination(cur+1);
            selected[smallest]=false;
            result.pop_back();
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    cin >> N >> K;
    selected = new bool[N];
    for (int i = 0; i < N; ++i)
    {
        selected[i] = false;
    }

    cout << countCombination(0);
    
    return 0;
}
