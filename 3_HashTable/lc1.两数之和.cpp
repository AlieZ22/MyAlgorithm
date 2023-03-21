#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* @method: 用哈希表存储nums，然后遍历一遍寻找 target-nums[i]，防止二重循环
* @evaluation: O(n)
*/

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); ++i){
            umap[nums[i]] = i;
        }
        vector<int> res;
        int another;
        for(int i=0; i < nums.size(); ++i){
            another = target - nums[i];
            if(umap.count(another) && umap[another]!=i){    // 注意同一元素不能重复用
                res.push_back(i);
                res.push_back(umap[another]);
                break;
            }
        }
        return res;
    }
};