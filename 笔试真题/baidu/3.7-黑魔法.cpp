/*
魔法师：前缀和(ac较少,超时)，前缀积
魔法师小树有n个魔法元素，排成一行，每个魔法元素的能量值是一个非零整数ai
小树每次施展魔法的方式是挑选一段连续非空的魔法元素，将它们的能量值乘起来，得到值就是这次魔法的总能量。
如果总能量大于零即为白魔法，否则为黑魔法。
小树可以施展的白魔法或者黑魔法的方案数各有多少。两个方案不同是指挑选的连续区间不同
示例：
5
5 -3 3 -1 1
>> 8 7
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 1;
int n;
int arr[N];
int s[N];   // 前缀和

int main()
{
    scanf("%d", &n);
    int tmp;
    // 负数为1，正数为0，那么根据1的个数就可以判断结果是正还是负
    for (int i = 1; i <= n; ++i){
        scanf("%d", &tmp);
        if(tmp > 0) arr[i] = 0;
        else arr[i] = 1;
    }
    for (int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + arr[i];
    }
    int cnt_black = 0, cnt_write = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            if((s[i] - s[j-1])%2==1){
                ++cnt_black;
            }else{
                ++cnt_write;
            }
        }
    }
    cout << cnt_black << " " << cnt_write << endl;
    return 0;
}