#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution_hot21 {
public:
    // 在pre后面添加node
    void addNode(ListNode *pre, ListNode *node){
        node->next = pre->next;
        pre->next = node;
        // 注意，这里不能改变pre，参数pre与外侧pre不同，只是一个拷贝
    }
    // 为list1添加头节点，每次连在list1上
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0, list1);
        ListNode *pre = dummy;
        ListNode *a = list1, *b = list2;
        while(a!=nullptr && b!=nullptr){
            if(b->val <= a->val){
                ListNode *node = b;
                b = b->next;
                addNode(pre, node);
                pre = pre->next;
            }else{
                pre = a;
                a = a->next;
            }
        }
        // 把b剩余的加到a, a已经空了
        while(b!=nullptr){
            ListNode *node = b;
            b = b->next;
            node->next = nullptr;
            pre->next = node;
            pre = pre->next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};