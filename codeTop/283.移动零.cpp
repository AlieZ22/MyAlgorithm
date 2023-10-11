#include <iostream>
#include <vector>
using namespace std;

class Solution_hot283 {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        // 消除0
        for(; fast<nums.size(); ++fast){
            if(nums[fast] != 0){
                nums[slow++] = nums[fast];     // 核心行
            }
        }
        // 末尾填补0
        for(; slow<nums.size(); ++slow){
            nums[slow] = 0;
        } 
    }
};