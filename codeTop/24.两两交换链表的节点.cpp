#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode *pre = &dummy;
        while(pre->next && pre->next->next){
            ListNode *slow = pre->next;
            ListNode *fast = pre->next->next;
            ListNode *next = fast->next;

            // 交换
            pre->next = fast;
            fast->next = slow;
            slow->next = next;

            // 迭代
            pre = slow;
        }
        return dummy.next;
    }
};