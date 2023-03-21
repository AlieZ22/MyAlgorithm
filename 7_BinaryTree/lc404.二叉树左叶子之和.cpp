#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
* @method: 所有左叶子之和（注意如何判断是左叶子的），后序遍历（左右中）
*/

class Solution404 {
public:
    int getValue(TreeNode *node){
        if(node == nullptr) return 0;
        int leftVal = 0;
        if(node->left && !node->left->left && !node->left->right){
            leftVal = node->left->val;
        }
        int val = leftVal + getValue(node->left) + getValue(node->right);
        return val;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return getValue(root);
    }
};