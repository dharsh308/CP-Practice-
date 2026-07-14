#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
       ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
public:
void insertionsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}
ListNode* insertionSortList(ListNode* head) {
    if (!head) return nullptr;
    vector<int> arr;
    ListNode* curr = head;
    while (curr) {
        arr.push_back(curr->val);
        curr = curr->next;
    }
    insertionsort(arr);
    ListNode* sortedHead = new ListNode(arr[0]);
    ListNode* node = sortedHead;
    for (int i = 1; i < arr.size(); ++i) {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }
    return sortedHead;
}

};