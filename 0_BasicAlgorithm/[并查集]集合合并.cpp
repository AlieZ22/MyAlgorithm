#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, m;
int p[N];

int findRoot(int x){
    if(x!=p[x]) p[x]=findRoot(p[x]);
    return p[x];
}

void mergeSet(int u, int v){
    u = findRoot(u);
    v = findRoot(v);
    p[u] = v;
}

bool isInsection(int u, int v){
    u = findRoot(u);
    v = findRoot(v);
    if(u==v){
        return true;
    }else{
        return false;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    char ops;
    // 初始化p[], 起初每个节点都是根
    for(int i=1;i<=n;++i){
        p[i]=i;
    }
    int u, v;
    for(int i=0; i<m; ++i){
        cin>>ops>>u>>v;
        if(ops=='M'){
            mergeSet(u,v);
        }else{
            bool res = isInsection(u,v);
            if(res){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}