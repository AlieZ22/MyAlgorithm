#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot2 {
public:
    int getLen(ListNode *list){
        int cnt = 0;
        while(list != nullptr){
            ++cnt;
            list = list->next;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLen(l1), len2 = getLen(l2);
        if(len2 > len1) return addTwoNumbers(l2,l1);
        int up = 0, x=0;          // 进位
        ListNode *head = l1, *pre=nullptr;
        // 修改建立在l1上, l1总是最长的
        while(l1 != nullptr && l2 != nullptr){
            x = (l1->val + l2->val + up) % 10;
            up = (l1->val + l2->val + up) / 10;       // 表示进位
            l1->val = x;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            x = (l1->val + up) % 10;
            up = (l1->val + up) / 10;
            l1->val = x;
            pre = l1;
            l1 = l1->next;
        }
        // 处理最后进位
        if(up){
            ListNode *newNode = new ListNode(up);
            pre->next = newNode;
        }
        return head;
    }
};