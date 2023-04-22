#include <bits/stdc++.h>
using namespace std;

/*
ac 100%
排序a,b数组，这样他们的差绝对值之和肯定最小（贪心），记录b数组原来的值和对应的下标
开辟res数组，res[b原来下标处] = a[当前下标]即可
*/

const int N = 1e5+10;
int a[N];
int n;
typedef pair<int,int> PII;    // 绝对值的差，下标

vector<int> min_abs_diff(vector<PII>& signB){
    sort(a, a+n);
    sort(signB.begin(), signB.end());
    vector<int> res(n);
    for(int i=0;i<n;++i){
        int idx = signB[i].second;
        res[idx] = a[i];
    }
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", &a[i]);
    }
    vector<PII> sign_b(n);
    int tmp;
    for(int i=0;i<n;++i){
        scanf("%d", &tmp);
        sign_b[i].first = tmp;
        sign_b[i].second = i;
    }
    vector<int> res = min_abs_diff(sign_b);
    for(auto& item: res){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}