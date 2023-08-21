#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;


// c++17特性 推导引导
class Solution_hot23{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        lists.erase(remove_if(lists.begin(), lists.end(), [](auto p){return !p;}, lists.end()));
        priority_queue q{ [](auto& a, auto& b){return a->val > b->val;}, lists};
        ListNode head, *tail = &head;
        while(!q.empty()){
            ListNode *f = q.top(); q.pop();
            tail->next = f;
            tail = tail->next;
            if(f->next){
                q.push(f->next);
            }
        }
        return head.next;
    }
};


// c++11 写法
/*

class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

*/