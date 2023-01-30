#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* @method: 还是遍历一遍nums2，记录各个数出现的次数，然后在nums1中找重复的，每重复一次标记数减1
* @evaluation: O(n+m)
*/

class Solution350 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 与普通求交集相比，这个要求记录出现次数
        vector<int> res;
        unordered_map<int, int> cnt_umap;
        for(int& item: nums2){
            ++cnt_umap[item];
        }
        for(int& item: nums1){
            if(cnt_umap[item]>0){
                res.push_back(item);
                --cnt_umap[item];
            }
        }
        return res;
    }
};