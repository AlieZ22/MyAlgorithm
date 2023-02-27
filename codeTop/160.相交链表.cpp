#include <iostream>
#include "ListNode.h"
using namespace std;

/*
* @method: 长链先移动与短链的长度差，然后一起移动看是否重合
*/

class Solution_hot1650 {
public:
    int getLen(ListNode *root){
        int cnt=0;
        while(root!=nullptr){
            ++cnt;
            root = root->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if(lenA > lenB){
            int x = lenA - lenB;
            while(x--){
                headA = headA->next;
            }
        }else{
            int x = lenB - lenA;
            while(x--){
                headB = headB->next;
            }
        }
        while(headA!=nullptr && headB!=nullptr){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};