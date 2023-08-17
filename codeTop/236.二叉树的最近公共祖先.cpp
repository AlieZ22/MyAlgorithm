#include <iostream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

/*
* @method: 存储二叉树每个节点的父节点（fa[root->val]=nullptr），然后存储p的溯根路径，再q溯根找第一个与p路径重合的节点。
*/

class Solution_hot236 {
public:
    /*
    先dfs遍历，获取所有节点的父节点；
    然后存储p节点（点->根）的路径，自底向上遍历q节点至根；
    在过程中找到第一个公共祖先。
    */
    unordered_map<TreeNode*, TreeNode*> fa;
    unordered_map<TreeNode*, bool> p_path;

    void dfs(TreeNode* root){
        TreeNode *node = root;
        if(node == nullptr) return;
        if(node->left){
            fa[node->left] = node;
            dfs(node->left);
        }
        if(node->right){
            fa[node->right] = node;
            dfs(node->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        fa[root] = nullptr;
        while(p != nullptr){
            p_path[p] = true;   // 注意自己节点和root节点也要在path上
            p = fa[p];
        }
        while(q != nullptr){
            if(p_path.count(q)){
                return q;
            }
            q = fa[q];
        }
        return nullptr;
    }
};