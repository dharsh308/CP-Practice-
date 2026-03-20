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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key == root->val) {
            if ((root->left == nullptr) && (root->right == nullptr)) {
                delete root;
                return nullptr;
            } 
            else if (root->left == nullptr) {
                TreeNode* curr = root->right;
                delete root;
                return curr;
            } 
            else if (root->right == nullptr) {
                TreeNode* curr = root->left;
                delete root;
                return curr;
            } 
            else {
                TreeNode* curr = root->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val);
            }
        }
        return root;
    }
};