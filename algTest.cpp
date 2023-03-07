#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 10;

class Solution {
public:
    int res ;
    void selectQuickSort(vector<int>& nums, int l, int r, int k){
        if(l > r) return;
        int i=l-1, j=r+1, x=nums[(l+r)>>1], index = (l+r)>>1;
        while(i < j){
            do ++i; while(nums[i] > x);
            do --j; while(nums[j] < x);
            if(i<j){
                swap(nums[i], nums[j]);
                if(i == index){
                    index = j;
                }else if(j == index){
                    index = i;
                }else{}
            }
        }
        if(index == k-1){
            res = nums[index];
            return;
        }else if(index > k-1){
            selectQuickSort(nums,l,j,k);
        }else{
            selectQuickSort(nums,j+1,r,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        selectQuickSort(nums,0,nums.size()-1,k);
        return res;
    }
};


int main()
{
    vector<int> vec{-1,2,0};
    Solution s;
    cout << s.findKthLargest(vec, 1) << endl;
    return 0;
}