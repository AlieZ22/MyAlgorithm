#include<iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 快慢指针在两个链表上，fast先移动一个链表长度差
* @evaluation: O(m+n)
*/

class Solution_interview0207 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0, m=0;      // 记录两个链表的长度,A总是为长链,B总是为短链
        ListNode *nodeA = headA, *nodeB = headB;
        while(nodeA != nullptr){
            ++n;
            nodeA = nodeA->next;
        }
        while(nodeB != nullptr){
            ++m;
            nodeB = nodeB->next;
        }
        if(n < m){
            swap(n,m);
            swap(headA, headB);
        }
        // A（长链）先走n-m步
        nodeA = headA;
        nodeB = headB;
        for(int step = n-m; step > 0; --step){
            nodeA = nodeA->next;
        }
        // A, B 一起移动
        while(nodeA != nullptr && nodeB != nullptr){
            if(nodeA == nodeB) return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nullptr;
    }
};