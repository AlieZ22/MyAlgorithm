#include <iostream>
#include <vector>
using namespace std;

/*
* @method: dfs会超时，用dp优化（只要知道总路径数就行了，不需要知道具体路径）
*/

class Solution62 {
public:
    // dfs会超时的，需要用dp来做
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i=0, j=0;
        for(i=0;i<m;++i){
            dp[i][0] = 1;
        }
        for(j=0;j<n;++j){
            dp[0][j] = 1;
        }
        for(i=1;i<m;++i){
            for(j=1;j<n;++j){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution62 s;
    cout<< s.uniquePaths(3, 6) <<endl;
    return 0;
}