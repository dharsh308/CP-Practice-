#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int>v;
        ListNode*curr=head;
        while(curr){
            if(curr->val<x)v.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr){
            if(curr->val>=x)v.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        int i=0;
        while(curr&&i<v.size()){
            curr->val=v[i++];
            curr=curr->next;
        }
    return head;
    }
};