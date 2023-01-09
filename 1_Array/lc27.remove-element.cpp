#include<iostream>
#include<vector>
using namespace std;

/*
* @method: 快慢指针，一次遍历。快慢一起移动，快值赋慢值，慢满足条件(遇到val)停下
* @evaluation: O(n)
*/

class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        for(;fast < nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};