#include<iostream>
#include<string>
using namespace std;

/*
* @method: 也可以当作移除元素，快慢指针，快遇到#就把slow退一个，正常情况直接快值赋慢值
*/

class Solution844 {
public:
    const char BACK = '#';

    string trimStr(string& str){
        int fast = 0, slow = 0;
        for(; fast < str.size(); fast++){
            if(str[fast] == BACK && slow > 0){   // 注意处理#空删的情况，即slow不能小于0
                --slow;
            }
            if(str[fast] != BACK){
                str[slow++] = str[fast];
            }
        }
        return str.substr(0, slow);
    }

    bool backspaceCompare(string s, string t) {
        return trimStr(s) == trimStr(t);
    }
};