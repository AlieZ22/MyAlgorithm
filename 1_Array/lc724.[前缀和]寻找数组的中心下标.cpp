#include <iostream>
#include <vector>
using namespace std;

// 数组中心下标：左侧所有元素的和 等于 右侧所有元素的和
class Solution724 {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        // 构建前缀和
        for(int i=1; i<=n; ++i){
            sum[i] = sum[i-1] + nums[i-1];
        }
        // 寻找中心下标
        int ans = -1;
        for(int i=1; i<=n; ++i){
            if(sum[i-1] == sum[n]-sum[i]){
                ans = i-1;
                break;
            }
        }
        return ans;
    }
};