#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* @method: 分组哈希，使用哈希表记录一边，然后用另一边检测
* @evaluation: O(n^2)
*/

class Solution454 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 先遍历A,B 它们的所有结果存储在umap中
        unordered_map<int, int> umap;
        for(int& a: nums1){
            for(int& b: nums2){
                ++umap[a+b];
            }
        }
        int count = 0;
        for(int& c: nums3){
            for(int& d: nums4){
                if(umap.count(-c-d)){
                    count += umap[0-(c+d)];
                }
            }
        }
        return count;
    }
};