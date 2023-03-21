#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
* @method: 判断是否为平衡二叉树，后序遍历判断两个子树的高度差
*/

class Solution110 {
public:
    bool res = true;
    int getHigh(TreeNode *node){
        if(node == nullptr) return 0;
        int highLeft = getHigh(node->left);
        int highRight = getHigh(node->right);
        int highDiff = highLeft - highRight;
        if(highDiff > 1 || highDiff < -1){
            res = false;
        }
        return 1+max(highLeft,highRight);
    }
    bool isBalanced(TreeNode* root) {
        int high = getHigh(root);
        return res;
    }
};