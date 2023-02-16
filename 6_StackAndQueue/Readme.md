栈和队列的原理不难，栈是先进后出（LIFO），队列是先进先出（FIFO）

![20210104235346563.png (524×286) (csdnimg.cn)](https://img-blog.csdnimg.cn/20210104235346563.png)

但是对于数据结构的使用很容易停留在表面的应用上，而忽略其底层的原理。栈和队列都是STL（c++标准库）中的数据结构，c++标准库是有多个版本的，要知道我们使用的STL是哪个版本，才能知道对应的栈和队列的实现原理。

那么普遍的STL版本主要有以下三个：

1. HP STL其他版本的C++ STL，一般是以HP STL为蓝本实现出来，HP STL是c++ STL的第一个实现版本，而且开放源码。
2. P.J.Plauger STL由P.J.Plauger参照HP STL实现出来，被Visual C++编译器所采用，不是开源的。
3. SGI STL由Silicon Graphics Computer System公司参照HP STL实现出来，被Linux的C++编译器GCC所采用，SGI STL是开源软件，源码可读性很高。

下面介绍的栈和队列也是SGI STL中的数据结构。

**栈**：先进后出

![20210104235434905.png (556×310) (csdnimg.cn)](https://img-blog.csdnimg.cn/20210104235434905.png)

栈提供push和pop等接口，所有元素必须符合先进后出的规则，所以栈不提供走访功能，也不提供迭代器（iterator）。

栈是以底层容器完成其所有功能，对外提供统一的接口，底层容器是可插拔的（意思是可以控制使用哪种容器来实现栈的功能）。所以STL中，栈往往不被归为容器，而是被归类为container adapter（容器适配器）。

栈的底层实现可以是 vector, deque（SGI STL中的缺省底层结构）, list，主要是数组和链表的底层实现。也可以指定vector为栈的底层实现，例如：

```c++
std::stack<int, std::vector<int> > third;
```



**队列**：先进先出

同样的，队列也不允许遍历行为，不提供迭代器，SGI STL中队列一样是以deque为缺省情况下的底部结构。

STL中队列也不被归类为容器，而归类为container adapter。



思考：为什么栈和队列的底层结构是deque？

参考：[(7条消息) Deque 的理解 STL中stack与queue为什么选择使用deque为底层模板容器_嘴大且吃雯的博客-CSDN博客](https://blog.csdn.net/weixin_66151870/article/details/128684812)

stack为先进后出结构，所有具有push_back和pop_back的容器都可以作为底层默认容器，比如list，vector。

queue为先进先出结构，所有具有push_back和pop_front的容器都可以作为底层默认容器，比如list。

**然而STL库中使用deque作为底层模板容器的原因**：

1、deque所有的头删头插尾删尾插的时间复杂度都为O(1)非常的高效，但是致命缺陷就是进行遍历，然而stack与queue根本不需要对元素进行遍历，使用deque作为底层模板容器简直就是取其精华去其糟粕的典型案例。

2、使用vector作为stack的底层模板虽然可以，但是效率低下（插入删除需要对元素进行大量搬移操作），使用deque相比于list作为queue的底层模板更能提高空间利用率。

