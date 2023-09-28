#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;

class Solution_hot148 {
public:
    // 构造线性表，进行排序
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> vecl;
        ListNode *node = head;
        while(node != nullptr){
            vecl.push_back(node);
            node = node->next;
        }
        sort(vecl.begin(), vecl.end(), [](const ListNode* l1, const ListNode* l2){return l1->val < l2->val;});
        ListNode dummy;
        ListNode *pre = &dummy;
        for(int i=0; i<vecl.size(); ++i){
            pre->next = vecl[i];
            pre = pre->next;
        }
        pre->next = nullptr;     // 注意：置最后一个Node的next为空
        return dummy.next;
    }
};