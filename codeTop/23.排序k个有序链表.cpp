#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

// 最简单的方式：将所有节点存起来，成为一个有序线性表，依次连接
bool cmp(const ListNode* a, const ListNode* b){
    return a->val < b->val;
}

class Solution_hot23 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vec;
        for(int i=0; i<lists.size(); ++i){
            ListNode *curr = lists[i];
            while(curr!=nullptr){
                vec.emplace_back(curr);
                curr=curr->next;
            }
        }
        sort(vec.begin(), vec.end(), cmp);
        ListNode head, *tail = &head;
        for(int i=0; i<vec.size(); ++i){
            tail->next = vec[i];
            tail = tail->next;
        }
        tail->next = nullptr;
        return head.next;
    }
};



// c++17特性 推导引导
/*
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
*/


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
