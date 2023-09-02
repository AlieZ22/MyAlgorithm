#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// 通过：80%，注意是正方形切分，而且不是一刀切

const int N = 1e3 + 10;
int n, m;
int S[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%d", &S[i][j]);
            S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
        }
    }
    int res = INT_MAX;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            for(int k=1; i+k<=n && j+k<=m; ++k){
                int sum1 = S[i+k][j+k] - S[i-1][j+k] - S[i+k][j-1] + S[i-1][j-1];
                int sum2 = S[n][m] - sum1;
                res = min(res, abs(sum1 - sum2));
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")