## 数组基础理论

数组是存放在**连续内存空间**上的**相同类型**数据的集合。例如下面这个字符数组：

![数组](https://code-thinking.cdn.bcebos.com/pics/算法通关数组.png)

有两点需要注意：

- 数组下标都是从0开始
- 数组内存空间的地址是连续的

因为数组的内存空间是连续的，所以“删除“或者”增添“数组元素时，就要移动数组元素。而且，数组的删除其实是覆盖，数组的元素个数是不变的。

二维数组同理。



## 二分查找

二分查找是一类重要的基础算法，其前提是数组有序。在ch.0中已经介绍过了，这里再沾一遍增强记忆。

二分的本质是处理边界问题，分开的两段分别满足不同的性质（如下图）。很多时候需要单调性，但是也不是必要。

二分可以分为`整数二分`和`浮点数二分`。

![1644222894074.png](https://s2.loli.net/2022/02/16/9gEc1rWk3VtmCRP.png)

`整数二分`的题目有两个模板：

1. 求左边界（≥x 左端点）。

   ```c++
   bool check(int n)
   {
       if(n >= x) return true;
       else return false;
   }
   
   int bsearch(int l, int r)
   {
   	while(l<r)
       {
           int mid = l+r>>1;    // 若l+r溢出，则需要(r-l)/2+l
           if(check(q[mid])) r=mid;
           else l=mid+1;
       }
       return l;
   }
   ```

2. 求右边界（≤x 右端点）。

   ```c++
   bool check(int n)
   {
       if(n <= x) return true;
       else return false;
   }
   
   int bsearch(int l, int r)
   {
       while(l<r)
       {
   		int mid = l+r+1>>1;
           if(check(q[mid])) l=mid;
           else r=mid-1;
       }
       return l;
   }
   ```

`浮点数二分`由于不用考虑边界问题，就比较简单。但是要注意循环条件，一般以精度（需要保留几位，就设置为10e (x-2)）或者直接循环100次作为循环条件。以求平方根为例（判断条件不用写等于）：

```c++
double l=0, r=x;
while(r-l > 1e-8)
{
    double mid = (l+r)/2;         // 浮点数没有位移运算
    if(mid*mid > x) r=mid;
    else l=mid;
}
printf("%lf\n",l);
```

注意的是，二分的模板一定有解，但是解需要根据题意判断题目是否有解。

相关例题：

- 35.搜索插入位置
- 34.在排序数组中查找元素的第一个和最后一个位置
- 69.x 的平方根
- 367.有效的完全平方数



## 移除元素

这涉及到对数组的理解，并引入一种“原地法”来修改数组元素。

首先要明白，数组元素在内存地址中连续，而且不能单独删除数组中的某个元素，只能对其进行覆盖。

例如，给定数组nums = [0,1,2,2,3,0,4,2], val = 2，要求原地删除数组中值为val的元素。其中一种暴力的做法就是双重循环，外层循环寻找值为val的元素，然后内层循环做后续元素的移动操作，不过这样的复杂度比较高。

一种更好的方式是利用双指针（快慢指针），过程如下（直接拿了现成的演示图）：

![27.移除元素-双指针法](https://code-thinking.cdn.bcebos.com/gifs/27.移除元素-双指针法.gif)

fast指针每次移动一个单位，slow指针遇到值为val时停下，当fast下次指向值不为val的元素时，赋给slow指向的位置，并移动slow。整个过程并没有改变元素的相对位置，这样可以用一个for循环的成本，解决两个for循环的工作。

需要考虑清楚的就是，指针什么情况走，什么情况停。这样的话，这类移除元素的题目就不在话下了。

相关例题：

- 27.移除元素
- 26.删除排序数组中的重复项
- 283.移动零
- 844.比较含退格的字符串
- 977.有序数组的平方



## 滑动窗口

考虑这样类型的题目：

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

【示例】输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

这个题目最直接的解法也是暴力搜索，两个for循环遍历所有可能的子序列，取满足条件最短的那个，不过复杂度为O(n^2)，效率太低了。

这里开始引入数组操作中的一个重要方法：**滑动窗口**

所谓滑动窗口，就是 **不断调整子序列的起始位置和终止位置**，从而得出想要的结果。具体地，用两个指针分别指向窗口起始位置和终止位置。其实滑动窗口也是一种特殊的双指针。在实现滑动窗口时，主要是要明确以下三点：

- 窗口内是什么？
- 如何移动窗口起始位置？
- 如何移动窗口终止位置？

针对这道题而言，窗口就是“满足和≥s的长度最小的连续子数组”，而移动窗口起始位置导致窗口缩小，移动终止位置导致窗口增大，应该在窗口未满足条件时，扩大窗口；而在窗口满足条件时，缩小窗口。这样通过滑动窗口能够把复杂度从O(n^2)降到O(n)。

相关例题：

- 209.长度最小的子数组
- 904.水果成篮
- 76.最小覆盖子串



