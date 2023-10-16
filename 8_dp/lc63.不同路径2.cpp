#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 这个是有障碍物的，障碍物的地方肯定不可达（dp为0），然后注意初始化的方式（遇到障碍就停了，因为是路径！）
*/

class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        // 初始化dp
        for(int i=0; i<m && !obstacleGrid[i][0]; ++i) dp[i][0]=1;
        for(int j=0; j<n && !obstacleGrid[0][j]; ++j) dp[0][j]=1;
        // 递推
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};