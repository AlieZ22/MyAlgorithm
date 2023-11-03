#include <iostream>
#include <queue>
using namespace std;

// 类似于跳表的设计
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution117 {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        queue<Node*> qn;
        if(curr!=nullptr) qn.push(curr);
        while(!qn.empty()){
            int size = qn.size();
            vector<Node*> vn;
            for(int i=0; i<size; ++i){
                Node* node = qn.front();
                qn.pop();
                vn.push_back(node);
                if(node->left) qn.push(node->left);
                if(node->right) qn.push(node->right);
            }
            Node* next = nullptr;
            for(int i=size-1; i>=0; --i){
                vn[i]->next = next;
                next = vn[i];
            }
        }
        return root;
    }
};