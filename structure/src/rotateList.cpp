#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int listSize = 1;
        ListNode *countHead = head;
        ListNode *tail = nullptr;
        while (countHead->next != nullptr)
        {
            countHead = countHead->next;
            listSize++;
            if (countHead->next == nullptr)
            {
                tail = countHead;
            }
        }
        if (listSize < 2 || k == 0)
        {
            return head;
        }
        if (k % listSize == 0)
        {
            return head;
        }
        k = k % listSize;
        int count = listSize - k;
        ListNode *newHead = head;
        ListNode *newTail = nullptr;
        while (count > 1)
        {

            newHead = newHead->next;

            count--;
        }
        if (count == 1)
            newTail = newHead;
        newHead = newHead->next;
        ListNode *ret = newHead;
        tail->next = head;
        newTail->next = nullptr;
        return ret;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2));
    Solution s;
    ListNode *ret = s.rotateRight(head, 0);
}