#include <iostream>
#include<math.h>
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
int leftHeight(TreeNode*root){
    int lh=0;
    while(root!=nullptr){
        root=root->left;
        lh++;
    }
    return lh;
}
int rightHeight(TreeNode*root){
    int rh=0;
    while(root!=nullptr){
        root=root->right;
        rh++;
    }
    return rh;
}
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(rh==lh)return pow(2,lh)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};