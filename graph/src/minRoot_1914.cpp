    #include <iostream>
    #include <vector>
    #include <utility>
    #include <queue>
    #define INF 987654321
    using namespace std;

    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        }
    };

    int solution(int n, vector<vector<pair<int, int>>> e, int start, int end){
        int* minRoot = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
        {
            minRoot[i] = INF;
        }


        minRoot[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        int* visited = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
        {
            visited[i]= 0;
        }
        
        q.push({start, 0});
        visited[start] = 1;
        while(!q.empty()){
            pair<int, int> next = q.top();
            q.pop();
            visited[next.first] = 1;
            if(minRoot[next.first] < next.second) continue;
            for( auto iter = e[next.first].begin(); iter != e[next.first].end(); ++iter )
            {
                if( visited[iter->first] == 0 && minRoot[iter->first] > minRoot[next.first] + iter->second){
                    minRoot[iter->first] = minRoot[next.first] + iter->second;
                    q.push({iter->first, minRoot[iter->first]});

                }
            }
        }
        
        return minRoot[end];
        
    }

    int main(int argc, char const *argv[])
    {
        int n;
        int m;
        vector<vector<pair<int, int>>> v;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            v.push_back(vector<pair<int, int>>());
        }
        for (int i = 0; i < m; i++)
        {
            int start;
            int end;
            int w;
            cin >> start >> end >> w;
            v[start-1].push_back({end-1, w});
        }
        int start;
        int end;
        cin >> start >> end;

        cout << solution(n,v, start-1, end-1);
        
        return 0;
    }
