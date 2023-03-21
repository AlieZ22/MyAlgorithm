#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
* @require: 增加空间的方式比较简单，这里增加难度，要求不使用额外的空间实现
* @method: 【基于反转字符串】先将前n个字符反转，然后将n至末尾字符串反转，最后全字符串反转
* @evaluation: O(n)   空间：O(1)
*/

class Solution_Offer58 {
public:
    void reverseSubStr(string& s, int l, int r){
        while(l < r){
            swap(s[l++], s[r--]);
        }
    }
    string reverseLeftWords(string s, int n) {
        int i=0, j=n-1;
        reverseSubStr(s, i, j);
        reverseSubStr(s,j+1,s.size()-1);
        reverseSubStr(s,0,s.size()-1);
        return s;
    }
};