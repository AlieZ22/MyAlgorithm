#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 二叉树的右视图：自顶向下，从左到右层次遍历，取每层最后一个节点的值加入结果数组
*/

class Solution199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<int> res;
        if(root != nullptr) qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                if(i == size-1){
                    res.push_back(node->val);
                }
                qt.pop();
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
        }
        return res;
    }
};