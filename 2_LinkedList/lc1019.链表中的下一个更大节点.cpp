#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;

/*
* @method: 将链表序列化为数组，反向遍历结合最大栈求出每个节点的下一个更大节点
* @evaluation: O(n)
*/

class Solution1019 {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        ListNode *node = head;
        // 链表序列化
        while(node!=nullptr){
            nums.push_back(node->val);
            node=node->next;
        }
        // 数组序列反向遍历
        vector<int> res;
        stack<int> st;
        // 有几个动作，在草稿纸上比划一下，确定先后顺序
        for(int i=nums.size()-1; i>=0; --i){
            // 1，用curr清理栈中元素
            int x = nums[i];
            while(!st.empty() && x >= st.top()){
                st.pop();
            }
            // 2，stack判断是否为空，取相应结果
            if(st.empty()){
                res.push_back(0);
            }else{
                res.push_back(st.top());
            }
            // 3，将curr加入栈
            st.push(x);
        }
        // 翻转res
        reverse(res.begin(), res.end());
        return res;
    }
};