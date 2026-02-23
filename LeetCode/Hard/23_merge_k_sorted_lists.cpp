#include <iostream>
#include <vector>
#include <queue>
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
    struct compare
    {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;

        for (auto i : lists)
        {
            if (i)
                pq.push(i);
        }

        ListNode *merged = new ListNode(0);
        ListNode *head = merged;

        while (!pq.empty())
        {
            ListNode *min = pq.top();
            pq.pop();
            head->next = min;
            head = head->next;
            if (min->next)
            {
                pq.push(min->next);
            }
        }
        return merged->next;
    }
};
