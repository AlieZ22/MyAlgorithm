#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
typedef long long ll;
int res=0;
ll n,r;
ll antisPos[N][3];     // 敌人坐标
ll oriPos[3];          // 技能坐标(x,y,z)

// 检验第k个敌人与技能的距离
bool checkDis(int k, ll r){
    ll dis = antisPos[k][0]*antisPos[k][0] + antisPos[k][1]*antisPos[k][1]
            + antisPos[k][2]*antisPos[k][2];
    if(dis <= r*r){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin>>n>>r;
    for(int i=1; i<=n; ++i){
        cin>>antisPos[i][0]>>antisPos[i][1]>>antisPos[i][2];
    }
    cin>>oriPos[0]>>oriPos[1]>>oriPos[2];
    // 计算相对位置
    for(int i=1; i<=n; ++i){
        antisPos[i][0] -= oriPos[0];
        antisPos[i][1] -= oriPos[1];
        antisPos[i][2] -= oriPos[2];
    }
    // 检验距离
    for(int i=1; i<=n; ++i){
        if(checkDis(i,r)){
            ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}