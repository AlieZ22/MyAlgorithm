#include<iostream>
#include<vector>
using namespace std;

/*
* @method：多种方法做，这里写出了快排和双指针两种
*/

class Solution977 {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;

        int i = l - 1, j = r + 1;
        int x = nums[l+r >> 1];
        while(i < j){
            do i++; while(nums[i] < x);
            do j--; while(nums[j] > x);
            if(i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l, j);
        quick_sort(nums, j+1, r);
    }
    
    vector<int> sortedSquares(vector<int>& nums) {
        // 方法1，先平方，再快排
        // for(int i=0; i<nums.size(); i++){
        //     nums[i] = nums[i]*nums[i];
        // }
        // quick_sort(nums, 0, nums.size()-1);
        // return nums;

        // 方法2，双指针，找到最后一个负数，归并一次
        int i, j, k=0;
        int a, b;
        for(i=0; i<nums.size(); i++){
            if(nums[i] >= 0) break;
        }
        j = i;
        i = i - 1;
        vector<int> res(nums.size());
        while(i>=0 && j<nums.size()){
            a = nums[i] * nums[i];
            b = nums[j] * nums[j];
            if(a <= b){
                res[k++] = a; --i;
            }else{ 
                res[k++] = b; ++j;
            }
        }
        while(i>=0) { res[k++] = nums[i] * nums[i]; --i; }
        while(j<nums.size()) { res[k++] = nums[j] * nums[j]; ++j; }
        return res;
    }
};