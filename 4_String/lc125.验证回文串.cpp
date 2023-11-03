#include <iostream>
#include <string>
using namespace std;

// 算字母和数字，字母全转小写
class Solution125 {
public:
    bool isPalindrome(string s) {
        int i=-1, j=s.size();
        while(i<j){
            do i++; while(i<j && !valid(s[i]));
            do j--; while(i<j && !valid(s[j]));
            cout<<i<<j<<endl;
            cout<<s[i]<<s[j]<<endl;
            if(i<j && s[i] != s[j]) return false;
        }
        return true;
    }

    bool valid(char& c){
        trim(c);
        if(c >= 'a' && c <= 'z'|| c >= '0' && c <= '9'){
            return true;
        }
        return false;
    }

    void trim(char& c){
        if(c >= 'A' && c <= 'Z'){
            c = c - 'A' + 'a';
        }
    }
};