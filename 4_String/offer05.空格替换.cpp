#include<iostream>
#include<string>
using namespace std;

/*
* @method: 双指针，计算有多少个空格，然后数组扩容，从后往前替换（减小复杂度）
* @evaluation: O(n)
*/

class Solution_Offer05 {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldLen = s.size();
        for(char& c: s){
            if(c == ' ') ++count;
        }
        s.resize(oldLen + 2*count);
        int i = oldLen-1, j = oldLen + 2*count - 1;
        while(i>=0){
            if(s[i] != ' '){
                s[j--] = s[i--];
            }else{
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                --i;
                j = j-3;
            }
        }
        return s;
    }
};