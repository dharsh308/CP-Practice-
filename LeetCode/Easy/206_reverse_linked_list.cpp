#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        vector<int> v;
        while (curr)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int i = v.size() - 1;
        while (curr && i >= 0)
        {
            curr->val = v[i--];
            curr = curr->next;
        }
        return head;
    }
};