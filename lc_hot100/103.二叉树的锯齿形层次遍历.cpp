#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
* @method: 层次遍历，如果需要改变遍历方向，那就原方向结果数组反转一下就行了
*/

class Solution_hot103 {
public:
    template<typename T>
    void reverseVec(vector<T>& vec){
        int i=0, j=vec.size()-1;
        while(i<j){
            swap(vec[i++],vec[j--]);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<vector<int> > res;
        if(root != nullptr) qt.push(root);
        bool dirSign = 0;       // 0：直接放，1：反转tmp数组
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
            if(dirSign){
                reverseVec(tmp);
            }
            dirSign = !dirSign;
            res.push_back(tmp);
        }
        return res;
    }
};