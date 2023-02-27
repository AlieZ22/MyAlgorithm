#include <iostream>
#include <vector>
using namespace std;

class Solution_hot88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 先把nums1后移n个单位
        int i=m-1, j=m+n-1;
        while(i>=0){
            nums1[j--] = nums1[i--];
        }
        // 归并排序， i指向nums1, j指向nums2
        i = n;
        j = 0;
        int curr = 0;
        while(i < n+m && j < n){
            if(nums1[i] <= nums2[j]){
                nums1[curr++] = nums1[i++];
            }else{
                nums1[curr++] = nums2[j++];
            }
        }
        // 处理后续
        while(i < n+m){
            nums1[curr++] = nums1[i++];
        }
        while(j < n){
            nums1[curr++] = nums2[j++];
        }
    }
};