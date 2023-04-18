#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights)
{
    long long answer = 0;
    map<int, map<int, int>> m;
    map<int, int> v1;
    v1.insert({weights[0], 1});
    m.insert({weights[0]*2, v1});
    m.insert({weights[0]*3, v1});
    m.insert({weights[0]*4, v1});

    for (int i = 1; i < weights.size(); ++i)
    {
        bool isDoubleMultiplierChecked = false;
        if (m.count(weights[i] * 2) > 0)
        {
            // 똑같은 숫자 없음
            if(m[weights[i]*2].count(weights[i])==0)
                
            answer = answer + m[weights[i] * 2];
            isDoubleMultiplierChecked = true;
        }
        if (m.count(weights[i] * 3) > 0)
        {
            answer = answer + m[weights[i] * 3];
        }
        if (m.count(weights[i] * 4) > 0 && !isDoubleMultiplierChecked)
        {
            answer = answer + m[weights[i] * 4];
        }
        for (int multiplier = 2; multiplier < 5; ++multiplier)
        {
            if (m.count(weights[i] * multiplier) > 0)
            {
                m[weights[i] * multiplier] += 1;
            }
            else
            {
                m.insert({weights[i] * multiplier, 1});
            }
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> v({100, 180, 360, 100, 270});
    cout << solution(v);
    return 0;
}
