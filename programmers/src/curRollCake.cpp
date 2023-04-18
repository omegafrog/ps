#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping)
{
    int answer = -1;
    vector<int> forwardTopping;
    vector<int> backwardTopping;
    unordered_set<int> toppingSet;

    for (int cur : topping)
    {
        toppingSet.insert(cur);
        forwardTopping.push_back(toppingSet.size());
    }
    toppingSet.clear();
    for (int i = topping.size() - 1; i >= 0; --i)
    {
        toppingSet.insert(topping[i]);
        backwardTopping.push_back(toppingSet.size());
    }
    reverse(backwardTopping.begin(), backwardTopping.end());
    for (int i = 0; i < topping.size() - 1; ++i)
    {
        int j = i + 1;
        if (forwardTopping[i] == backwardTopping[j])
            answer++;
    }
    if (answer == -1)
    {
        answer = 0;
    }
    else
    {
        answer += 1;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> toppings({1, 2, 1, 3, 1, 4, 1, 2});
    cout << solution(toppings);
    return 0;
}
