#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 还是可以用二分查找
*/

class Solution_hot33 {
public:
    // 二分查找
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[mid] < nums[l]){    // 左无序，右肯定有序
                if(target > nums[mid] && target <= nums[r] ){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }else{                      // 左有序，右无序
                if(target >= nums[l] && target < nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return nums[l] == target? l : -1;
    }
};