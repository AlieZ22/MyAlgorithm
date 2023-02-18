#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

/*
* @method: 二叉树后序遍历（左-右-中）
*/

class Solution145 {
public:
    void traversal(TreeNode *curr, vector<int>& vec){
        if(curr == nullptr) return;
        traversal(curr->left, vec);
        traversal(curr->right, vec);
        vec.push_back(curr->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    // 迭代法，效仿先序遍历迭代法，调整孩子入栈顺序，得到中右左的结果，再反转结果数组
    void reverse(vector<int>& vec){
        int i = 0, j = vec.size() - 1;
        while(i<j){
            swap(vec[i++], vec[j--]);
        }
    }
    vector<int> postorderTraversal1(TreeNode* root){
        vector<int> res;
        stack<TreeNode *> st;
        if(root!=nullptr)
            st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);
        }
        reverse(res);
        return res;
    }
};