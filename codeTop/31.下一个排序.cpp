#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
思路参考：leetcode解析
1，从后往前查找第一个相邻升序的元素对（i,j），满足A[i] < A[j]，那么[j, end)必然是降序
2，在[j, end)中查找最小且满足A[i] < A[k]的k，从后往前搜就行(end, j]是升序
3，将A[i]与A[k]交换
4，然后将[j, end)逆置，使其升序
5，如果找不到符合1的相邻元素对，那么[begin, end)为降序序列，直接逆序整个数组使其升序
*/

class Solution_hot31 {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1; i>0; --i){
            if(nums[i] > nums[i-1]){
                // 这里先执行4, 再执行3其实也是一样的。A[i-1]和A[k]在[j, end)相对位置一样
                sort(nums.begin()+i, nums.end()); 
                for(int j=i; j<n; ++j){
                    if(nums[j] > nums[i-1]){
                        swap(nums[i-1], nums[j]);
                        return ;
                    }
                }
            }
        }
        sort(nums.begin(), nums.end());
        return ;
    }
};