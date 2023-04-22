#include <bits/stdc++.h>
using namespace std;

string s;
int cnt_a = 0;
int cnt_bc = 0;

int main(){
    cin>>s;
    int n = s.size();
    for(int i=0;i<n;++i){
        if(s[i]=='a'){
            ++cnt_a;
        }else{
            ++cnt_bc;
        }
    }
    int res = 0;
    if(cnt_a >= cnt_bc){
        res = (cnt_a - cnt_bc) / 2;
    }else{
        res = (cnt_bc - cnt_a) / 2;
    }
    cout<<res<<endl;;
    return 0;
}