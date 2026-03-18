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
    map<int, vector<pair<int, int>>> res;
    void traversal(TreeNode* root, int colNo, int rowNo) {
        if (root == nullptr)
            return;
        res[colNo].push_back({rowNo, root->val});
        traversal(root->left, colNo - 1, rowNo + 1);
        traversal(root->right, colNo + 1, rowNo + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root, 0, 0);
        vector<vector<int>> ans;
        for (auto& i : res) {
            auto& v = i.second;

            sort(v.begin(), v.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });

            vector<int> temp;
            for (auto& i : v)
                temp.push_back(i.second);
            ans.push_back(temp);
        }
        return ans;
    }
};