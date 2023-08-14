#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution_hot102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> qt;
        if(root != nullptr) qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            vector<int> tmp;
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                qt.pop();
                tmp.push_back(node->val);
                if(node->left != nullptr) qt.push(node->left);
                if(node->right != nullptr) qt.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};