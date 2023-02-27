#include <iostream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

/*
* @method: 存储二叉树每个节点的父节点（fa[root->val]=nullptr），然后存储p的溯根路径，再q溯根找第一个与p路径重合的节点。
*/

class Solution_hot236 {
public:
    unordered_map<int, bool> vis;      // 记录从p到root的路径
    unordered_map<int, TreeNode*> fa;   // 记录所有节点的父节点
    void dfs(TreeNode* node){
        if(node==nullptr) return;
        if(node->left!=nullptr){
            fa[(node->left)->val] = node;
        }
        if(node->right!=nullptr){
            fa[node->right->val] = node;
        }
        dfs(node->left);
        dfs(node->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        fa[root->val] = nullptr;
        // 记录P到root的路径
        while(p!=nullptr){
            vis[p->val] = true;
            p = fa[p->val];
        }
        // 检查q的路径中与vis重合的节点
        while(q!=nullptr){
            if(vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};