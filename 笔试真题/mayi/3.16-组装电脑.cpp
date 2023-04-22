#include <bits/stdc++.h>
using namespace std;

// 93%

const int M = 41;
typedef long long ll;
typedef pair<ll,ll> PII;    // 价格-性能
ll n, x, m;
PII objs[M][M];
int objLen[M];     // 每组零件的个数
bool isComposed = false;       // 结果，是否能组装好
int res = 0;       // 结果，最终最大性能

// 每一层取一个，回溯
// 第k个零件，剩余预算leftx，总性能sumXN
void traversal(int k, int leftx, int sumXN){
    if(leftx < 0){
        return ;
    }
    if(k == n+1){
        isComposed = true;
        res = max(res, sumXN);
        return ;
    }
    int ol = objLen[k];
    for(int j=1; j<=ol; ++j){
        // 剪枝
        if(leftx < objs[k][j].first){
            break;
        }
        traversal(k+1, leftx-objs[k][j].first, sumXN+objs[k][j].second);
    }
}

int main(){
    scanf("%d %d", &n, &x);
    for(int i=1; i<=n; ++i){
        scanf("%d", &m);
        objLen[i] = m;
        for(int j=1;j<=m;++j){
            scanf("%d", &objs[i][j].first);
        }
        for(int j=1; j<=m; ++j){
            scanf("%d", &objs[i][j].second);
        }
    }
    // 给每一个型号的价格排序
    for(int i=1; i<=n; ++i){
        sort(objs[i]+1, objs[i]+1+objLen[i]);
    }
    traversal(1, x, 0);
    if(isComposed){
        cout<<res<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}