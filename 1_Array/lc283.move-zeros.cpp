#include<iostream>
#include<vector>
using namespace std;

/*
* @method: 先利用快慢指针移除元素0，满足原有相对顺序，并最后在slow之后的元素全部置0
* @evaluation: O(n)
*/

class Solution283 {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        for(; fast < nums.size(); fast++){
            if(nums[fast] != 0){
                nums[slow++] = nums[fast];
            }
        }
        for(; slow < nums.size(); slow++){
            nums[slow] = 0;
        }
    }
};