#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution147 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1,head);
        if(head == nullptr) return head;
        ListNode *ni = head, *nj = head->next, *lastSorted = head;
        ListNode *pre = dummy;
        while(nj != nullptr){
            if(nj->val >= lastSorted->val){
                lastSorted = nj;
                nj = nj->next;
            }else{
                // 找到插入位置
                for(ni=dummy->next,pre=dummy;ni!=nj;ni=ni->next){       // ni=dummy->next，不要设置为head了
                    if(ni->val > nj->val) break;
                    pre = ni;
                }
                // 记录nj，修改后面连接，插入节点
                ListNode *tmp = nj;
                nj = nj->next;
                lastSorted->next = nj;
                pre->next = tmp;
                tmp->next = ni;
            }
        }
        return dummy->next;
    }
};



int main(){
    ListNode *A = new ListNode(3, nullptr);
    ListNode *B = new ListNode(1, A);
    ListNode *C = new ListNode(2, B);
    ListNode *D = new ListNode(4, C);

    Solution147 s;
    s.insertionSortList(D);
    return 0;
}
