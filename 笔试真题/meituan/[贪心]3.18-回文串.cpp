#include <bits/stdc++.h>
using namespace std;

// 82%

string s;
int ops = 0;    // 可操作次数
int needChange[2] = {-1, -1};  // 题目保证能够形成回文串，那么最多改变两次，记录需要改变的位置
int ncPos = 0;

int main(){
    cin>>s;
    int i=0, j=s.size()-1;
    // 统计可操作次数，以及需要改变的位置
    while(i<j){
        if(s[i] != s[j]){
            needChange[ncPos++] = i;
        }
        if(ncPos >= 2){
            break;
        }
        ++i;
        --j;
    }
    ops = 2-ncPos;
    if(ops==0){
        for(int i=0;i<ncPos;++i){
            int index = needChange[i];
            int index2 = s.size()-1-index;
            if(s[index] < s[index2]){
                s[index2]=s[index];
            }else{
                s[index]=s[index2];
            }
        }
    }
    if(ops==1){  // 将需要改变的直接置为'a'
        int index = needChange[0];
        s[index] = 'a';
        s[s.size()-1-index] = 'a';
        ops--;
    }
    if(ops==2){
        i=0;
        j=s.size()-1;
        while(ops>=2 && i<j){
            if(s[i]!='a'){
                s[i] = 'a';
                s[j] = 'a';
                ops-=2;
            }
            ++i;
            --j;
        }
    }
    if(ops>0 && s.size()%2 == 1){
        s[s.size()/2] = 'a';
    }
    cout<<s<<endl;
    return 0;
}