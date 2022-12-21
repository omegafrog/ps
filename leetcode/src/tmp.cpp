#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int* color;
    int curcolor = 1;
    void bfs(vector<vector<int>>& e, vector<vector<int>>& dislikes){
        int startVertex = 0;
        
        queue<int> q;
        color[startVertex]=curcolor;
        q.push(startVertex);

        while(!q.empty()){
            int curVertex = q.front();
            q.pop();
            for(auto it = e[curVertex].begin(); it!=e[curVertex].end(); ++it){
                int nextVertex = *it;
                if(color[nextVertex] == 0){
                    for(vector<int> dislike : dislikes){
                        if((curVertex == dislike[0]-1 && nextVertex == dislike[1]-1) || 
                        (curVertex == dislike[1]-1 && nextVertex == dislike[0]-1)){
                            
                        }
                        color[nextVertex] = curcolor;
                        q.push(nextVertex);
                    }
                }
            }

        }
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        color = (int*)malloc(sizeof(int)*n);
        vector<vector<int>> v;
        for(int i = 0; i < n; ++i){
            v.push_back(vector<int>());
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
        for(int i =0 ;i < n; ++i){
            color[i] = 0;
        }
        bfs(v, dislikes);
        return !(curcolor>2);

    }
};

int main(int argc, char const *argv[])
{
    int n = 10;
    vector<vector<int>> dislike;
    dislike.push_back(vector<int>({1, 2}));
    dislike.push_back(vector<int>({3, 4}));
    dislike.push_back(vector<int>({5, 6}));
    dislike.push_back(vector<int>({6, 7}));
    dislike.push_back(vector<int>({8, 9}));
    dislike.push_back(vector<int>({7, 8}));

    Solution s;
    cout << s.possibleBipartition(n, dislike);
    return 0;
}
