#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
* @method: 【基于双指针的字符反转】先去除多余的空格，然后全字符串反转，再把每个单词反转
* @evaluation: O(n^2)
*/

class Solution151 {
public:
    const char BLANK = ' ';
    // 双指针法去除空格
    void removeBlank(string& s){
        int fast=0, slow=0;
        // 移除前面的空格
        while(fast < s.size() && s[fast] == BLANK){
            ++fast;
        }
        // 移除多余的空格
        for(; fast < s.size(); ++fast){
            if(fast - 1 >= 0 && s[fast-1] == s[fast] && s[fast] == BLANK){
                continue;
            }else{
                s[slow++] = s[fast];
            }
        }
        // 移除末尾多余的空格
        if(slow-1 > 0 && s[slow-1] == BLANK){
            s.resize(slow-1);
        }else{
            s.resize(slow);
        }
    }

    // 反转一部分字符串
    void reverseSubStr(string& s, int l, int r){
        while(l < r){
            swap(s[l++], s[r--]);
        }
    }

    // 先去除多余的空格，然后全字符串反转，再把每个单词反转
    string reverseWords(string s) {
        removeBlank(s);
        reverseSubStr(s,0,s.size()-1);
        int i=0, j=0;
        for(; j < s.size(); ++j){
            if(s[j] == BLANK){
                reverseSubStr(s, i, j-1);
                i = j+1;
            }
        }
        // j到末尾也要翻转一次
        reverseSubStr(s, i, j-1);
        return s;
    }
};