#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution1448 {
public:
    int ans = 0;
    // dfs，记录路径之前最大的值
    void dfs(TreeNode* node, int pmax){
        if(node->val >= pmax){
            ans++;
            pmax = node->val;
        }
        if(node->left) dfs(node->left, pmax);
        if(node->right) dfs(node->right, pmax);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN); // 注意看节点权值的范围，所以最开始取INT_MIN
        return ans;
    }
};