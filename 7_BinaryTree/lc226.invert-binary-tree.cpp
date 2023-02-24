#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
* @method: 层次遍历，每次交换左右节点
*/

class Solution226 {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> qt;
        if(root != nullptr) qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                qt.pop();
                swap(node->left, node->right);
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
        }
        return root;
    }
};