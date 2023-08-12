#include<iostream>
#include "ListNode.h"
using namespace std;

typedef pair<ListNode*, ListNode*> PNN;
class Solution_hot25 {
public:
    PNN reverseSubList(ListNode* front, ListNode* tail){
        ListNode *prev = tail->next;   // 注意点1
        ListNode *curr = front;
        ListNode *next = nullptr;
        while(prev!=tail){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return PNN{tail, front};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        ListNode *next = dummy;
        while(next!=nullptr){         // 注意点2
            int _k = k;
            while(_k--){
                next = next->next;
                if(next == nullptr){
                    return dummy->next;
                }
            }
            PNN nodes = reverseSubList(prev->next, next);
            prev->next = nodes.first;
            prev = nodes.second;
            next = nodes.second;
        }
        return dummy->next;
    }
};