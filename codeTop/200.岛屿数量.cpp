#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 二维网格的深度优先遍历
*/

class Solution_hot200 {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int nr = grid.size();
        int nc = grid[0].size();
        grid[i][j] = 0;       // 置0防止死循环
        if(i-1>=0 && grid[i-1][j] =='1') dfs(grid, i-1, j);
        if(i+1<nr && grid[i+1][j] =='1') dfs(grid, i+1, j);
        if(j-1>=0 && grid[i][j-1] =='1') dfs(grid, i, j-1);
        if(j+1<nc && grid[i][j+1] =='1') dfs(grid, i, j+1);
    }
    // dfs深度优先遍历
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(nr == 0) return 0;
        int nc = grid[0].size();
        int res = 0;
        for(int i=0; i<nr; ++i){
            for(int j=0; j<nc; ++j){
                if(grid[i][j] == '1'){
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};