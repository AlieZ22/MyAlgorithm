#include <iostream>
#include "TreeNode.h"
#include <algorithm>
using namespace std;

/*
  递归
  节点的贡献值：以该节点为根的子树中，以该节点为起点的一条最大和路径
  空节点：最大贡献为0；非空节点：节点值与子节点最大贡献值之和（最大贡献>0时，才选取）
*/
class Solution_hot124 {
public:
    int res = INT_MIN;
    int maxVal(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int leftVal = max(maxVal(node->left), 0);
        int rightVal = max(maxVal(node->right), 0);
        int newVal = node->val + leftVal + rightVal;
        res = max(res, newVal);
        return node->val + max(leftVal, rightVal);
    }
    int maxPathSum(TreeNode* root) {
        maxVal(root);
        return res;
    }
};