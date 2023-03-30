#include <bits/stdc++.h>
using namespace std;

string s;        // 十六进制数
unordered_map<char, int> umap;

void initMap(){
    for(int i=0; i<=9; ++i){
        umap[char(i+'0')] = i;
    }
    umap['A'] = 10; umap['a'] = 10;
    umap['B'] = 11; umap['b'] = 11;
    umap['C'] = 12; umap['c'] = 12;
    umap['D'] = 13; umap['d'] = 13;
    umap['E'] = 14; umap['e'] = 14;
    umap['F'] = 15; umap['f'] = 15;
}

// 进制转换，将16进制的数转化为10进制
int main(){
    cin>>s;
    initMap();
    int res = 0;
    int j = 0;
    for(int i=s.size()-1; i>=2; --i){
        res += umap[s[i]]*pow(16,j++);
    }
    cout<<res<<endl;
    return 0;
}
