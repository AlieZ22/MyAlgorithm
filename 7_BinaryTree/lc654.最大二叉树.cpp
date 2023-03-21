#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 思路其实和 中+后序构建二叉树 一样，这个更加简单，分裂一个数组即可
*/

class Solution654 {
public:
    TreeNode* traversal(vector<int>& nums){
        if(nums.size()==0) return nullptr;
        int maxIndex = 0;
        int maxn = nums[0];
        for(int i=0;i<nums.size();++i){
            if(nums[i] > maxn){
                maxn = nums[i];
                maxIndex = i;
            }
        }
        // 创建根节点
        TreeNode *root = new TreeNode(maxn);
        // 分裂nums
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin()+maxIndex+1,nums.end());
        root->left = traversal(leftNums);
        root->right = traversal(rightNums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums);
    }
};