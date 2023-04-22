#include <bits/stdc++.h>
using namespace std;

// 100%

const int N = 1010;
int arr[N][N];      // 记录哪里有敌人
int S[N][N];        // 前缀和
int n;  // 敌人数
int A, B;

int main(){
    scanf("%d %d %d", &n, &A, &B);
    int x, y;
    for(int i=1; i<=n; ++i){
        scanf("%d %d", &x, &y);
        arr[x][y]++;
    }
    // 前缀和
    for(int i=1; i<N; ++i){
        for(int j=1; j<N; ++j){
            S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + arr[i][j];
        }
    }
    int maxNum = 0;
    for(int i=B+1; i<N; ++i){
        for(int j=A+1; j<N; ++j){
            maxNum = max(maxNum, S[i][j] - S[i-B-1][j] - S[i][j-A-1] + S[i-B-1][j-A-1]);
        }
    }
    cout<<maxNum<<endl;
    return 0;
}