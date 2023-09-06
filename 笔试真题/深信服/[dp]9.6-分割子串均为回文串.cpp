#include <bits/stdc++.h>
using namespace std;

// GPT-4，通过100%

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入值为待分割字符串，返回值最少分割次数
     * @param string string字符串 待分割字符串
     * @return int整型
     */
    int min_cut_string(string string) {
        return minCnt(string);
    }

    bool isPalindrome(const string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    int minCnt(string s){
        int n = s.size();
        vector<int> dp(n, INT_MAX);
        
        for(int i=0; i<n; ++i){
            // 奇数长度
            for(int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; ++j){
                dp[i+j] = min(dp[i+j], i-j>0? dp[i-j-1]+1:0);
            }
            // 偶数长度
            for(int j=0; i-j-1>=0 && i+j<n && s[i-j-1]==s[i+j]; ++j){
                dp[i+j] = min(dp[i+j], i-j-1>0?dp[i-j-2]+1:0);
            }
        }

        return dp[n-1];
    }
};