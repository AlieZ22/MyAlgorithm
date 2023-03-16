#include <iostream>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

/*
输出二叉树的镜像，后序遍历，swap
*/

class Solution_offer27 {
public:
    // 后序遍历
    TreeNode* dfs(TreeNode *root){
        if(root == nullptr) return nullptr;
        TreeNode *left = dfs(root->left);
        TreeNode *right = dfs(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        TreeNode *res = dfs(root);
        return res;
    }
};