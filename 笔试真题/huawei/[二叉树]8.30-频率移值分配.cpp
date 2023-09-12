#include <bits/stdc++.h>
using namespace std;

// AC: 100%

const int N = 4096 + 10;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int v, TreeNode *l, TreeNode *r):val(v),left(l),right(r){}
};

int n;
int nums[N];
vector<vector<int>> ans;

TreeNode* buildTree(int l, int r, int p){
    if(l > r){
        return nullptr;
    }
    int minV = INT_MAX;
    int maxV = INT_MIN;
    for(int i=l; i<=r; ++i){
        minV = min(minV, nums[i]);
        maxV = max(maxV, nums[i]);
    }
    TreeNode *node = new TreeNode();
    node->val = (minV + maxV) / 2 - p;
    int mid = (l+r)>>1;
    if(l < r){
        node->left = buildTree(l, mid, p + node->val);
        node->right = buildTree(mid + 1, r, p + node->val);
    }
    return node;
}

void printTree(TreeNode *root){
    queue<TreeNode*> qt;
    if(root != nullptr) qt.push(root);
    while(!qt.empty()){
        int size = qt.size();
        vector<int> tmp;
        for(int i=0; i<size; ++i){
            TreeNode *node = qt.front();
            qt.pop();
            tmp.emplace_back(node->val);
            if(node->left) qt.push(node->left);
            if(node->right) qt.push(node->right);
        }
        ans.emplace_back(tmp);
    }
    for(int i=0; i<(int)ans.size(); ++i){
        for(int j=0; j<(int)ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &nums[i]);
    }
    TreeNode *root = buildTree(1, n, 0);
    // 层次遍历
    printTree(root);
    return 0;
}