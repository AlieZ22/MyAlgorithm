#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
* @method: 层次遍历，记录每一层（通过队列在遍历前的大小，每层做一个循环）
*/

class Solution102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qt;
        if(root != nullptr) qt.push(root);
        vector<vector<int> > res;
        while(!qt.empty()){
            int size = qt.size();
            vector<int> tmp;
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                qt.pop();
                tmp.push_back(node->val);
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};