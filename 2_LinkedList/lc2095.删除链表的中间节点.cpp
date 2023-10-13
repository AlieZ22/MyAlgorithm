#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution2095 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        // 获取链表长度
        int n = 0;
        ListNode *curr = head;
        while(curr != nullptr){
            ++n;
            curr = curr->next;
        }
        // 找到待删除节点
        ListNode *pre = &dummy;
        for(int i=0; i<n/2; ++i){
            pre = pre->next;
        }
        ListNode *delNode = pre->next;
        pre->next = pre->next->next;
        delete delNode;
        return dummy.next;
    }
};