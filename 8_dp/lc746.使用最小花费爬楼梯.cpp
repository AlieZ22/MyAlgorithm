#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* @method: dp
* dp[i]: 爬到i阶楼梯的最小花费
* 递推公式：dp[i] = min(dp[i-1],dp[i-2])+cost[i], i>=2
* 初始化：dp[0]=cost[0],dp[1]=cost[1]
*/

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int *dp = new int[n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;++i){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        int res = min(dp[n-1],dp[n-2]);
        delete [] dp;
        return res;
    }
};