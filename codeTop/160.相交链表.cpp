#include <iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 长链先移动与短链的长度差，然后一起移动看是否重合
*/

class Solution_hot1650 {
public:
    // 先得到两链表的差，然后长链表先移动一定长度
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if(lenA >= lenB) return getInsection(headA, headB, lenA-lenB);
        else return getInsection(headB, headA, lenB-lenA);
    }

    ListNode* getInsection(ListNode *headA, ListNode *headB, int distance){
        while(distance--){
            headA = headA->next;
        }
        while(headA!=nullptr && headB!=nullptr){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    int getLen(ListNode *node){
        int cnt = 0;
        while(node != nullptr){
            ++cnt;
            node=node->next;
        }
        return cnt;
    }
};