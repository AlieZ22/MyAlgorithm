#include <bits/stdc++.h>
using namespace std;

/*
求数组每个数左边第一个比它小的数，如果不存在则输出-1
*/

const int N = 1e5+10;
int n;
int ans[N];
int st[N];

int main(){
    scanf("%d", &n);
    int tmp;
    st[0]=-1;
    int stPos = 0;
    for(int i=1;i<=n;++i){
        scanf("%d", &tmp);
        if(tmp > st[stPos]){
            ans[i] = st[stPos++];
            st[stPos] = tmp;
        }else{
            while(stPos>0 && tmp <= st[stPos]){
                --stPos;
            }
            ans[i] = st[stPos++];
            st[stPos] = tmp;
        }
    }
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}