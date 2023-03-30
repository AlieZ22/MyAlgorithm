#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // 中心扩散思想
    string longestPalindrome(string s) {
        int maxLen = 1;
        int resIdx = 0;   // idx
        int n = s.size();
        for(int k=0;k<n;++k){     // 遍历每一个字符，从中间向两边扩散
            int i=k-1, j=k+1;
            int len =1;
            // 先同样字符扩散
            while(i>=0 && s[i] == s[k]){
                ++len;
                --i;
            }
            while(j<n && s[j] == s[k]){
                ++len;
                ++j;
            }
            // 再不同字符扩散
            while(i>=0 && j<n && s[i] == s[j]){
                len+=2;
                ++j;
                --i;
            }
            // 结算
            if(maxLen < j-i-1){
                maxLen = j-i-1;
                resIdx = i+1;
            }
        }
        return s.substr(resIdx, maxLen);
    }
};