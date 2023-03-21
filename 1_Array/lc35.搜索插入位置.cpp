#include<iostream>
#include<vector>
using namespace std;

/*
* @method：简单的二分，取最左端点的做法，唯一注意的就是target大于数组最大元素时，返回值要+1
* @evaluation: O(log n)
*/
class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l < r){
            mid = l+r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[l] < target? (l+1): l;
    }
};