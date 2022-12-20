#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        return dfs(rooms);
    }
    bool dfs(vector<vector<int>> &rooms)
    {
        bool *visited = (bool *)malloc(sizeof(bool) * rooms.size());
        for (int i = 0; i < rooms.size(); i++)
        {
            visited[i] = false;
        }
        int startRoomNum = 0;
        stack<int> s;
        s.push(startRoomNum);
        visited[startRoomNum] = true;

        while (!s.empty())
        {
            int currentRoomNum = s.top();
            s.pop();

            for (auto nextRoom = rooms[currentRoomNum].begin(); nextRoom != rooms[currentRoomNum].end(); ++nextRoom)
            {

                int nextRoomNum = *nextRoom;
                if (visited[nextRoomNum] == false)
                {
                    visited[nextRoomNum] = true;
                    s.push(nextRoomNum);
                }
            }
        }
        bool allVisited = true;
        for (int i = 0; i < rooms.size(); i++)
        {
            if(visited[i] == false){
                allVisited = false;
                break;
            }
        }
        return allVisited;
    }
};