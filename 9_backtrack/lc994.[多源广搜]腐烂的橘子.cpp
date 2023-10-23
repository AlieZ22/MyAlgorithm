#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 算法未通过（stack-overflow），这里只是记录一下思路。
class Solution994 {
public:
    int time = 0;
    bool stateChange = false;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> qp;     // 记录腐烂橘子下标
        int fresh = 0;                // 新鲜橘子个数
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    qp.push({i, j});
                }
            }
        }
        if(fresh == 0){
            return time;
        }
        time++;
        // 模拟腐烂
        stateChange = false;
        while(!qp.empty()){
            auto pos = qp.front();
            qp.pop();
            int x = pos.first;
            int y = pos.second;
            rotting(grid, x+1, y, n, m);
            rotting(grid, x-1, y, n, m);
            rotting(grid, x, y+1, n, m);
            rotting(grid, x, y-1, n, m);
        }
        if(stateChange == false){
            return -1;
        }else{
            return orangesRotting(grid);
        }
    }

    bool validPos(int x, int y, int n, int m){
        if(x>=0 && x<n && y>=0 && y<m){
            return true;
        }
        return false;
    }

    void rotting(vector<vector<int>>& grid, int x, int y, int n, int m){
        // 前提是坐标有效
        if(!validPos(x,y,n,m)){
            return ;
        }
        if(grid[x][y] == 1){
            grid[x][y] == 2;
            stateChange = true;
        }
    }
};