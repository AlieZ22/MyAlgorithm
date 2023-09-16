#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
int n, m;
vector<vector<int>> grid;
vector<vector<int>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(){
    deque<pair<PII,int>> q;
    q.push_front({{0,0}, grid[0][0]});
    visited[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop_front();

        if(x==n-1 && y==m-1){
            return cnt;
        }

        for(int i=0; i<4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx, ny) && !visited[nx][ny]){
                visited[nx][ny] = 1;
                if(grid[nx][ny] == 0){
                    q.push_front({{nx, ny}, cnt});
                }else{
                    q.push_back({{nx, ny}, cnt+1});
                }
            }
        }
    }
    return -1;
}


int main(){
    scanf("%d %d", &n, &m);
    grid = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<int>>(n, vector<int>(m));

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%d", &grid[i][j]);
        }
    }

    int ans = bfs();
    cout<<ans<<endl;
    return 0;
}