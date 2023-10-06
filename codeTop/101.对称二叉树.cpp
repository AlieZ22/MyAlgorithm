#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution_hot101 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> qt;
        qt.push(root->left);
        qt.push(root->right);
        while(!qt.empty()){
            TreeNode *leftN = qt.front(); qt.pop();
            TreeNode *rightN = qt.front(); qt.pop();

            // 同时为空，则继续
            if(!leftN && !rightN) continue;

            // 某一个为空，或者两者值不相同则返回false
            if(!leftN || !rightN || leftN->val != rightN->val) return false;

            // 继续迭代
            qt.push(leftN->left);
            qt.push(rightN->right);
            qt.push(leftN->right);
            qt.push(rightN->left);
        }
        return true;
    }
};