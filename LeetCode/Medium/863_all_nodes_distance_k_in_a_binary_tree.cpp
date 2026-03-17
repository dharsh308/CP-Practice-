#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void trackParent(TreeNode *root,
                     unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        queue<TreeNode *> q;
        q.push(root);
        parentMap[root] = nullptr;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left != nullptr)
            {
                q.push(curr->left);
                parentMap[curr->left] = curr;
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
                parentMap[curr->right] = curr;
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        trackParent(root, parentMap);

        queue<TreeNode *> q;
        unordered_set<TreeNode *> visited;
        q.push(target);
        visited.insert(target);
        int currLevel = 0;

        while (!q.empty())
        {
            if (currLevel == k)
                break;

            int s = q.size();
            while (s-- > 0)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left != nullptr && !visited.count(curr->left))
                {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right != nullptr && !visited.count(curr->right))
                {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap[curr] != nullptr &&
                    !visited.count(parentMap[curr]))
                {
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            currLevel++;
        }
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};