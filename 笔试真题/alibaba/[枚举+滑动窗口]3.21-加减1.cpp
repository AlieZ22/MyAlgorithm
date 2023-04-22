#include <bits/stdc++.h>
using namespace std;

/*
由于窗口内的数只会变成0-9，这个范围非常小，可以去穷举
所以，先假设一个窗口内的值变为x，复杂度为O(10n)
5 3
2 9 1 8 3
>> 7
*/

// ac 100%

const int N = 1e5+10;
int n, k;
int arr[N];
int ops = 0;             // 某个窗口的操作数
int minOps = INT_MAX;    // 最小的操作数

int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;++i){
        scanf("%d", &arr[i]);
    }
    // 将滑动窗口的值固定
    for(int x=0; x<=9; ++x){
        ops = 0;
        // 先加上前k个
        for(int i=1;i<=k;++i){
            ops += abs(arr[i]-x);
        }
        minOps = min(minOps, ops);
        // k后面的窗口遍历
        int i=1, j;
        for(j=k+1;j<=n;++j){
            ops -= abs(arr[i]-x);
            ++i;
            ops += abs(arr[j]-x);
            minOps = min(minOps, ops);
        }
    }
    cout<<minOps<<endl;
    return 0;
}
