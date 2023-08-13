#include <bits/stdc++.h>
using namespace std;

class Solution6939 {
public:
    unordered_map<int, vector<int>> umap;
    int maxNumUnit(int x){
        int m_unit = -1;
        while(x != 0){
            m_unit = max(m_unit, x%10);
            x = x/10;
        }
        return m_unit;
    }
    int maxSum(vector<int>& nums) {
        int res = INT_MIN;
        for(int i=0; i<nums.size(); ++i){
            int unit = maxNumUnit(nums[i]);
            umap[unit].push_back(nums[i]);
        }
        for(auto kv: umap){
            vector<int> vec = kv.second;
            if(vec.size() > 1){
                for(int i=0; i<vec.size()-1; ++i){
                    for(int j=i+1; j<vec.size(); ++j){
                        res = max(res, vec[i]+vec[j]);
                    }
                }
            }
        }
        return res==INT_MIN?-1:res;
    }
};