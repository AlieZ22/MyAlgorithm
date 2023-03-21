#include <iostream>
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 找二叉树的所有路径，前序遍历，回溯
*/

class Solution257 {
public:
    vector<string> res;
    // 前序遍历（中左右），遇到空节点提交s
    void backtrack(TreeNode *node, string s){       
        if(node == nullptr) return ;
        if(s.size()!=0){
            s.append("->");
        }
        s.append(to_string(node->val));
        if(node->left==nullptr && node->right==nullptr){
            res.push_back(s);
        }
        if(node->left) backtrack(node->left, s);
        if(node->right) backtrack(node->right, s);
        s.erase(s.begin()+s.size()-1);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root, "");
        return res;
    }
};