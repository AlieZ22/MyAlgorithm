#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1493 {
public:
    // 思路转化：仅包含一个0的子数组最大长度，但要注意必须要删除一个数
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int cnt_0 = 0;
        int l = 0, r = 0;
        for(; r<nums.size(); ++r){
            if(nums[r] == 0) cnt_0++;
            while(l<r && cnt_0 > 1){
                if(nums[l] == 0) cnt_0--;
                l++;
            }
            // cnt_0 > 0? r-l+1-cnt_0: r-l+1-1; 但是由于cnt_0大于0时肯定为1，所以统一了
            ans = max(ans,r-l);
        }
        return ans;
    }
};