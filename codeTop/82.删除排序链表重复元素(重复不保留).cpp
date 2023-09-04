#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot82 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;
        while(curr->next && curr->next->next){
            if(curr->next->val == curr->next->next->val){
                int x = curr->next->val;
                while(curr->next && curr->next->val == x){
                    curr->next = curr->next->next;
                }
            }else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};