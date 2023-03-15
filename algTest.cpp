#include <bits/stdc++.h>
using namespace std;

const int N = 10e5+10;
int t, n;
typedef pair<int,int> PII;
PII a[N];
int dp[N];

// error: 没有考虑到a-first相等的情况，即first不一定严格单增
// solution: 当first相同时，second降序排，这样就不会重复统计

bool cmp(const PII& p1, const PII& p2){
    if(p1.first < p2.first){
        return true;
    }else if(p1.first > p2.first){
        return false;
    }else{
        if(p1.second > p2.second){
            return true;
        }else{
            return false;
        }
    }
}

int findMaxObj(){
    int cnt = 0;
    // 小-大
    // a-first升序，相同时a-second降序
    sort(a+1, a+n+1, cmp);
    // a-second中取最长递增子序列
    for(int i=1; i<=n; ++i) dp[i]=1;
    for(int i=2; i<=n; ++i){
        for(int j=1; j<i; ++j){
            if(a[i].second > a[j].second) dp[i] = max(dp[i], dp[j]+1);
        }
        if(dp[i] > cnt) cnt=dp[i];
    }
    return cnt;
}

int main(){
    scanf("%d", &t);
    int tmp;
    int res;
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;++i){
            scanf("%d", &tmp);
            a[i].first = tmp;
        }
        for(int i=1;i<=n;++i){
            scanf("%d", &tmp);
            a[i].second = tmp;
        }
        res = findMaxObj();
        cout<<res<<endl;
    }
    return 0;
}