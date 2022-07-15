#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;
    int before = arr[0];
    q.push(before);
    for (int idx = 1; idx < arr.size(); ++idx)
    {
        before = q.back();
        if (arr[idx] == before)
        {
            continue;
        }
        q.push(arr[idx]);
    }
    while (!q.empty())
    {
        answer.push_back(q.front());
        q.pop();
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
int main()
{
    vector<int> input = {1, 1, 3, 3, 0, 1, 1};
    vector<int> output = solution(input);
}