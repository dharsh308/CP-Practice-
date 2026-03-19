#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == nullptr)
            return;
        if (root->left)
            inorder(root->left, v);
        v.push_back(root->val);
        if (root->right)
            inorder(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> val;
        inorder(root, val);

        int l = 0, r = val.size() - 1;
        while (l < r) {
            int sum = val[l] + val[r];
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else if (sum > k)
                r--;
        }
        return false;
    }
};