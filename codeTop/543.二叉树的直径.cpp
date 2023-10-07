#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution_hot543 {
private:
    int ans = 0;
public:
    // 后序遍历
    int diameter(TreeNode* node){
        if(node == nullptr) return 0;

        int diameter_l = diameter(node->left);
        int diameter_r = diameter(node->right);

        ans = max(ans, diameter_l + diameter_r + 1);
        return max(diameter_l, diameter_r) + 1;    // 返回该节点为根的子树的深度
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter_root = diameter(root);
        return ans-1;     // 最长路径为：经过最多节点数的路径 的节点数-1
    }
};