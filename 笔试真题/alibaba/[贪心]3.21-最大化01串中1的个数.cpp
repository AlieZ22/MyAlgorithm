#include <bits/stdc++.h>
using namespace std;

// ac 79%

string s;
int ops = 0;          // 当前操作次数
int orig_cnt1 = 0;    // 之前1的个数
int cnt1 =0;          // 操作后，1的个数

char verseChar(char c){
    if(c=='1') return '0';
    else return '1';
}

int main(){
    cin>>s;
    int n = s.size();
    // 记录原来1的个数
    for(int i=0; i<n; ++i){
        if(s[i] == '1') ++orig_cnt1;
    }
    // 总是让左边排满1
    for(int i=0; i<n; ++i){
        if(i<n-1 && s[i]=='0'){
            ++ops;
            s[i] = verseChar(s[i]);
            s[i+1] = verseChar(s[i+1]);
        }
    }
    // 统计操作后1的个数
    for(int i=0; i<n; ++i){
        if(s[i] == '1') ++cnt1;
    }
    if(cnt1 > orig_cnt1){
        cout<<ops<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}