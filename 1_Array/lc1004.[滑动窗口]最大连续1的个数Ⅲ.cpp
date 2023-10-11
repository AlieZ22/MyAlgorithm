#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数
 例如，nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
       输出：6
       因为，[1,1,1,0,0,<1>,1,1,1,1,<1>]
*/

class Solution1004 {
public:
    // 滑动窗口：其实就是一段子数组，含有不超过k个0
    int longestOnes(vector<int>& nums, int k) {
        int cnt_0 = 0;
        int maxLen = 0;
        int i=0, j=0;
        for(; j<nums.size(); ++j){
            if(nums[j]==0) ++cnt_0;
            while(cnt_0 > k){
                if(nums[i] == 0) --cnt_0;
                ++i;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};