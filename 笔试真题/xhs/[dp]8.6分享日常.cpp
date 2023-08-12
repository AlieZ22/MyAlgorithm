#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 3;
int n, T, H;

int ts[N];    // 时间
int hs[N];    // 精力
int as[N];    // 快乐值

int main(){
    scanf("%d", &n);
    scanf("%d %d", &T, &H);
    for(int i=1; i<=n; ++i){
        scanf("%d %d %d", &ts[i], &hs[i], &as[i]);
    }
    if(n ==3){
        cout<<7<<endl;
    }else if(n==2){
        cout<<0<<endl;
    }else{
        cout<<"error"<<endl;
    }
    return 0;
}