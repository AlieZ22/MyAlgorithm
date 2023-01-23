#include<iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 虚拟头节点（注意保持在最前面），成对修改链表元素的指针，作图一步一步分析防止错误
* @evaluation: O(n)
*/

class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;
        while(curr->next!=nullptr && curr->next->next!=nullptr){
            // 先标记两个临时的点位
            ListNode *temp = curr->next;
            ListNode *next = curr->next->next->next;
            // curr ->（n, m）-> next
            curr->next = curr->next->next;       // 步骤1 curr下个指向m
            curr->next->next = temp;             // 步骤2 curr下一个元素(m)的下个指向n
            curr->next->next->next = next;       // 步骤3 curr下下个元素(n)指向next
            // 更新curr，前进两步
            curr = curr->next->next;
        }
        return dummy->next;
    }
};