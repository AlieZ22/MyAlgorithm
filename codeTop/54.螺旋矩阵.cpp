#include <bits/stdc++.h>
using namespace std;


/*
设置一个visited，如果触碰边界或者已经访问过，就转个方向
*/

class Solution_hot54 {
public:
    int k = 0;   // 表示当前取哪个方向
    int direction[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};  // 预定四个方向
    int n, m;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        vector<int> res;
        this->n = matrix.size();
        this->m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int i=0, j=0;
        int cnt = 0;
        // 总共执行row*col次
        while(cnt < n*m){
            res.push_back(matrix[i][j]);
            visited[i][j] = true;
            int newI = i+direction[k][0];
            int newJ = j+direction[k][1];
            if(!isValid(newI, newJ) || visited[newI][newJ]){
                ++k;
                k%=4;
            }
            i = newI;
            j = newJ;
            ++cnt;
        }
        return res;
    }

    bool isValid(int x, int y){
        if(x>=0 && x<n && y>=0 && y<m){
            return true;
        }
        return false;
    }
};