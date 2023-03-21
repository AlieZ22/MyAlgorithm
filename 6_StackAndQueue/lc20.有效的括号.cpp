#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

/*
* @method: 记录字符匹配模式，用stack模拟匹配，注意最后要检查stack是否为空
* @evaluation: O(n)
*/

class Solution20 {
private:
    unordered_map<char,int> match;
public:
    void initMatch(){
        match['('] = -1;
        match['{'] = -2;
        match['['] = -3;
        match[')'] = 1;
        match['}'] = 2;
        match[']'] = 3;
    }
    bool isValid(string s) {
        // 当遇到 match['c'] > 0 表示要弹栈检查
        stack<char> cstack;
        initMatch();
        for(char c: s){
            if(match[c] < 0){
                cstack.push(c);
            }else if(match[c] > 0){
                if(cstack.empty() || match[cstack.top()] + match[c] != 0){
                    return false;
                }
                cstack.pop();
            }else{
                cerr<<"error match!"<<endl;
                return false;
            }
        }
        return cstack.empty()? true: false;     // 应该完成匹配，有剩余元素也不对
    }
};