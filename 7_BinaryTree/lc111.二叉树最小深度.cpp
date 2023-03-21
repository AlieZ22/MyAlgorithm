#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
* @method: 二叉树的最小深度，注意要从“叶子”节点来找
*/

class Solution111 {
public:
    // 注意，是到叶子节点，如果左子树为空，那么叶子节点要去右子树找
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int lDepth = getDepth(node->left);
        int rDepth = getDepth(node->right);

        if(node->left != nullptr && node->right == nullptr){
            return 1+lDepth;
        }
        if(node->right != nullptr && node->left == nullptr){
            return 1+rDepth;
        }
        return 1+min(lDepth,rDepth);
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};