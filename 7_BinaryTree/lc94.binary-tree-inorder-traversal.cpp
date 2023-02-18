#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 递归法，二叉树中序遍历（左-中-右）
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
};