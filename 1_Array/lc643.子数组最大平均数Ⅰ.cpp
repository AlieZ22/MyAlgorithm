#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution643 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 滑动窗口
        int i=0, j=0;
        int sum = 0;
        for(; j<k; ++j){
            sum += nums[j];
        }
        int maxSum = sum;
        for(; j<nums.size(); ++j){
            sum -= nums[i++];
            sum += nums[j];
            maxSum = max(sum, maxSum);
        }
        return static_cast<double>(maxSum) / k;
    }
};