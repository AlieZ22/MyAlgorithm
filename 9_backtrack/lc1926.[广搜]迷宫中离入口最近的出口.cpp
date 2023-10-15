#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos{
    int x, y;
    Pos(){}
    Pos(int x, int y):x(x),y(y){}
};

class Solution {
private:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int n;
    int m;
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int step = 0;
        n = maze.size();
        m = maze[0].size();
        queue<Pos> qp;
        int x = entrance[0];
        int y = entrance[1];
        // 防止回溯可以将走过的地方置为墙
        //vector<vector<bool>> visited(n, vector<bool>(m));
        maze[x][y] = '+';
        // 获得初始的方向
        for(int i=0; i<4; ++i){
            if(valid(x+dx[i], y+dy[i]) && !isWall(x+dx[i], y+dy[i], maze)){
                qp.push({x+dx[i], y+dy[i]});
            }
        }
        // 直到走出边界
        while(!qp.empty()){
            int size = qp.size();
            ++step;
            for(int k=0; k<size; ++k){
                auto pos = qp.front();
                qp.pop();
                maze[pos.x][pos.y] = '+';
                for(int i=0; i<4; ++i){
                    x = pos.x + dx[i];
                    y = pos.y + dy[i];
                     // 找到出口
                    if(!valid(x, y)){
                        return step;
                    }
                    // 其余可走的路径
                    if(!isWall(x,y,maze)){
                        qp.push({x,y});
                    }
                }
            }
        }
        return -1;
    }

    bool isWall(int x, int y, vector<vector<char>>& maze){
        if(maze[x][y] == '+'){
            return true;
        }
        return false;
    }

    bool valid(int x, int y){
        if(x >= 0 && x < n && y >=0 && y < m){
            return true;
        }
        return false;
    }

};