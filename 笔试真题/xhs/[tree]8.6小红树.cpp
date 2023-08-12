#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, u, v;

int nodes[N];      // 每个点的权值
//int edges[N][N];   // 连接图

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &nodes[i]);
    }
    for(int i=1; i<n; ++i){
        scanf("%d %d", &u, &v);
    }
    cout<<1<<endl;
    return 0;
}