#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int t, n;
typedef pair<int,int> PII;
PII a[N];
int tails[N];    // tails[i] 长度为i的最长递增子序列的末尾元素


/*
error1: 没有考虑到a-first相等的情况，即first不一定严格单增
solution: 当first相同时，second降序排，这样就不会重复统计

error2: 直接用dp来做最长递增子序列长度超时
solution: 贪心+二分
*/

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
    // 小-大
    // a-first升序，相同时a-second降序
    sort(a+1, a+n+1, cmp);
    // a-second中取最长递增子序列, 动态规划会超时，用贪心+二分
    tails[1] = a[1].second;
    int j=1;
    for(int i=2; i<=n; ++i){
        if(a[i].second > tails[j]) tails[++j] = a[i].second;
        else{
            // 二分查找tails(1~j)，找到插入位置
            int l=1, r=j;
            while(l<r){
                int mid = (l+r)>>1;
                if(tails[mid] >= a[i].second) r = mid;
                else l = mid+1;
            }
            tails[l] = a[i].second;
        }
    }
    return j;
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