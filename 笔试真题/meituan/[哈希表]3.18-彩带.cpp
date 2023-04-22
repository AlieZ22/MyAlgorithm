#include <bits/stdc++.h>
using namespace std;

// 100%

const int N = 5010;
const int M = 2010;
int n, k;
int arr[N];   // 保存所有彩带色彩数字
int bucket[M];   // 保存所有彩带颜色-对应的出现次数
int res = 0;

// 如果颜色数小于等于k，返回true
bool checkColor(){
    int cnt = 0;
    for(int i=1; i<M; ++i){
        if(bucket[i] > 0) ++cnt;
    }
    if(cnt > k) return false;
    else return true;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; ++i){
        scanf("%d", &arr[i]);
    }
    int i=1, j=1;
    for(j=1; j<=n; ++j){
        bucket[arr[j]]++;
        while(!checkColor() && i<j){
            bucket[arr[i]]--;
            ++i;
        }
        res = max(res, j-i+1);
    }
    cout<<res<<endl;
    return 0;
}