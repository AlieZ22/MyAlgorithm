#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

/*
* @method: 用栈模拟逆波兰表达式，第一个出栈数字为b，第二个出栈数字为a，遇到符号就解释执行
* @evaluation: O(n)
*/

class Solution150 {
private:
    stack<int> numStack;
public:
    bool isOps(char c){
        if(c=='+' || c=='-' || c=='*' || c=='/') return true;
        else return false;
    }
    int explainOps(char c, int a, int b){
        int res = 0;
        switch(c){
            case '+': res = a+b; break;
            case '-': res = a-b; break;
            case '*': res = a*b; break;
            case '/': res = a/b; break;
        }
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        int a=0, b=0;
        for(string s: tokens){
            if(s.size()==1 && isOps(s[0])){      // 遇到符号解释执行算数运算,有可能有负数（s[0]为－）
                b = numStack.top();
                numStack.pop();
                a = numStack.top();
                numStack.pop();
                numStack.push(explainOps(s[0], a, b));
            }else{
                numStack.push(atoi(s.c_str()));
            }
        }
        return numStack.top();
    }
};


int main(){
    Solution150 s;
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}