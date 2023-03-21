#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
* @method: 求完全二叉树节点的个数，后序遍历，左右中（其实就是抽象出一个3节点/角的模型，来看需要怎么递归）
*/

class Solution222 {
public:
    int getCnt(TreeNode *node){
        if(node == nullptr) return 0;
        int cntLeft = getCnt(node->left);         // 左
        int cntRight = getCnt(node->right);       // 右
        int cnt = 1 + cntLeft + cntRight;         // 中
        return cnt;
    }
    int countNodes(TreeNode* root) {
        return getCnt(root);
    }
};