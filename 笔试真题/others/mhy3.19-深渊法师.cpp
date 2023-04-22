#include <bits/stdc++.h>
using namespace std;

// 15%, 10%

const int N = 2e5+10;
int n,x;
int dun[N];    // 每个法师的护盾值
char attr[N];   // 每个法师的属性：F, I, W
int cost = 0;

bool checkDun(int start, int end){
    for(int i=start; i<=end; ++i){
        if(dun[i]!=0) return false;
    }
    return true;
}

// 取[i,j-1] 判断如何最优, 连续的-属性不同的法师
void minCost(int start, int end){
    // 总是取dun最大的值，消除
    int maxDun =  -1;
    int pos = 0;
    while(!checkDun(start, end)){
        maxDun=-1;
        for(int i = start; i<=end; ++i){
            if(dun[i]>maxDun){
                maxDun = dun[i];
                pos = i;
            }
        }
        if(pos==start){ // 只能连右边消除
            if(dun[pos+1]!=0 && dun[pos]+dun[pos+1] >= x){
                cost += x;
                dun[pos]=0;
                dun[pos+1]=0;
            }else{
                cost += dun[pos];
                dun[pos]=0;
            }
        }else if(pos==end){      // 只能连左边消除
            if(dun[pos-1]!=0 && dun[pos]+dun[pos-1] >= x){
                cost += x;
                dun[pos]=0;
                dun[pos-1]=0;
            }else{
                cost += dun[pos];
                dun[pos]=0;
            }
        }else{
            // 看看连左边还是连右边
            if(dun[pos-1]==0 && dun[pos+1]==0){   // 左右都不连
                cost += dun[pos];
                dun[pos]=0;
            }else if(dun[pos-1]==0){
                if(dun[pos]+dun[pos+1] >=x){
                    cost+=x;
                    dun[pos]=0;
                    dun[pos+1]=0;
                }else{
                    cost +=dun[pos];
                    dun[pos]=0;
                }
            }else{
                if(dun[pos]+dun[pos-1] >=x){
                    cost+=x;
                    dun[pos]=0;
                    dun[pos-1]=0;
                }else{
                    cost +=dun[pos];
                    dun[pos]=0;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &x);
    for(int i=1; i<=n; ++i){
        scanf("%d", &dun[i]);
    }
    for(int i=1; i<=n; ++i){
        cin>>attr[i];
    }
    for(int i=1; i<=n; ++i){
        if(dun[i]==0){
            continue;
        }
        if(i==n){
            cost+=dun[i];
        }
        if(i!=n && attr[i]==attr[i+1]){     // 不能用高天之歌
            cost+=dun[i];
            dun[i]=0;
            continue;
        }
        if(i!=n && attr[i] != attr[i+1]){     // 可以使用高天之歌，判断要不要用
            // 连续多个不同属性的话，需要判断应该怎么用高天之歌
            int j = i+1;
            while(j<=n && attr[j]!=attr[j-1]) ++j;
            // 取[i,j-1] 判断如何最优
            minCost(i, j-1);
            i=j;
        }
    }
    cout<<cost<<endl;
    return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,x;
int dun[N];    // 每个法师的护盾值
char attr[N];   // 每个法师的属性：F, I, W
int cost = 0;

int main(){
    scanf("%d %d", &n, &x);
    for(int i=1; i<=n; ++i){
        scanf("%d", &dun[i]);
    }
    for(int i=1; i<=n; ++i){
        cin>>attr[i];
    }
    for(int i=1; i<=n; ++i){
        if(dun[i]==0){
            continue;
        }
        if(i==n){
            cost+=dun[i];
        }
        if(i!=n && attr[i]==attr[i+1]){     // 不能用高天之歌
            cost+=dun[i];
            dun[i]=0;
            continue;
        }
        if(i!=n && attr[i] != attr[i+1]){     // 可以使用高天之歌，判断要不要用
            if(dun[i]+dun[i+1] >= x){  // use
                cost+=x;
                dun[i]=0;
                dun[i+1]=0;
            }else{                     // not use
                cost+=dun[i];
                dun[i]=0;
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}

*/