#include <iostream>
#include <vector>
using namespace std;

const int N = 10001;
int node[N];
int fa[N];
int n;
int res = 0;

int findLeft(int root){
    return 2 * root + 1;
}

int findRight(int root){
    return 2 * root + 2;
}

vector<int> dfs(int root){      // 返回子树的 (红，蓝)数
    if(root >= n) 
        return vector<int>();
    vector<int> vec(2);
    if(findLeft(root) >= n && findRight(root) >= n){    // 叶子节点
        ++res;
        if(node[root] == 1)
            vec[0] = 1;
        if(node[root] == 0)
            vec[1] = 1;
        return vec;
    }
    vector<int> left;
    vector<int> right;
    if(findLeft(root) < n)
        left = dfs(findLeft(root));
    if(findRight(root) < n){
        right = dfs(findRight(root));
    }
    int red = 0, blue = 0;
    if(left.size()!=0){
        red += left[0];
        blue += left[1];
    }
    if(right.size()!=0){
        red += right[0];
        blue += right[1];
    }
    if(red == blue)
        res++;
    vector<int> tmp(2);
    tmp[0] = red;
    tmp[1] = blue;
    return tmp;
}

int main(){
    char c;
    int x;
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin >> c;
        if(c == 'R') node[i] = 1;
        if(c == 'B') node[i] = 0;
    }
    for (int i = 1; i < n; ++i){
        cin >> x;
        fa[i] = x - 1;
    }
    vector<int> vec = dfs(0);
    cout << res << endl;
    return 0;
}



/*
6
RBRRBR
1 1 2 2 3

>> 4
*/