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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        ListNode*curr=head;
        vector<int>v;
        while(curr){
            v.push_back(curr->val);
            curr=curr->next;
        }
        int n=v.size();
        k%=n;
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
        
        curr=head;
        int i=0;
        while(curr&&i<v.size()){
            curr->val=v[i];
            curr=curr->next;
            i++;
        }
        return head;
    }
};