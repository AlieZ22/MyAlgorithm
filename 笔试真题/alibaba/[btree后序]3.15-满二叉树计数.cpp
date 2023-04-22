#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n;
int l, r;
typedef pair<int,int> PII;     // 左右孩子
PII node[N];
int d[N];     // 存所有节点的入度
int res=0;
bool isManNode[N]; 

// 左右孩子高度相同且都是满二叉树节点

int getHeight(int k){
    // 叶子节点
    if(node[k].first == node[k].second && node[k].first == -1){
        isManNode[k] = 1;
        ++res;
        return 1;
    }
    // 判断k是否为满二叉树节点
    int left_h = node[k].first==-1? 0 :getHeight(node[k].first);
    int right_h = node[k].second==-1? 0:getHeight(node[k].second);
    if(isManNode[node[k].first] && isManNode[node[k].second] && left_h == right_h){
        isManNode[k]=1;
        ++res;
    }
    return max(left_h, right_h)+1;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d %d", &l, &r);
        node[i].first = l;
        node[i].second = r;
        d[l]++;
        d[r]++;
    }
    // 注意：题中并没有确定root节点
    int rt=1;
    for(int i=1;i<=n;++i){
        if(d[i]==0){
            rt = i;
            break;
        }
    }
    getHeight(rt);
    cout<<res<<endl;
    return 0;
}
