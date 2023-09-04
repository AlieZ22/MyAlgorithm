#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
二维动态规划：
dp[i][j]表示text1[0:i]和text2[0:j]的最长公共子序列长度
dp的i，j从1开始，string text1/2 从下标0开始
1, text1[i-1] == text2[j-1]，那么dp[i][j] = dp[i-1][j-1] + 1;
2，若1不满足，则dp[i][j] = max(dp[i-1][j], dp[i][j-1])
*/

class Solution_hot1143 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=1; i<=n; ++i){
            char c1 = text1[i-1];
            for(int j=1; j<=m; ++j){
                char c2 = text2[j-1];
                if(c1 == c2){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};