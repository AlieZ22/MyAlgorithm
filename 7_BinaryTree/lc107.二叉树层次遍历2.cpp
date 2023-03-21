#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
* @method: 自底而上层次遍历：普通层次遍历，再将这个结果res数组反转即可
*/

class Solution107 {
public:
    template<typename T>
    void reverseVec(vector<T>& vec, int l, int r){
        while(l<r){
            swap(vec[l++], vec[r--]);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 普通层次遍历，然后反转结果数组
        queue<TreeNode*> qt;
        vector<vector<int> > res;
        if(root != nullptr) qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            vector<int> tmp;
            for(int i=0; i<size; ++i){
                TreeNode *node = qt.front();
                qt.pop();
                tmp.push_back(node->val);
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
            res.push_back(tmp);
        }
        reverseVec(res,0,res.size()-1);
        return res;
    }
};