#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1732 {
public:
    // 简单的前缀和
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> sum(n + 1);
        sum[0] = 0;
        int res = sum[0];
        for(int i=1; i<=n; ++i){
            sum[i] = sum[i-1] + gain[i-1];
            res = max(res, sum[i]);
        }
        return res;
    }
};