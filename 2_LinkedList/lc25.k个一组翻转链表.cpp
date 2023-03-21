#include <iostream>
#include "ListNode.h"
using namespace std;


typedef pair<ListNode*, ListNode*> PNN;
class Solution25 {
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