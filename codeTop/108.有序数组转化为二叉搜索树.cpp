#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

// 注意: 要高度平衡的二叉搜索树，那么每次在可选的范围里从中间的数构建节点。
class Solution_hot108 {
public:
    TreeNode* buildNode(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        int mid = (l+r)>>1;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildNode(nums, l, mid-1);
        node->right = buildNode(nums, mid+1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildNode(nums, 0, nums.size()-1);
    }
};