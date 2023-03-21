#include<iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 快慢指针，虚空（dummy）头节点统一删除head的方式
* @evaluation: O(n)
*/

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre, *fast, *slow;
        pre = fast = slow = dummy;
        // fast先移动n步
        for(int i = 0; i < n && fast != nullptr; ++i){
            fast = fast->next;
        }
        // fast, slow一起移动
        while(fast != nullptr){
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        // 删除pre->next
        ListNode *temp = pre->next;
        pre->next = temp->next;
        delete temp;
        return dummy->next;
    }
};