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

例题包括：

- 35.搜索插入位置
- 34.在排序数组中查找元素的第一个和最后一个位置
- 69.x 的平方根
- 367.有效的完全平方数