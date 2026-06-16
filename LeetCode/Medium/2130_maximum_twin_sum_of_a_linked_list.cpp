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
    int pairSum(ListNode* head) {
        int res=0;
        vector<int>list;
        ListNode*curr=head;
        while(curr){
            list.push_back(curr->val);
            curr=curr->next;
        }
        int n=list.size();
        for(int i=0;i<n;i++){
            int twin=n-1-i;
            if(twin>0&&twin<n){
                int sum=list[i]+list[twin];
                res=max(res,sum);
            }
        }
        return res;
    }
};