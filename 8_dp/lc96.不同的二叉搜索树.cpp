#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 以1..n为root的不同二叉搜索树的数目，先分析子问题，推断出递推公式
* dp[i]: 1..i为root的不同二叉搜索树的数目
*/

class Solution96 {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=i; ++j){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};