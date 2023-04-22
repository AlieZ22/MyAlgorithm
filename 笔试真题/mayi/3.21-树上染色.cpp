#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const char c1 = 'R';
const char c2 = 'W';
int n;
int u, v;
char color[N];       // 每个节点的颜色

vector<int> g[N];    // 存储图 i节点所连接的节点集
int minOps = INT_MAX;
int ops = 0;

// 对节点i的孩子做规范，f防止重复路径，c是i节点应该的颜色，ops为总操作次数
void dfs(int i, int f, char c){
    if(color[i] != c){
        ++ops;
    }
    int sz = g[i].size();
    int needc = c==c1?c2:c1;
    for(int k=0; k<sz; ++k){
        if(g[i][k] != f){
            dfs(g[i][k], i, needc);
        }
    }
}

void traversal(){
    for(int i=1; i<=n; ++i){
        ops = 0;
        dfs(i,i,color[i]);
        minOps = min(minOps, ops);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        cin>>color[i];
    }
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    traversal();
    cout<<minOps<<endl;
    return 0;
}