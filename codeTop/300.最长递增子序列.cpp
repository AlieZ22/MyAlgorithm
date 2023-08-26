#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 动态规划：dp[i]表示以i结尾子数组的最长递增子序列的长度
// dp[i] = max(dp[j]+1, dp[i]), j<i && nums[j]<nums[i]

class Solution_hot300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; ++i){
            int j = i-1;
            while(j>=0){
                if(nums[j] < nums[i]) dp[i] = max(dp[j]+1, dp[i]);
                j--;
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};