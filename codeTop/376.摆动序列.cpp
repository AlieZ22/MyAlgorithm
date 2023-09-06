#include <iostream>
#include <vector>
using namespace std;

// 低频题，2023.9.6快手二面
class Solution_cold376 {
public:
    // 贪心：找波峰和波谷的个数
    // 注意，子序列
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2){ return n; }
        int prevDiff = nums[1] - nums[0];
        int ret = prevDiff != 0? 2:1;
        for(int i=2; i<n; ++i){
            int diff = nums[i] - nums[i-1];
            if((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)){
                ret++;
                prevDiff = diff;
            }
        }
        return ret;
    }
};