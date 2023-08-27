#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_hot56 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start = INT_MIN, end = INT_MIN;
        for(auto& it: intervals){
            if(end < it[0]){
                if(end != INT_MIN) res.push_back({start, end});
                start = it[0];
                end = it[1];
            }
            end = max(end, it[1]);
        }
        // 加入最后一个
        res.push_back({start, end});
        return res;
    }
};