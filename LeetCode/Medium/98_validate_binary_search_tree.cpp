#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *node, vector<int> &v)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> val;
        inorder(root, val);
        for (int i = 1; i < val.size(); i++)
        {
            if (val[i] <= val[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};