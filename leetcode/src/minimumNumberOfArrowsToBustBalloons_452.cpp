#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);

        int curArr = points[0][1];
        int arrow = 1;
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] > curArr || curArr > points[i][1]){
                curArr = points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
