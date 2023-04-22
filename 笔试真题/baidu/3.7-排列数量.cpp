/*
排列数量：
排列的定义： 1到k，每个数都出现过且恰好出现1次，被称为一个长度为k的排列
例如 [2,1,3]，[4,3,2,1] 都是排列。
输入：
有多组数据，首先输入一个正整数T，表示有T组数据。
每组数据的第一行输入一个正整数n，代表排列的大小
每组数据的第二行输入n个正整数ai，代表小红拿到的排列。
输出：
一个整数，表示有多少区间能构成一个排列
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 1;
int t,n;
typedef pair<int, int> PII;         // 值-原下标(从1开始)
PII arr[N];

int main()
{
    scanf("%d", &t);
    int tmp;
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i){
            scanf("%d", &tmp);
            arr[i].first = tmp;
            arr[i].second = i;
        }
        sort(arr+1, arr + n + 1);
        int res = 0;
        int maxIndex = 0;
        int minIndex = N;
        for (int i = 1; i <= n; ++i){
            int index = arr[i].second;
            maxIndex = max(maxIndex, index);
            minIndex = min(minIndex, index);
            if(maxIndex-minIndex+1 == i){      // 原来最大下标-原来最小下标 == 元素的个数
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}