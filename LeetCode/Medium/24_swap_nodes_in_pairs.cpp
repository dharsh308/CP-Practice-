#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *curr = head;
        while (curr && curr->next)
        {
            swap(curr->val, curr->next->val);
            curr = curr->next->next;
        }
        return head;
    }
};