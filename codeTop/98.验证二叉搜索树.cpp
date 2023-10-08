#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution_hot98 {
public:
    // 验证二叉搜索树：中序遍历严格递增
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node){
            while(node){
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
        for(int i=0; i<inorder.size()-1; ++i){
            if(inorder[i+1] <= inorder[i]){
                return false;
            }
        }
        return true;
    }
};