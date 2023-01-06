### 快速排序

O(nlogn)  

1. 确定分界点x: q[l], q[(l+r)/2], q[r], 或者随机
2. 调整区间【难点】：左半全为≤x，右半全为≥x
3. 递归处理左右两端 

**模板**：

```c++
void quick_sort(int q[], int l, int r)
{
    if(l>=r) return;
    
    int i = l-1, j = r+1, x = q[l+r >> 1];
    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
```

注意：

1. `i`和`j`初始要取两侧之外的值，这是为了统一(i++)和(j--)，每次交换之后都需要将i,j向内侧移动。
2. x最好取中间值，不然后面分治的quick_sort容易出现死循环。



### 归并排序

O(nlogn)

1. 确定分界点: mid=(l+r)/2
2. 递归排序： left与right区间
3. 归并：将两个有序数组合并为一个

**模板**：

```c++
int tmp[N];
void merge_sort(int q[], int l, int r)
{
	if(l>=r) return;
    
    int mid = l+r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid+1, r);
    
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    
    for(i=l,j=0; i<=r; i++,j++) q[i]=tmp[j];
}
```



### 二分

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

`浮点数二分`由于不用考虑边界问题，就比较简单。但是要注意循环条件，一般以精度（需要保留几位，就设置为10e (x-2)）或者直接循环100次作为循环条件。以求平方根为例：

```c++
double l=0, r=x;
while(r-l > 1e-8)
{
    double mid = (l+r)/2;         // 浮点数没有位移运算
    if(mid*mid >= x) r=mid;
    else l=mid;
}
printf("%lf\n",l);
```

注意的是，二分的模板一定有解，但是解需要根据题意判断题目是否有解。



### 高精度计算

优先级略低，暂记模板。

**高精度加法**

```c++
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++ )
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}
```

**高精度减法**

```c++
// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```

**高精度乘低精度**

```c++
// C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}
```

**高精度除低精度**

```c++
// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```



### 前缀和

**一维前缀和**

> 公式一：S[i] = a[1] + a[2] + ... + a[i]
>
> 公式二：a[l] + a[l+1] + .. + a[r] = S[r] - S[l-1]
>
> 初始化公式：S[i] = S[i-1] + a[i]， S[0] = 0

前缀和就是数组前多少元素之和，其作用就是`快速求出数组中某段区间的和`。

使用的**要求**：

1. S[0] = 0 （目的是为了统一公式二）
2. 数组的坐标从1开始。

**二维前缀和**

其实就是一个容斥原理，小学数学orz。

> 公式一：S\[i, j\]为第i行j列格子左上部分所有元素的和
>
> 公式二：以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
>
> 初始化公式：S\[i, j\] = S\[i-1, j\] + S\[i, j-1\] - S\[i-1, j-1\] + a[i, j]，S[0, 0] = 0

注意：下标也要从1开始。在实际的题目中，若下标以0开始，则需要适当调整。



### 差分

差分就是`前缀和的逆运算`。

**一维差分**

给定A数组，a1, a2, ... , an ，需要进行很多个操作，`每个操作都是为[l, r]区间内的a元素+c`。这样每个操作都需要`O(r-l)`的时间，而利用差分，可以将这个操作的时间降为`O(1)`。具体做法如下：

1. 构造差分数组B，b[i] = a[i] - a[i-1]，a,b 数组都从1开始，a[0]=0。（构造时也可以将a[i] 理解为 insert(i,i,a[i]) ,这样的话，其实就不需要考虑如何构造了）

2. 对于操作[l, r] + c，对应到差分数组为：

   ```c++
   void insert(int l, int r, int c)
   {
   	b[l] += c;
       b[r+1] -= c;
   }
   ```

3. 操作完成后，利用前缀和公式还原A数组。

**二维差分**

由A二维数组得到差分二维数组B，b[i, j] += c 相当于i, j右下角的所有a元素+c。

给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：

```c++
void insert(int x1, int y1, int x2, int y2)
{
    b[x1, y1] += c;
    b[x2+1, y1] -= c;
    b[x1, y2+1] -= c;
    b[x2+1, y2+1] += c;
}
```

注意：数组要从1开始！



### 双指针

一般有两种类型：

1. 双指针分别指向两个序列
2. 双指针共同指向一个序列

双指针的用途十分广泛，而其核心思想是从朴素的双重循环中将时间复杂度优化到O(n)。具体地，针对双指针题目可以先从朴素方法着手，然后挖掘其中两个指针的单调关系，根据这样的单调关系套模板来进行优化。模板如下：

```c++
for(int i=0,j=0; i<n; i++)
{
    
    while(j<i && check(i,j))   // check是判断此时不满足某些性质
    {
        j++;
    }
    // 具体逻辑
    
}
```



#### 快慢指针

定义slow，fast指针，slow用于查找需要操作的位置。

**移除元素**专题，原地移除元素并保持数组中其余数的相对位置不变。（leetcode 26, 283, 844），还有977，利用正负数，将有序拆成了两段，利用双指针进行两个有序数组的归并。

#### 滑动窗口

不断调节子序列的起始位置和终止位置，从而得到想要的结果。想清楚这三个点问题就很容易解决了：

- 窗口内是什么？
- 如何移动窗口的起始位置？
- 如何移动窗口的结束位置？

leetcode 209，904，76



### 位运算

- 求整数n的二进制表示中，第k位（从个位算，个位是第0位）是几？

  ```c++
  // 先将第k位右移至最后一位，在判断最后一位是多少
  n >> k & 1
  ```

- lowbit(x): 返回x二进制表示中最后一个1的位置

  ```
  x & -x == x & (~x+1)
  ```

- 消除整数n二进制中最后一个1

  ```
  n & (n-1)
  ```



### 离散化

离散化的本质，是映射。将间隔很大的点，映射到相邻的数组元素中，以减少对空间的需求。

![1644478591794.png](https://s2.loli.net/2022/02/16/Yfk5F327a9JoAQb.png)

离散化实现的模板为：

```c++
vector<int> alls;      // 存储所有待离散化的值

// 去重
sort(alls.begin(), alls.end());
alls.erase(unique(alls), alls.end());

vector<int>::iterator unique(vector<int> &a)    // 一个双指针算法
{
    int j=0;
    for(int i=0;i<alls.size();i++)
        if(!i || a[i]!=a[i-1])
            a[j++] = a[i];
    return a.begin()+j;
}

int find(int x)    // 得到离散化后的坐标
{
    int l=0, r=alls.size()-1;
    while(l<r)
    {
        int mid = (r-l)/2 + l;
        if(alls[mid] >= x) r=mid;
        else l=mid+1;
    }
    return l+1;
}
```



### 区间合并

目的是将存在交集的区间进行合并。主要利用贪心的思维，先按照区间起始位置排序，然后再根据start, end位置判断加入结果集还是合并区间。具体模板如下：

```c++
// 将所有存在交集的区间合并
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}
```

