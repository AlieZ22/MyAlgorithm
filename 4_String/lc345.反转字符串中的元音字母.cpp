#include <iostream>
#include <string>
using namespace std;

// 双指针
class Solution345 {
private:
    const char tar_ch[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
public:
    string reverseVowels(string s) {
        int i = -1, j = s.size();
        while(i < j){
            do ++i; while(i<j && !isTarChar(s[i]));
            do --j; while(i<j && !isTarChar(s[j]));
            if(i < j) swap(s[i], s[j]);
        }
        return s;
    }

    bool isTarChar(char c){
        for(const auto& ch: tar_ch){
            if(ch == c){
                return true;
            }
        }
        return false;
    }
};