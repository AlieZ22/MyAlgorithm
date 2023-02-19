#include <iostream>
#include <queue>
#include <vector>
#include "Node.h"
using namespace std;

/*
* @method: N叉树的层次遍历，同二叉树层次遍历，只是孩子多了点
*/

class Solution429 {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> qn;
        vector<vector<int> > res;
        if(root != nullptr) qn.push(root);
        while(!qn.empty()){
            int size = qn.size();
            vector<int> tmp;
            for(int i=0; i<size; ++i){
                Node *n = qn.front();
                qn.pop();
                tmp.push_back(n->val);
                for(auto& item: n->children){
                    qn.push(item);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};