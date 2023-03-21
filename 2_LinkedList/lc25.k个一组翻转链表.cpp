#include <iostream>
#include "ListNode.h"
using namespace std;


typedef pair<ListNode*, ListNode*> PNN;
class Solution25 {
public:
    PNN reverseSubList(ListNode* head, ListNode* tail){
        ListNode *pre = tail->next;
        ListNode *p = head;
        while(pre!=tail){
            ListNode *n = p->next;
            p->next = pre;
            pre = p;
            p = n;
        }
        return PNN{tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy;
        ListNode *n = dummy;
        int _k = k;
        while(n!=nullptr){
            _k = k;
            while(_k--){
                n = n->next;
                if(n==nullptr){
                    return dummy->next;
                }
            }
            cout<<n->val<<endl;
            PNN nodes = reverseSubList(pre->next, n);
            pre->next = nodes.first;
            pre = nodes.second;
            n = nodes.second;
        }
        ListNode *res = dummy->next;
        return res;
    }
};