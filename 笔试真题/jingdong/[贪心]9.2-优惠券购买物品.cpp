#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 通过：0%，有些问题，还得看看

typedef long long LL;
const int N = 2e5 + 10;
LL items[N];
int n, m;
LL res = 0;

void quick_sort(LL q[], int l, int r){
    if(l>=r) return;
    int i=l-1, j=r+1, mid = q[(l+r)>>1];
    while(i<j){
        do ++i; while(q[i] < mid);
        do --j; while(q[j] > mid);
        if(i<j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

int main() {
    scanf("%d %d", &n, &m);
    //vector<LL> items(n, 0);
    vector<vector<int>> yhq(m, vector<int>(2));
    for(int i=0; i<n; ++i){
        scanf("%lld", &items[i]);
    }
    for(int i=0; i<m; ++i){
        scanf("%d %d", &yhq[i][0], &yhq[i][1]);
        //cout<<yhq[i][0]<<" "<<yhq[i][1]<<endl;
    }
    quick_sort(items, 0, n-1);
    //quick_sort(yhq, 0, m-1);
    //sort(items.begin(), items.end());
    sort(yhq.begin(), yhq.end());
    for(int i=n-1; i>=0; --i){
        LL price = items[i];
        // 找一个最大优惠
        for(int j=m-1; j>=0; --j){
            if(yhq[j][0] == 0) continue;
            if(yhq[j][0] <= price){
                //cout<<"使用优惠："<<yhq[j][0]<<"-"<<yhq[j][1]<<endl;
                price -= yhq[j][1];
                yhq[j][0] = 0;
                break;
            }
        }
        res += price;
    }
    cout<<res<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")