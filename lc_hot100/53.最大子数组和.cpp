#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 经典动态规划，dp[i]为以nums[i]结尾的连续子数组最大和
*/

class Solution_hot53 {
public:
    int maxSubArray(vector<int>& nums) {
        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        int res = dp[0];
        for(int i=1; i<nums.size(); ++i){
            if(dp[i-1] > 0){
                dp[i] = dp[i-1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
            res = dp[i] > res? dp[i]:res;
        }
        return res;
    }
};