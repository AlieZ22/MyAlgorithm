#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method：递归法，二叉树前序遍历（中-左-右）
* 递归解法：明确三要素
* 1，确定递归函数的参数和返回值
* 2，确定终止条件
* 3，确定单层递归的逻辑
*/

class Solution144 {
public:
    void traversal(TreeNode *curr, vector<int>& vec){
        if(curr == nullptr) return;
        vec.push_back(curr->val);
        traversal(curr->left, vec);
        traversal(curr->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};