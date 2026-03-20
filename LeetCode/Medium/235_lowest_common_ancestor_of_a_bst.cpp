#include <iostream>
#include <vector>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return nullptr;
        while(root!=nullptr){
            if(p->val<root->val&&q->val<root->val)root=root->left;
            else if(p->val>root->val&&q->val>root->val)root=root->right;
            else{
                return root;
            }
        }
        return nullptr;
    }
};