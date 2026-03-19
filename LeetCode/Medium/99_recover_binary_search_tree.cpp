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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left) {
            inorder(root->left);
        }
        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;
        if (root->right) {
            inorder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};