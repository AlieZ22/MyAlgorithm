#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int M = 1e9+7;
int t, a, b, n;
long long Rn[N];

/*
Rn: x^n+y^n
a: x+y, b:xy
Rn = a*Rn-1 - b*Rn-2
*/

int main(){
    scanf("%d", &t);
    cout<<M<<endl;
    while(t--){
        scanf("%d %d %d", &a, &b, &n);
        Rn[0] = 2;
        Rn[1] = a;
        for(int i=2; i<=n; ++i){
            Rn[i] = (((a*Rn[i-1]) %M) - ((b*Rn[i-2])%M) + M) %M;
        }
        cout<<Rn[n]<<endl;
    }
    return 0;
}