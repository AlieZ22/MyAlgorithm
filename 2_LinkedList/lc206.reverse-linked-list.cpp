#include<iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 反转链表，提前记录next节点，每次curr指向pre
* @evaluation: O(n)
*/

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *curr = head;
        while(curr != nullptr){
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};