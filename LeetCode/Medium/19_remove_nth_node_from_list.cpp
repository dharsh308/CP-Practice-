#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*h1=head;
        int c=0;
        while(h1){
             c++;
            h1=h1->next;
           
        }
        if(n==c){
            ListNode*del=head->next;
            delete head;
            return del;

        }
        h1=head;
        for(int i=0;i<c-1-n;i++){
            h1=h1->next;
        }
        ListNode*del=h1->next;
        h1->next=h1->next->next;
        delete del;
        return head;
    }
};