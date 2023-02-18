#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

/*
* @method：二叉树前序遍历（中-左-右）
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
    // 迭代法解决二叉树前序遍历（直接处理根节点，先入栈右孩子再入栈左孩子，这样访问顺序就是中左右）
    vector<int> preorderTraversal1(TreeNode* root){
        vector<int> res;
        stack<TreeNode *> st;
        if(root!=nullptr) st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
            // 先入栈右节点，再入栈左节点
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return res;
    }
};