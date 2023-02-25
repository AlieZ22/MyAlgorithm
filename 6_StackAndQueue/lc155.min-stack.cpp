#include <iostream>
#include <stack>
using namespace std;

/*
* @method: 用两个栈实现，一个栈保存数据，一个栈保存当前最小元素
*/

class MinStack {
private:
    stack<int> dataStack;
    stack<int> sortedStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        dataStack.push(val);
        if(sortedStack.empty()){
            sortedStack.push(val);
        }else{
            int min = val < sortedStack.top()? val: sortedStack.top();
            sortedStack.push(min);
        }
    }
    
    void pop() {
        dataStack.pop();
        sortedStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return sortedStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */