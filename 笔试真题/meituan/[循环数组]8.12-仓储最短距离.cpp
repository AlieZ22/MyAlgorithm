#include<bits/stdc++.h>
using namespace std;

/*
1 < n < 1e5
1 < a_i < 1e9
*/

typedef long long LL;      // 注意要用long long
const int N = 1e5 + 10;
int n;
LL Sum=0, x, y;
LL S[N];

int main(){
    scanf("%d", &n);
    for(int i=2; i<=n+1; ++i){
        LL len = 0;
        scanf("%lld", &len);
        S[i] = S[i-1] + len;
        Sum += len;
    }
    scanf("%lld %lld", &x, &y);
    LL max_n = max(x, y);
    LL min_n = min(x, y);
    LL dist = S[max_n]-S[min_n];
    LL res = min(dist, Sum-dist);
    printf("%lld", res);
    return 0;
}