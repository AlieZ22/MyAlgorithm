#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// ac：37%

const int N = 10e5+1;
int s_time;    // 小美的全局时间
int e_time;
int a[N] = {0};        // 在i时刻能够看到的流星数
int b[N] = {0};        // 差分数组，[l,r] + c
int starTime[N][2];    // 所有流星的开始-结束
int n;

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}

int main(){
    int time;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> time;
        starTime[i][0] = time;
    }
    for (int i = 1; i <= n; ++i){
        cin >> time;
        starTime[i][1] = time;
    }
    for (int i = 1; i <= n; ++i){
        insert(starTime[i][0], starTime[i][1], 1);
    }
    int maxN = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i){
        a[i] = a[i - 1] + b[i];
        if(a[i] == maxN){
            ++cnt;
        }
        if(maxN < a[i]){
            maxN = a[i];
            cnt = 1;
        }
    }
    cout << maxN << " " << cnt << endl;
    return 0;
}

/*
3
1 2 5
3 6 7
>> 2 4
*/