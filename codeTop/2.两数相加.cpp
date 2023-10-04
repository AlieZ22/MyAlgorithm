#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot2 {
public:
    // 直接用归并的方式做
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *pre = &dummy;
        int x, up=0;
        while(l1 != nullptr && l2 != nullptr){
            x = (up + l1->val + l2->val) % 10;
            up = (up + l1->val + l2->val) / 10;
            ListNode *node = new ListNode(x);
            pre->next = node;
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            x = (up + l1->val) % 10;
            up = (up + l1->val) / 10;
            ListNode *node = new ListNode(x);
            pre->next = node;
            pre = pre->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            x = (up + l2->val) % 10;
            up = (up + l2->val) / 10;
            ListNode *node = new ListNode(x);
            pre->next = node;
            pre = pre->next;
            l2 = l2->next;
        }
        if(up != 0){
            ListNode *node = new ListNode(up);
            pre->next = node;
        }
        return dummy.next;
    }
};