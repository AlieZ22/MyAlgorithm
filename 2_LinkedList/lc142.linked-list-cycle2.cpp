#include<iostream>
#include<unordered_set>
#include "ListNode.h"
using namespace std;

/*
* @method: 1，快慢指针；2，哈希表
* @evaluation: O(n)
*/

class Solution142 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        // 找到第一次相遇点
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){    // 有环，得到相交点
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    // 哈希表：碰到循环访问的第一个就是环的起点
    ListNode* detectCycle2(ListNode *head){
        ListNode *curr = head;
        unordered_set<ListNode*> visited;
        while(curr != nullptr){
            if(visited.count(curr)){
                return curr;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};