#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

/*
* @method: 二叉树中序遍历（左-中-右）
*/

class Solution94 {
public:
    void traversal(TreeNode *curr, vector<int>& vec){
        if(curr == nullptr) return ;
        traversal(curr->left, vec);
        vec.push_back(curr->val);
        traversal(curr->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    // 迭代法
    vector<int> inorderTraversal1(TreeNode* root){
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while(!st.empty() || node){
            while(node){
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};