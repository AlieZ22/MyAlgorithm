#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot21 {
public:
    // 简单一点考虑，直接类似归并排序
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1, nullptr);
        ListNode *pre = dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                pre->next = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        while(list1 != nullptr){
            pre->next = list1;
            list1 = list1->next;
            pre = pre->next;
        }
        while(list2 != nullptr){
            pre->next = list2;
            list2 = list2->next;
            pre = pre->next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};