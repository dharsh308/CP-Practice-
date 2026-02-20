#include <iostream>
#include <vector>
using namespace std;

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *merged = new ListNode();
        ListNode *head = merged;
        ListNode *h1 = list1;
        ListNode *h2 = list2;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                head->next = h1;
                h1 = h1->next;
            }
            else
            {
                head->next = h2;
                h2 = h2->next;
            }
            head = head->next;
        }
        if (h1)
        {
            head->next = h1;
        }
        if (h2)
        {
            head->next = h2;
        }
        return merged->next;
    }
};