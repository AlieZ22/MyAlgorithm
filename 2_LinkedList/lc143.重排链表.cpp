#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

class Solution143{
public:
    // 将链表改存为线性表
    void reorderList(ListNode *head){
        vector<ListNode*> vec;
        ListNode *node = head;
        while(node!=nullptr){
            vec.push_back(node);
            node=node->next;
        }
        int i=0, j=vec.size()-1;
        while(i<j){
            vec[i]->next = vec[j];
            ++i;
            if(i==j){
                break;
            }
            vec[j]->next = vec[i];
            --j;
        }
        vec[i]->next = nullptr;
    }
};