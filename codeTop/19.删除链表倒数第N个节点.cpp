#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot19 {
public:
    // 快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *curr = pre;

        // curr先向前移动n个单位
        while(n--){
            curr = curr->next;
        }

        // curr, pre一起移动，至curr->next为空
        while(curr->next != nullptr){
            curr = curr->next;
            pre = pre->next;
        }

        // 删除pre下一个
        ListNode *delNode = pre->next;
        pre->next = pre->next->next;
        delete delNode;
        return dummy.next;
    }
};