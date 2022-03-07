#include <iostream>
using namespace std;

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ret = nullptr;
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        if (head1 == nullptr)
        {
            ret = head2;
            return ret;
        }
        else if (head2 == nullptr)
        {
            ret = head1;
            return ret;
        }
        if (head1->val > head2->val)
        {
            ret = new ListNode(head1->val, nullptr);
            head1 = head1->next;
        }
        else
        {
            ret = new ListNode(head2->val, nullptr);
            head2 = head2->next;
        }
        ListNode *cur = ret;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                cur->next = new ListNode(head1->val, nullptr);
                head1 = head1->next;
            }
            else
            {
                cur->next = new ListNode(head2->val, nullptr);
                head2 = head2->next;
            }
            cur = cur->next;
        }
        while (head1 != nullptr)
        {
            cur->next = new ListNode(head1->val, nullptr);
            cur = cur->next;
            head1 = head1->next;
        }
        while (head2 != nullptr)
        {
            cur->next = new ListNode(head2->val, nullptr);
            cur = cur->next;
            head2 = head2->next;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
    ListNode *nullList = nullptr;
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    Solution s1 = Solution();
    ListNode *a = s1.mergeTwoLists(nullList, list2);
    while (a != nullptr)
    {
        cout << a->val << " ";
        a = a->next;
    }
    return 0;
}
