#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

// 通过：66.67%，时间复杂度过高

/*
grid[i][j]表示单元格的金币数，可以为0，如果grid[i][j]=-1，那么不可通行
但是有一次机会可以使用技能将一个不可达地方变为grid[i][j]=0
小明可以任意移动，求他最多可以收集多少金币？
*/

// md，还要自己处理输入。。
vector<int> parseRow(const string& str){
    vector<int> row;
    int num;
    stringstream ss;
    for(char c: str){
        if(isdigit(c) || c=='-'){
            ss << c;
        }
        else if(c == ',' || c == ']'){
            if(ss.str().length()>0){
                ss >> num;
                row.push_back(num);
                ss.clear();
                ss.str("");
            }
        }
    }
    return row;
}

int dfs(vector<vector<int>>& grid, int x, int y, bool useSkill){
    int m = grid.size(), n = grid[0].size();
    if(x<0 || x>=m || y<0 || y>=n) return 0;

    if(grid[x][y] == -1){
        if(useSkill) return 0;
        useSkill = true;
    }

    int gold = max(0, grid[x][y]);
    int original = grid[x][y];
    grid[x][y] = -1;   // 标记已访问

    int temp = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for(int i=0; i<4; ++i){
        int newX = x + dx[i], newY = y + dy[i];
        temp = max(temp, dfs(grid, newX, newY, useSkill));
    }
    grid[x][y] = original;   // 恢复路径访问
    return gold + temp;
}

int main() {
    vector<vector<int>> grid;
    string line;
    // 读取
    while(true){
        getline(cin, line);
        if(line.empty()){
            break;
        }
        vector<int> row = parseRow(line);
        grid.push_back(row);
    }

    int result = dfs(grid, 0, 0, false);
    cout<<result<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")