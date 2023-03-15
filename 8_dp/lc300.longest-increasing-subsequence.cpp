#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution300 {
public:
    // 方法1，动态规划
    // dp[i]：以i结尾的，最长递增子序列的长度
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(),1);
    //     int res = 1;
    //     for(int i=1;i<nums.size();++i){
    //         for(int j=0;j<i;++j){
    //             if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
    //         }
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

    // 方法2，贪心+二分，注意：如果nums.size()为10e5那么 n^2的动态规划就会超时
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(),0);
        tails[0] = nums[0];   // 表示长度为j+1的，最长上升子序列的末尾元素
        int j=0;        // 指向tails当前位置
        for(int i=1;i<nums.size();++i){
            if(nums[i] > tails[j]) tails[++j] = nums[i];
            else{      // 二分来找(0~j)中应该插入的位置
                int l=0, r=j;
                while(l<r){
                    int mid = (l+r)>>1;
                    if(tails[mid] >= nums[i]) r=mid;
                    else l=mid+1;
                }
                tails[l]=nums[i];
            }
        }
        return j+1;
    }
};