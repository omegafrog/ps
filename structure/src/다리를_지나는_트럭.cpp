#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int curWeight = 0;
    int truckNum = 0;
    int timer = 0;
    queue<int> bridge;
    bridge.push(0);
    bridge.push(0);

    for (int i = 0; i < truck_weights.size(); ++i)
    {
        timer++;

        if (bridge.size() > bridge_length)
        {
            int cur = bridge.front();
            bridge.pop();
            curWeight -= cur;
            if (cur > 0)
            {
                truckNum--;
            }
        }
        int predictWeight = curWeight + truck_weights[i];
        // 다리의 최대 무게를 넘지 않는다면 push하고 타이머 진행
        if (bridge.size() != 0)
        {
            predictWeight -= bridge.front();
        }

        if (predictWeight <= weight)
        {
            bridge.push(truck_weights[i]);
            curWeight += truck_weights[i];
            truckNum++;
        }
        // 다리의 최대 무게를 넘는다면 0을 넣고 타이머 진행
        else
        {
            bridge.push(0);
            i--;
        }
    }
    if (bridge.size() > bridge_length)
    {
        int cur = bridge.front();
        bridge.pop();
        curWeight -= cur;
        if (cur > 0)
        {
            truckNum--;
        }
    }
    // 다리에 남은 트럭이 빠져나올때까지 pop하면서 timer 진행
    while (truckNum > 0)
    {

        if (bridge.size() > bridge_length)
        {
            int cur = bridge.front();
            bridge.pop();
            curWeight -= cur;
            if (cur > 0)
            {
                truckNum--;
            }
        }
        if (truckNum == 0)
            break;
        // 다리의 최대 무게를 넘는다면 0을 넣고 타이머 진행

        bridge.push(0);
        timer++;
    }
    answer = timer;
    return answer;
}

int main()
{
    vector<int> input = {7, 4, 5, 6};
    int res = solution(2, 10, input);
}