#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> sp;    // 温度，temperatures中的下标
        sp.push({INT_MAX, 0});
        for(int i=0; i<n; ++i){
            while(temperatures[i] > sp.top().first){
                int s_idx = sp.top().second;
                ans[s_idx] = i - s_idx;
                sp.pop();
            }
            sp.push({temperatures[i], i});
        }
        return ans;
    }
};