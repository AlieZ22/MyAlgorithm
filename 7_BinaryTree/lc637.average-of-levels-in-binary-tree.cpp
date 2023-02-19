#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 二叉树每层的平均值：层次遍历，每一层统计和，以及计算均值
*/

class Solution637 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<double> res;
        if(root != nullptr) qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            double sum = 0;
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                qt.pop();
                sum += node->val;
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
            sum = sum / size;
            res.push_back(sum);
        }
        return res;
    }
};