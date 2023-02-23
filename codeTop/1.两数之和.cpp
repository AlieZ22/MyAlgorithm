#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution_hot1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> res;
        // 一遍循环能够保证不会重复计算同一个
        for(int i=0; i<nums.size(); ++i){
            int x = nums[i];
            if(umap.count(target-x)){
                res.push_back(umap[target-x]);
                res.push_back(i);
                break;
            }
            umap[x] = i;
        }
        return res;
    }
};