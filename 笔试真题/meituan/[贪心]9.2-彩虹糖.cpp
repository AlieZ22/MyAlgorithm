#include <bits/stdc++.h>
using namespace std;

/*
小美有很多彩虹糖，每颗彩虹糖都有一个颜色，她每天吃两颗彩虹糖
如果今天吃的彩虹糖组合是之前没吃过的组合，则小美今天会高兴。

小美想知道，她最多有几天会高兴？
*/

// 通过：10%

const int N = 1e5 + 10;
int n;
int cnt = 0;
map<vector<int>, bool> vecmap;

int main() {
    scanf("%d", &n);
    vector<int> arr(n);
    vector<int> select(n, 0);
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; ++i){
        if(select[i]) continue;
        for(int j=i+1; j<n; ++j){
            if(select[j]) continue;
            vector<int> tmp{arr[i], arr[j]};
            if(!vecmap.count(tmp)){
                ++cnt;
                select[i] = 1;
                select[j] = 1;
                vecmap[tmp] = true;
                //cout<<arr[i]<<" "<<arr[j]<<endl;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}