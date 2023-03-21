#include <iostream>
#include <stack>
using namespace std;

/*
* @method: 一个栈s1用于入队，另一个栈s2用于出队，但是注意只有当s2为空时才应该转移s1内的元素，否则不能保证s2的top为队头
*/

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int x = this->peek();
        s2.pop();
        return x;
    }
    
    int peek() {
        // 是否需要移动元素
        moveElement();
        // 取s2的top
        return s2.empty()?-1:s2.top();
    }
    
    bool empty() {
        return s1.size() + s2.size() > 0? false: true;
    }

    void moveElement(){
        // 注意：只有当s2空的时候，转移s1的元素至s2，让s2的top为队列头
        if(s2.empty()){
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */