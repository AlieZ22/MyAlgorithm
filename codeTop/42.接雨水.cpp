#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_hot42 {
public:
    // 对于列（每根柱子）能接的水 = min(两边最高柱子高度)-当前柱子高度
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        // dp：第i个柱子，左右最高的柱子高度
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);

        for(int i=1; i<n-1; ++i){
            max_left[i] = max(max_left[i-1], height[i-1]);
        }
        for(int i=n-2; i>0; --i){
            max_right[i] = max(max_right[i+1], height[i+1]);
        }
        for(int i=1; i<n-1; ++i){
            int min_level = min(max_left[i], max_right[i]);
            if(min_level > height[i]){
                ans += (min_level - height[i]);
            }
        }
        return ans;
    }
};