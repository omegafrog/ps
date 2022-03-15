#include <iostream>
using namespace std;

// Definition for singly-linked list.
typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *ret = nullptr;
        int carry = 0;
        int res = head1->val + head2->val + carry;
        if (res > 9)
        {
            res -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        head1 = head1->next;
        head2 = head2->next;
        ret = new ListNode(res);
        ListNode *tail = ret;
        while (head1 != nullptr && head2 != nullptr)
        {
            res = head1->val + head2->val + carry;
            if (res > 9)
            {
                res -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head1 = head1->next;
            head2 = head2->next;
            tail->next = new ListNode(res);
            tail = tail->next;
        }
        while (head1 != nullptr)
        {
            int res = head1->val + carry;
            if (res > 9)
            {
                res -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head1 = head1->next;
            tail->next = new ListNode(res);
            tail = tail->next;
        }
        while (head2 != nullptr)
        {
            int res = head2->val + carry;
            if (res > 9)
            {
                res -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head2 = head2->next;
            tail->next = new ListNode(res);
            tail = tail->next;
        }
        if (carry == 1)
        {
            tail->next = new ListNode(carry);
        }
        return ret;
    }
};
int main()
{
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    Solution s;
    ListNode *l3 = s.addTwoNumbers(l1, l2);
    while (l3 != nullptr)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }
}