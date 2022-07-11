#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

class Node
{
private:
    int value;
    bool oprand;
    class Node *left;
    class Node *right;

public:
    Node(int value, bool oprand)
    {
        this->value = value;
        this->oprand = oprand;
        left = nullptr;
        right = nullptr;
    }
    Node *getLeft()
    {
        return left;
    }
    Node *getRight()
    {
        return right;
    }
    int getOprand()
    {
        return (oprand) ? 1 : -1;
    }
    void setRight(int value)
    {
        right = new Node(value, true);
    }
    void setLeft(int value)
    {
        left = new Node(value, false);
    }
    int getValue()
    {
        return value;
    }
};

int dfs(Node *root, int sum, int target)
{
    int ret = 0;
    if (root->getLeft() == nullptr && root->getRight() == nullptr)
    {
        if (sum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    Node *left = root->getLeft();
    Node *right = root->getRight();
    ret += dfs(left, sum + left->getOprand() * left->getValue(), target);
    ret += dfs(right, sum + right->getOprand() * right->getValue(), target);
    return ret;
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    Node *root = new Node(0, true);
    root->setLeft(numbers[0]);
    root->setRight(numbers[0]);
    queue<Node *> q;
    q.push(root->getLeft());
    q.push(root->getRight());
    for (int i = 1; i < numbers.size(); ++i)
    {
        vector<Node *> v;
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            cur->setLeft(numbers[i]);
            cur->setRight(numbers[i]);
            v.push_back(cur->getLeft());
            v.push_back(cur->getRight());
        }
        for (Node *n : v)
        {
            q.push(n);
        }
    }
    answer = dfs(root, 0, target);

    return answer;
}
int main()
{
    vector<int> input = {1, 1, 1, 1, 1};
    int target = 3;
    int output = solution(input, target);
    cout << output;
}

// #include <string>
// #include <vector>

// using namespace std;

// int select(vector<int>& numbers,vector<int>& oprands,int target, int depth){
//     int sum = 0;
//     int ret = 0;
//     if(depth==0){
//         for(int i = 0; i < numbers.size(); ++i){
//             sum+=numbers[i]*oprands[i];
//         }
//         if(sum==target){
//             return 1;
//         }else{
//             return 0;
//         }
//     }

//     oprands.push_back(-1);
//     ret+=select(numbers, oprands, target, depth-1);
//     oprands.pop_back();
//     oprands.push_back(1);
//     ret+=select(numbers, oprands, target, depth-1);
//     oprands.pop_back();

//     return ret;
// }

// int solution(vector<int> numbers, int target) {
//     int answer = 0;
//     vector<int> oprands;
//     answer = select(numbers, oprands, target, numbers.size());
//     return answer;
// }