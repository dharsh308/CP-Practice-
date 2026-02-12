#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        stack<TreeNode *> s;
        TreeNode *node = root;
        vector<int> v;
        while (node || !s.empty())
        {
            while (node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            v.push_back(node->val);
            node = node->right;
        }
        return v;
    }
};