#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    PNN reverseSubList(ListNode* front, ListNode* tail){
        ListNode *pre = tail->next;
        ListNode *node = front;
        while(pre!=tail){
            ListNode *nex = node->next;
            node->next = pre;
            pre = node;
            node = nex;
        }
        return PNN{tail, front};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1,head);
        ListNode *pre = dummy;
        ListNode *nex = dummy;
        while(nex!=nullptr){
            int _k = k;
            while(_k--){
                nex = nex->next;
                if(nex==nullptr){
                    return dummy->next;
                }
            }
            ListNode *front = pre->next;
            PNN nodes = reverseSubList(front, nex);
            pre->next = nodes.first;
            pre = nodes.second;
            nex = nodes.second;
        }
        return dummy->next;
    }
};

int main(){
    Solution s;
    ListNode *n5 = new ListNode(5,nullptr);
    ListNode *n4 = new ListNode(4,n5);
    ListNode *n3 = new ListNode(3,n4);
    ListNode *n2 = new ListNode(2,n3);
    ListNode *n1 = new ListNode(1,n2);
    ListNode *res = s.reverseKGroup(n1, 2);
    while(res!=nullptr){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}