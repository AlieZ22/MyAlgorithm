#include <bits/stdc++.h>
using namespace std;

// 100%

const int M = 1e9+7;
int n;
long res = 1;
string s;

// 交换节点k的左右孩子，k节点的孩子s[left],右孩子s[right]
void swapNodes(int k){
    int left = 2*k;
    int right = 2*k+1;
    if(s[left] != s[right]){
        res+=(res % M);
        res = res % M;
    }
}

void traversal(int treeSize){
    int lastNYNode = treeSize/2;       // 最后一个非叶节点
    for(int i=lastNYNode; i>=1; --i){
        swapNodes(i);
    }
}

int main(){
    scanf("%d", &n);
    int treesize = pow(2,n)-1;
    s.resize(treesize+1);
    for(int i=1; i<=treesize; ++i){
        cin>>s[i];
    }
    traversal(pow(2,n)-1);
    cout<<res<<endl;
    return 0;
}