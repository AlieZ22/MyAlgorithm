#include <bits/stdc++.h>
using namespace std;

const int N = 51;
const int M = 1e9+7;
typedef long long ll;
int n,m;
ll dp[N][N];       // dp，解决树的个数问题

// 与代码随想录动态规划中，二叉搜索树种类题类似，这里多了一层循环来限制层数

int main(){
    scanf("%d %d", &n, &m);
    // dp初始化
    for(int j=0;j<=m;++j){
        dp[0][j]=1;
    }
    for(int i=1;i<=n;++i){            // 当前总共节点数
        for(int j=1;j<=m;++j){        // 当前层数
            // 计算dp[i][j]
            for(int k=1;k<=i;++k){    // 将总节点划分的方案
                dp[i][j] += dp[k-1][j-1] * dp[i-k][j-1];
                dp[i][j] = (dp[i][j]%M);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}