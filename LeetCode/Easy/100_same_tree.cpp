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
    void preorder(TreeNode *node, vector<int> &v)
    {
        if (node == nullptr)
        {
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(node->val);
        preorder(node->left, v);
        preorder(node->right, v);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> v1, v2;
        preorder(p, v1);
        preorder(q, v2);
        return v1 == v2;
    }
};