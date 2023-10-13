#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution872 {
public:
    // 中序遍历，拿到叶子节点序列，path保存叶值序列
    void dfs(TreeNode* root, vector<int>& path){
        if(root == nullptr) return ;

        if(!root->left && !root->right){
            path.push_back(root->val);
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> path1;
        vector<int> path2;
        dfs(root1, path1);
        dfs(root2, path2);
        // 判断path1,2是否一致
        if(path1.size() == path2.size()){
            for(int i=0; i<path1.size(); ++i){
                if(path1[i] != path2[i]){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
};