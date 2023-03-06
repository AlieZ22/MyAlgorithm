#include <iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 找到pre，tail，反转中间部分链表，然后接起来
*/

class Solution_hot92 {
public:
    // 反转链表
    ListNode* reverseList(ListNode* head){
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while(curr!=nullptr){
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 记录 pre, tail，反转中间的链
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        ListNode *curr = head;
        ListNode *headNode = nullptr, *tailNode = nullptr;
        int cnt = 0;
        while(curr!=nullptr && cnt <= right){
            ++cnt;
            if(cnt == left){
                headNode = pre;
            }
            if(cnt == right){
                tailNode = curr->next;
                curr->next = nullptr;
                break;
            }
            pre = curr;
            curr = curr->next;
        }
        ListNode *subNode = reverseList(headNode->next);
        headNode->next = subNode;
        while(subNode->next!=nullptr){
            subNode = subNode->next;
        }
        subNode->next = tailNode;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};