## 链表的基础概念

链表通过指针将每个节点串联起来，每个节点由数据域和指针域构成。

链表可以分为：单链表，双链表（两个指针域，向前向后），循环链表等。

链表在内存中是分散的，而不像数组在内存中连续。

### **链表定义**

```c++
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};
```

### **链表操作 - 删除**

![链表删除节点](https://img-blog.csdnimg.cn/20200806195114541.png)

如图所示，删除节点D，只需要更改前一个节点C的next，**然后将D释放**即可（在java或python中不用自己释放，有GC机制）。

有一个特殊情况是删除头节点，针对这个情况可以将head指针后移，以作特殊处理；还可以创建一个**虚拟头节点**（dummy node）来统一删除操作。见leetcode 203. 移除链表元素。

### **链表操作 - 添加**

![20200806195134331.png (1122×420) (csdnimg.cn)](https://img-blog.csdnimg.cn/20200806195134331.png)

如图所示，添加节点F，需要先将F的next指向D，然后再更改C的next指向F，时间代价为O(1). 但是在找到添加节点位置需要O(1)的查找时间。

练习链表的各种操作，可以去做leetcode 707，很基础但是可以巩固其中的细节。



### 双指针解链表相关类型问题

- 反转链表（206，24）：pre，curr指针，每次将curr->next指向pre，将pre赋值为curr。24题注意next节点要考虑是否为空，这点可以放在循环里面来写。

  ```c++
  // leetcode 24
  ListNode* swapPairs(ListNode* head) {
      ListNode *dummy = new ListNode(0,head);
      ListNode *pre = dummy;
      ListNode *curr = head;
      ListNode *ne;
      while(curr != nullptr && curr->next != nullptr){
          ne = curr->next;
  
          pre->next = ne;
          curr->next = ne->next;
          ne->next = curr;
  
          pre = curr;
          curr = curr->next;
      }
      return dummy->next;
  }
  ```

- 删除链表倒数第N个节点（leetcode 19）: 没什么说的，快慢指针。

- 链表相交：相比与找倒数第N个点更难一些，关键就难在找到**哪里是快慢指针初始的位置**。可以遍历链表得到长度差，将长的链表的头节点先往前移动这个长度差，再两个链表指针一起走，判断指针值是否相等。

  ```c++
  // leetcode 面试题02.07 链表相交
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      // 得到A,B链表的长度
      int len_A = 0, len_B = 0;
      ListNode *curr_A = headA;
      ListNode *curr_B = headB;
      while(curr_A != nullptr){
          curr_A = curr_A->next;
          ++len_A;
      }
      while(curr_B != nullptr){
          curr_B = curr_B->next;
          ++len_B;
      }
      // 将A置为更长的链表
      if(len_B > len_A){
          swap(len_B, len_A);
          swap(headA, headB);
      }
      curr_A = headA;
      curr_B = headB;
      // 让A先走步差
      for(int i=0; i<len_A - len_B; ++i){
          curr_A = curr_A->next;
      }
      // 再一起走，判断是否有相同节点
      while(curr_A != nullptr && curr_B != nullptr){
          if(curr_A == curr_B) return curr_A;
          curr_A = curr_A->next;
          curr_B = curr_B->next;
      }
      return nullptr;
  }
  ```

- 环形链表：fast一次走两步，slow一次走一步。可以根据数学公式推导，在第一相遇的地方确定new fast，然后将new slow置于起点，两者每次走一步，再次相交的地方就是环起点。

  ```c++
  // leetcode 142 环形链表
  ListNode *detectCycle(ListNode *head) {
      ListNode *slow = head;
      ListNode *fast = head;
      do{
          if(fast == nullptr || fast->next == nullptr) return nullptr;
          fast = fast->next->next;
          slow = slow->next;
      }while(fast!=slow);
      slow = head;
      while(fast != nullptr){
          if(fast == slow){
              break;
          }
          fast = fast->next;
          slow = slow->next;
      }
      return fast;
  }
  ```

  



## 小结

使用快慢指针可以考虑的几个维度：

1. 快慢指针的**初始位置**如何确定？
2. 快慢指针的**速率**：是齐头并进，还是不同速率？

链表的主要类型差不多是这些，后续有其他类型会进行补充。



## 虚拟头节点

链表的一大问题就是**操作**当前节点必须要找到前一个节点才行，这就造成了头节点的尴尬，因为头节点之前没有任何节点，头节点的操作就得单独进行处理。

在链表中，使用**虚拟头节点（dummy）**有时候会方便很多。<u>尤其是每次对应头节点的情况都要单独处理时</u>。

