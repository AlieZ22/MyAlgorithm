/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution_hot199 {
public:
    // 层次遍历，每次取每层最右边的值
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        TreeNode *node = root;
        queue<TreeNode*> qt;
        if(node != nullptr) qt.push(node);
        while(!qt.empty()){
            int size = qt.size();
            for(int i=0; i<size; ++i){
                node = qt.front();
                qt.pop();
                if(i == size-1){
                    res.push_back(node->val);
                }
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
        }
        return res;
    }
};