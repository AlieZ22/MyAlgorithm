#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution_hot560 {
public:
    // 前缀和 + 哈希表优化
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> umap;  // 前缀和，出现次数
        umap[0] = 1;   // 注意这个初始化，即pre本身满足k
        int pre = 0;
        for(const auto& item: nums){
            pre += item;
            if(umap.count(pre - k)){
                ans += umap[pre-k];
            }
            umap[pre]++;
        }
        return ans;
    }
};