#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int t[N][N];
int n, m;
int S[N][N];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            int tmp = 0;
            scanf("%d", &tmp);
            S[i][j] = S[i-1][j]+S[i][j-1]-S[i-1][j-1]+tmp;
        }
    }
    int res = INT_MAX;
    for(int i=1; i<=n; ++i){
        res = min(res, abs(S[i][m] - (S[n][m] - S[i][m])));
    }
    for(int j=1; j<=m; ++j){
        res = min(res, abs(S[n][j] - (S[n][m] - S[n][j])));
    }
    printf("%d", res);
    return 0;
}