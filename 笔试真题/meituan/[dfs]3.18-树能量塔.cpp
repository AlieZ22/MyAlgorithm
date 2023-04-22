#include <bits/stdc++.h>
using namespace std;

/*
给定一颗n个节点的树，每个节点有一个能量塔，可以为距离当前点不超过给定能量值的点提供一点能量。
求，最终每个点可以获得多少能量。（能量塔自己可以给自己提供能量）
示例：
3
1 1 1
1 2
3 2
-output-: 2 3 2
>> 对树上的某个点，dfs一次，复杂度为O(n^2)
*/

const int N = 510;
int n;
int energy[N];
int res[N];
int g[N][N];   // 存储无向图


// 当前点，父节点（防止图重复遍历），剩余可达距离
void dfs(int x, int f, int leftdis){
    if(leftdis<0) return;
    ++res[x];
    for(int i=1; i<N; ++i){
        if(i == f) continue;      // 防止重复遍历
        if(g[x][i] == 1){
            dfs(i, x, leftdis-1);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &energy[i]);
    }
    int x,y;
    for(int i=1; i<n; ++i){
        scanf("%d %d", &x, &y);
        g[x][y] = 1;
        g[y][x] = 1;
    }
    for(int i=1; i<=n; ++i){
        dfs(i, i, energy[i]);
    }
    for(int i=1; i<=n; ++i){
        cout<<res[i]<<" ";
    }
    return 0;
}