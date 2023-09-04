#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
思路：
用[前序+中序]或者[后序+中序]可以还原二叉树，
对于二叉搜索树，其节点排序就可以的到中序遍历，所以可以优化，序列化只存前/后序遍历
*/


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        vector<int> arr;
        postOrder(root, arr);
        if(arr.size() == 0) return res;
        for(int i=0; i<arr.size()-1; ++i){
            res.append(to_string(arr[i]) + ",");
        }
        res.append(to_string(arr.back()));
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        vector<int> postOrder = split(data, ',');
        vector<int> inOrder(postOrder);
        sort(inOrder.begin(), inOrder.end());
        return traversal(inOrder, postOrder);
    }

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

    vector<int> split(const string &str, char dec){
        int pos = 0;
        int start = 0;
        vector<int> res;
        while(pos < str.size()){
            while(pos < str.size() && str[pos] == dec){
                ++pos;
            }
            start = pos;
            while(pos < str.size() && str[pos] != dec){
                ++pos;
            }
            if(start < str.size()){
                res.emplace_back(stoi(str.substr(start, pos - start)));
            }
        }
        return res;
    }

    // 左右中：中右左 反序
    void postOrder(TreeNode* root, vector<int>& arr){
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node){
            while(node){
                arr.emplace_back(node->val);
                st.push(node);
                node = node->right;
            }
            node = st.top();
            st.pop();
            node = node->left;
        }
        swapVec(arr);
    }

    void swapVec(vector<int>& arr){
        int i=0, j=arr.size()-1;
        while(i<j){
            swap(arr[i++], arr[j--]);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;