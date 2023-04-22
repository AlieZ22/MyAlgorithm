#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 1;

int main(){
    int t, n;
    cin >> t >> n;
    while(t--){
        int res = 0, one_cnt = 0;
        int tmp;
        for (int i = 0; i < n;++i){
            if(tmp>1) ++res;
            else ++one_cnt;
        }
        res += (one_cnt + 1) / 2;
        cout << res << endl;
    }
    return 0;
}