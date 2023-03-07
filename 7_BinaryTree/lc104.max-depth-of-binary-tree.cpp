#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
* @method: dfs 左右中，得到二叉树的最大深度
*/

class Solution104 {
public:
    int getDepth(TreeNode *node){
        if(node == nullptr) return 0;
        int lDepth = getDepth(node->left);        // 左
        int rDepth = getDepth(node->right);       // 右
        int depth = 1 + max(lDepth, rDepth);      // 中
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};