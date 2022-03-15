#include <iostream>
#include <vector>
using namespace std;

int N;

typedef struct node
{
    char val;
    struct node *left;
    struct node *right;
} node;
node *head;
vector<node *> nodePointers;

void preOrder(node *cur)
{
    if (cur == NULL)
        return;
    cout << cur->val;
    preOrder(cur->left);
    preOrder(cur->right);
}

void inOrder(node *cur)
{
    if (cur == NULL)
        return;
    inOrder(cur->left);
    cout << cur->val;
    inOrder(cur->right);
}

void postOrder(node *cur)
{
    if (cur == NULL)
        return;
    postOrder(cur->left);
    postOrder(cur->right);
    cout << cur->val;
}

int main()
{
    cin >> N;
    char parent, left, right;
    node *cur = head;
    node firstNode = {'A', NULL, NULL};
    head = &firstNode;
    nodePointers.push_back(&firstNode);
    for (int i = 0; i < N; ++i)
    {
        cin >> parent >> left >> right;
        for (node *tmp : nodePointers)
        {
            if (tmp->val == parent)
            {
                cur = tmp;
                break;
            }
        }
        cur->val = parent;
        if (left == '.' && right == '.')
        {
            continue;
        }
        else if (left == '.')
        {
            cur->right = new node;
            cur->right->val = right;
            cur->right->left = NULL;
            cur->right->right = NULL;
            nodePointers.push_back(cur->right);
        }
        else if (right == '.')
        {
            cur->left = new node;
            cur->left->val = left;
            cur->left->left = NULL;
            cur->left->right = NULL;
            nodePointers.push_back(cur->left);
        }
        else
        {
            cur->right = new node;
            cur->right->val = right;
            cur->right->left = NULL;
            cur->right->right = NULL;
            nodePointers.push_back(cur->right);
            cur->left = new node;
            cur->left->val = left;
            cur->left->left = NULL;
            cur->left->right = NULL;
            nodePointers.push_back(cur->left);
        }
    }
    preOrder(head);
    cout << "\n";
    inOrder(head);
    cout << "\n";
    postOrder(head);
}