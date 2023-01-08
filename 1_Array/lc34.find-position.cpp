#include<iostream>
#include<vector>
using namespace std;

/*
* @method: 二分完全体，分别求出左边界和右边界，注意空数组单独处理
* @evaluation: O(log n)
*/

class Solution34 {
public:
    int findLeftPosition(const vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l < r){
            mid = l + r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[l]==target? l: -1;
    }
    int findRightPosition(const vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l < r){
            mid = (l+r+1) >> 1;
            if(nums[mid] <= target){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return nums[l]==target? l: -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>{-1,-1};
        int start = findLeftPosition(nums, target);
        int end = start==-1? -1: findRightPosition(nums, target);
        return vector<int>{start, end};
    }
};