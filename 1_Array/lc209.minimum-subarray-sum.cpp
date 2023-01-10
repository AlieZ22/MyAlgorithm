#include<iostream>
#include<vector>
using namespace std;

/*
* @method: 滑动窗口，参考双指针模板写法，标准for-while
* @evaluation: O(n)
*/

class Solution209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int start = 0, end = 0, sum = 0;
        for(; end < nums.size(); end++){
            sum += nums[end];
            while(sum >= target){
                minLen = min(minLen, end-start+1);
                sum -= nums[start++];
            }
        }
        return minLen==INT_MAX? 0: minLen;
    }
};