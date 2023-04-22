#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+10;
int n, k;
vector<ll> arr[N];  // 保存ai(ai1 - aik)
ll res=0;
map<vector<ll>,ll> umap;    // 存储差分数组字符串 以及个数

// 快乐对：ai+bi = aj+bj  --> ai-aj = -(bi-bj)
// 即，两个数列的差分数组(从1开始)相反的话，那就可以成为一个完美对

vector<ll> chagedVec(const vector<ll>& vec){
    vector<ll> _vec(vec);
    for(ll &t: _vec){
        t = -t;
    }
    return _vec;
}

int main(){
    scanf("%d %d", &n, &k);
    ll tmp;
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j){
            cin>>tmp;
            arr[i].push_back(tmp);
        }
    }
    // 遍历每组ai，得到差分数组，忽略b[1]，因为只要看后面变化
    for(int i=1; i<=n; ++i){
        vector<ll> bv(k-1,0);
        for(int j=1; j<k; ++j){
            bv[j-1] = (arr[i][j] - arr[i][j-1]);
        }
        vector<ll> verse_bv = chagedVec(bv);
        res += umap[verse_bv];             // 先结算结果，再加上这次的
        ++umap[bv];
    }
    cout<<res<<endl;
    return 0;
}