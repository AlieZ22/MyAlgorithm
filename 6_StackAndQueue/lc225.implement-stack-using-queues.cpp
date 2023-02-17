#include <iostream>
#include <queue>
using namespace std;

/*
* @method: 两个队列q1,q2, q1保存所有元素，当需要pop时，移到q2中（q1只留一个元素）弹出最后一个q1，再把q2移回q1. top复用pop
*/

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // 将q1移动到q2，q1只保留一个元素
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        // 弹出“栈顶”
        int tmp = q1.front();
        q1.pop();
        // 将q2移回q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }
    
    int top() {
        // 取到pop元素，加回来
        int x = this->pop();
        this->push(x);
        return x;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */