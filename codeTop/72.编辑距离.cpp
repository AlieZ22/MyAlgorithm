#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
dp[i][j], 将word1[0:i]等同word2[0:j]的最少操作次数
对应三种操作：
1, 增删：dp[i][j] = dp[i-1][j]+1 或 dp[i][j-1]+1
2, 修改：dp[i][j] = dp[i-1][j-1] + 1
3, 不操作(word1[i-1] == word2[j-1])：dp[i][j] = dp[i-1][j-1]
取三种操作，最小的总操作数
*/

class Solution_hot72 {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; ++i){
            dp[i][0] = i;
        }
        for(int j=0; j<=m; ++j){
            dp[0][j] = j;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};