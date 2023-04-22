#include <iostream>
#include <string>
using namespace std;

#define INT_MIN -99999

const int N = 201;
int colorMap[N][N];    // B:0, R:1
int coinMap[N][N];
int dp[N][N];     // 表示 i,j停下时，获得的最多金币数量
int res = 0;
int k=0;

// 从(i, j-1) -> (i, j)
int coinFromLeft(int i, int j){
  if(j-1 == 0){
    return INT_MIN;
  }else{
    if(colorMap[i][j-1] != colorMap[i][j]){
      return dp[i][j-1] - k;
    }else{
      return dp[i][j-1];
    }
  }
}

// 从(i-1, j) -> (i, j)
int coinFromUp(int i, int j){
  if(i-1 == 0){
    return INT_MIN;
  }else{
    if(colorMap[i-1][j] != colorMap[i][j]){
      return dp[i-1][j] - k;
    }else{
      return dp[i-1][j];
    }
  }
}

int main(){
  int n, m;
  char c;
  scanf("%d %d %d", &n, &m, &k);
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      cin>>c;
      if(c == 'B') colorMap[i][j]=0;
      if(c == 'R') colorMap[i][j]=1;
    }
  }
  int coin;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      cin>>coin;
      coinMap[i][j] = coin;
    }
  }
  // 动态规划
  coin = 0;
  for(int i=0; i<=n; ++i) dp[i][0] = 0;
  for(int j=0; j<=m; ++j) dp[0][j] = 0;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      if(i==1 && j==1){
        coin = coinMap[i][j];
        continue;
      }
      int coinFL = coinFromLeft(i,j);
      int coinFU = coinFromUp(i,j);
      if(max(coinFL, coinFU) < 0){
        break;
      }
      dp[i][j] += max(coinFL, coinFU) + coinMap[i][j];
      res = max(res, dp[i][j]);
    }
  }
  cout<<res<<endl;
  return 0;
}