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
        if(s2.size() == 0){
            pour();
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        if(s2.size() == 0){
            pour();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.size() + s2.size() == 0? true: false;
    }

    // 将s1中元素倾倒至s2
    void pour(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
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