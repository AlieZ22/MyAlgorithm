#include<iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 基本的指针删除，用前后双指针（或者单个指针判断curr->next）
* @evaluation: O(n)
*/

class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy, *curr = dummy->next;
        while(curr!=nullptr){
            if(curr->val == val){
                pre->next = curr->next;
                delete curr;
                curr = pre->next;
            }else{
                pre = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};