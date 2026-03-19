#include <iostream>
#include <vector>
#include<Stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        TreeNode*curr=root;
        while(true){
            while(curr!=nullptr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            if(--k==0)return curr->val;
            curr=curr->right;
        }
        return 0;
    }
};