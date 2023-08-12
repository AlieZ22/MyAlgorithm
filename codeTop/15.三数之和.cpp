#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3000 + 10;
int tmp[N];
class Solution_hot15 {
public:
    void quicksort(vector<int>& vec, int l, int r){
        if(l >= r) return ;
        int i=l-1, j=r+1, x=vec[(l+r)>>1];
        while(i<j){
            do ++i; while(vec[i] < x);
            do --j; while(vec[j] > x);
            if(i<j) swap(vec[i],vec[j]);
        }
        quicksort(vec,l, j);
        quicksort(vec,j+1, r);
    }
    void merge_sort(vector<int>& nums, int l, int r){
        if(l>=r) return;
        
        int mid = (l+r)>>1;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);

        int k=0, i=l, j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i] < nums[j]) tmp[k++]=nums[i++];
            else tmp[k++]=nums[j++];
        }
        while(i<=mid){ tmp[k++]=nums[i++]; }
        while(j<=r) {tmp[k++]=nums[j++]; }
        for(int i=l, j=0; i<=r; ++i, ++j) nums[i]=tmp[j];
    }
    // 注意，不能存在相同答案，但是数组中有重复元素，答案使用重复元素可以
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int i=0, left=0, right=0;
        quicksort(nums,0,nums.size()-1);
        for(; i<nums.size()-2; ++i){
            // 重复i去重
            if(i>0 && nums[i] == nums[i-1]) continue;
            left = i+1;
            right = nums.size()-1;
            while(left < right){
                int x = nums[i]+nums[left]+nums[right];
                if(x > 0){
                    --right;
                }else if(x == 0){
                    vector<int> tmp{nums[i], nums[left], nums[right]};
                    res.push_back(tmp);
                    // 找到答案时，对b,c也要去重（用例 [0,0,0,0]）
                    while(left < right && nums[right] == nums[right-1]) --right;
                    while(left < right && nums[left] == nums[left+1]) ++left;
                    // 双指针同时收缩
                    --right;
                    ++left;
                }else{
                    ++left;
                }
            }
        }
        return res;
    }
};