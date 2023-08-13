#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

class Solution6914 {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<ListNode*> vec;
        ListNode *curr = head;
        while(curr != nullptr){
            vec.push_back(curr);
            curr = curr->next;
        }
        int jin = 0;
        for(int i=vec.size()-1; i>=0; --i){
            int num = vec[i]->val;
            num = jin + num * 2;
            jin = num / 10;
            num = num % 10;
            vec[i]->val = num;
        }
        if(jin != 0){
            ListNode *new_head = new ListNode(jin, head);
            head = new_head;
        }
        return head;
    }
};