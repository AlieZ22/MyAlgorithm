#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution244 {
public:
    // 转成线性表，然后判断
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode *node = head;
        while(node != nullptr){
            vec.push_back(node->val);
            node = node->next;
        }
        // 判断vec的是否回文
        int l=0, r=vec.size()-1;
        while(l<r){
            if(vec[l++] != vec[r--]){
                return false;
            }
        }
        return true;
    }
};