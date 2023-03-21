#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
* @method: 利用unordered_set存储访问过的nums1，然后再遍历nums2，取出公共元素放入res_set，最后转vector
* @evaluation: O(n+m)
*/

class Solution349 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> visited_nums1, res_set;
        for(int i=0; i<nums1.size(); ++i){
            visited_nums1.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); ++i){
            if(visited_nums1.count(nums2[i])){
                res_set.insert(nums2[i]);
            }
        }
        vector<int> res;
        for(auto& item: res_set){
            res.push_back(item);
        }
        return res;
    }
};