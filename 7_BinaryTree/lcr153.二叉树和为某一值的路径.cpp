#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution153_lcr {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }

    // 深搜 + 回溯
    void dfs(TreeNode* root, int sum){
        if(root == nullptr) return ;
        path.push_back(root->val);
        sum -= root->val;

        if(sum == 0 && root->left == nullptr && root->right == nullptr){
            res.push_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);

        path.pop_back();
    }
};