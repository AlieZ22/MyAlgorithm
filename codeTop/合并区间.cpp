#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
const int N = 10e5+1;
vector<PII> segs, res;
int n;

int main(){
    scanf("%d", &n);
    int l,r;
    while(n--){
        scanf("%d %d", &l, &r);
        segs.push_back(PII{l, r});
    }
    sort(segs.begin(),segs.end());
    int st=-10e9-1, ed=-10e9-1;
    for(int i=0; i<segs.size(); ++i){
        if(ed < segs[i].first){
            if(ed != -10e9-1) res.push_back(PII{st,ed});
            st = segs[i].first;
            ed = segs[i].second;
        }
        ed = max(ed, segs[i].second);
    }
    cout<<res.size()<<endl;
    return 0;
}


/*
5
1 2
2 4
5 6
7 8
7 9
*/