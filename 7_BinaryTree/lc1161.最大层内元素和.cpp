#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution1161 {
public:
    // 层次遍历，找元素和最大的一层（相同值则取层数较小的返回）
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MAX;
        int sum = INT_MIN;
        int level = 0;
        queue<TreeNode*> qt;
        if(root != nullptr) qt.push(root);
        while(!qt.empty()){
            level++;
            int size = qt.size();
            int tmp_s = 0;
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                qt.pop();
                tmp_s += node->val;
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
            if(tmp_s > sum){
                sum = tmp_s;
                ans = level;
            }
        }
        return ans;
    }
};