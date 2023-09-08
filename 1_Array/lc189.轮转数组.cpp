#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 三次翻转就可以轮转

class Solution189 {
public:
    void swapSubArr(vector<int>& nums, int l, int r){
        while(l < r){
            swap(nums[l++], nums[r--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int idx = n - k;
        swapSubArr(nums, 0, idx-1);
        swapSubArr(nums, idx, n-1);
        swapSubArr(nums, 0, n-1);
    }
};