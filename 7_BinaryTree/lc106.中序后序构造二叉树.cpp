#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
* @method: 从中序，后序构建二叉树，每次其实就是构建一个根节点，然后dfs就行了
*/

class Solution106 {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size()==0) return nullptr;
        int n = postorder.size();
        // 找到根节点
        TreeNode *root = new TreeNode(postorder[n-1]);
        // 划分区间：左中，右中，左后，右后
        int pos = 0;
        for(int i=0;i<n;++i){
            if(inorder[i] == root->val){
                pos = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + pos);
        vector<int> rightInorder(inorder.begin()+pos+1, inorder.end());
        int leftLen = leftInorder.size();
        int rightLen = rightInorder.size();
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftLen);
        vector<int> rightPostorder(postorder.begin()+leftLen, postorder.begin()+leftLen+rightLen);
        root->left = traversal(leftInorder,leftPostorder);
        root->right = traversal(rightInorder,rightPostorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder,postorder);
    }
};