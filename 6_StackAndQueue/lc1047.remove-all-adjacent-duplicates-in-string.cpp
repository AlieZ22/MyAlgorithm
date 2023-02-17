#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
* @method: 简单的栈模拟
*/

class Solution1047 {
public:
    string removeDuplicates(string s) {
        stack<char> cstack;
        for(char c: s){
            if(!cstack.empty() && cstack.top() == c){
                cstack.pop();
            }else{
                cstack.push(c);
            }
        }
        int n = cstack.size();
        s.resize(n);
        for(int i=n-1; i>=0; --i){
            s[i] = cstack.top();
            cstack.pop();
        }
        return s;
    }
};