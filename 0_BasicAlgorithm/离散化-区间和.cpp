#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 300010;
int n,m;
typedef pair<int,int> PII;
vector<int> alls;
vector<PII> adds, querys;
int a[N], S[N];

vector<int>::iterator unique(vector<int>& vec){
    int j=0;
    for(int i=0; i<vec.size(); ++i){
        if(!i || vec[i]!=vec[i-1]){
            vec[j++] = vec[i];
        }
    }
    return vec.begin()+j;
}

// 从alls的值，找到a中对应的下标(二分)
int find(int x){
    int l=0, r=alls.size()-1;
    while(l<r){
        int mid = (r-l)/2 + l;
        if(alls[mid] >= x) r=mid;
        else l=mid+1;
    }
    return l;
}

int main(){
    scanf("%d %d", &n, &m);
    int x, c;
    for(int i=0;i<n;++i){
        scanf("%d %d", &x, &c);
        adds.push_back(PII{x,c});
        alls.push_back(x);
    }
    int l, r;
    for(int i=0;i<m;++i){
        scanf("%d %d", &l, &r);
        querys.push_back(PII{l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 排序，去重alls
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls), alls.end());
    
    // 添加
    for(int i=0;i<n;++i){
        int idx = find(adds[i].first)+1;       // a[]从下标1开始
        a[idx] += adds[i].second;
    }
    
    // 前缀和
    for(int i=1;i<=alls.size();++i){
        S[i] = S[i-1] + a[i];
    }
    
    // 输出结果
    for(int i=0;i<m;++i){
        int l = find(querys[i].first)+1;
        int r = find(querys[i].second)+1;
        cout<<S[r]-S[l-1]<<endl;
    }
    return 0;
}