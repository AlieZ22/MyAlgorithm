#include <bits/stdc++.h>
using namespace std;

const int Len = 12+1;
int n, m, p;
int bag[Len];
int ans[Len];      // 总是保存最小字典序的
int isGet = 0;

// AC：98%

void updateAns(){
    if(!isGet){
        for(int i=1; i<=m; ++i){
            ans[i] = bag[i];
        }
        isGet = 1;
    }else{
        int changeSign = 0;
        for(int i=1; i<=m; ++i){
            if(bag[i] < ans[i]){
                changeSign = 1;
                break;
            }
        }
        if(changeSign==1){
            for(int i=1; i<=m; ++i){
                ans[i] = bag[i];
            }
        }
    }
}

void checkPrice(){
    int price = 0;
    for(int i=1; i<=m; ++i){
        price += bag[i]*bag[i];
    }
    if(price == p){
        updateAns();
    }
}

void dfs(int num){
    if(num == 0){
        checkPrice();
        return;
    }
    // 每次总是尝试先放入最后一个格子
    for(int i=m; i>0; --i){
        if(i==m || bag[i]+1 <= bag[i+1]){        // 剪枝，保证bag单调递增
            ++bag[i];
            dfs(num-1);
            --bag[i];
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &p);
    for(int i=1; i<=m; ++i){
        bag[i] = 1;
    }
    n = n-m;
    dfs(n);
    if(isGet){
        for(int i=1; i<=m; ++i){
            cout<<ans[i];
            if(i!=m){
                cout<<" ";
            }
        }
    }else{
        cout<<-1<<endl;
    }
    return 0;
}