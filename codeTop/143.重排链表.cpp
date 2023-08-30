#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

// 线性表来存链表，交替更改next指向
class Solution_hot143 {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode *curr = head;
        while(curr != nullptr){
            vec.push_back(curr);
            curr = curr->next;
        }
        int i=0, j=vec.size()-1;
        while(i < j){
            vec[i++]->next = vec[j];
            if(i < j){
                vec[j--]->next = vec[i];
            }
        }
        vec[i]->next = nullptr;
    }
};