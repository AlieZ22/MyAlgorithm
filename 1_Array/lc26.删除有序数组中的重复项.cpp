#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* @method: 快慢指针，用哈希表记录重复值。快慢一起移动，快值赋慢值，慢满足条件(遇到重复值)停下
* @evaluation: O(n)
*/

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, bool> umap;
        int fast = 0, slow = 0;
        for(; fast < nums.size(); fast++){
            if(!umap[nums[fast]]){
                nums[slow++] = nums[fast];
                umap[nums[fast]] = true;
            }
        }
        return slow;
    }
};