#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 拆分整数，动态规划，dp[i]为数字i拆分后的最大乘积
*/

class Solution343 {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3; i<=n; ++i){
            for(int j=1; j<i-1; ++j){
                dp[i] = max(dp[i],max(j*(i-j), j*dp[i-j]) );
            }
        }
        return dp[n];
    }
};