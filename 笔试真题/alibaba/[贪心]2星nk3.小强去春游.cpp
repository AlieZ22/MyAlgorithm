#include <bits/stdc++.h>
using namespace std;

/*
当人数小于等于3时，只有一种最优解：a+b+c
当人数大于3时，会有两种情况：假设四人体重从小到大 abcd
1，用a来运c,d: 2*a+c+d
2，先ab把b运过去，a回来，然后cd一起走，b把船运回来：a+2*b+d
人数大于3时，应该取这两种情况的最小代价
*/

const int N = 1e5+10;
typedef long long ll;
ll cost = 0;
int t,n;

int main(){
    scanf("%d", &t);      // t组数据
    for(int i=0;i<t;++i){
        cost = 0;
        scanf("%d", &n);
        vector<int> a(n);     // 每个人的体重
        for(int j=0; j<n; ++j){
            scanf("%d", &a[j]);
        }
        // 体重排序
        sort(a.begin(), a.end());
        // 运输
        int r=n-1;
        while(r>=3){       // 处理人数大于3的情况
            cost += min(2*a[0]+a[r-1]+a[r], a[0]+2*a[1]+a[r]);
            r-=2;
        }
        if(r==2){        // 3个人
            cost += a[0]+a[1]+a[2];
        }else{           // 2个人
            cost += a[1];
        }
        cout<<cost<<endl;
    }
    return 0;
}