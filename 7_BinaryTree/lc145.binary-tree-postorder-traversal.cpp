#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 递归法，二叉树后序遍历（左-右-中）
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
};