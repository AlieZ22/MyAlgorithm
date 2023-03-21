#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
* @method: 对称二叉树，层次遍历对称检查（外侧，内侧）
*/

class Solution101 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> qt;
        qt.push(root->left);
        qt.push(root->right);
        while(!qt.empty()){
            TreeNode *leftN = qt.front(); qt.pop();
            TreeNode *rightN = qt.front(); qt.pop();
            // 若左右节点都空，继续
            if(!leftN && !rightN){
                continue;
            }
            // 如果有一个节点空，或者两个节点值不同，返回false
            if(!leftN || !rightN || leftN->val != rightN->val){
                return false;
            }
            // 依次放入：左节点左孩子，右节点右孩子，左节点右孩子，右节点左孩子
            qt.push(leftN->left);
            qt.push(rightN->right);
            qt.push(leftN->right);
            qt.push(rightN->left);
        }
        return true;
    }
};