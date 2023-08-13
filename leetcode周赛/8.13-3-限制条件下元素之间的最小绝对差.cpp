#include <bits/stdc++.h>
using namespace std;

class Solution7022 {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        int res = INT_MAX;
        set<int> s = {INT_MIN/2, INT_MAX};    // 有序集合，哨兵
        for(int i=x; i<n; i++){
            s.insert(nums[i-x]);
            int y = nums[i];
            auto it = s.lower_bound(y);
            cout<<*it<<endl;
            res = min(res, min(*it - y, y - *--it));
        }
        return res;
    }
};