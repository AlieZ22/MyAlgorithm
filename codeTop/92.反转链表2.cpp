#include <iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 找到pre，tail，反转中间部分链表，然后接起来
*/

typedef pair<ListNode*, ListNode*> PNN;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy;
        ListNode *front, *tail, *node = head;
        int cnt = 1;
        while(node != nullptr){
            if(cnt < left){ pre = node; }
            if(cnt == left){ front = node; }
            if(cnt == right){
                tail = node;
                break;
            }
            node = node->next;
            cnt++;
        }
        PNN resNodes = reverseSubList(front, tail);
        pre->next = resNodes.first;
        return dummy->next;
    }

    PNN reverseSubList(ListNode* front, ListNode* tail){
        ListNode *prev = tail->next;
        ListNode *node = front;
        ListNode *next = nullptr;
        while(prev != tail){
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return PNN{tail, front};
    }
};