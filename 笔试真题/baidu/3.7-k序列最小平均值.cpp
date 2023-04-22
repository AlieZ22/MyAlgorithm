/*
拆分数组：贪心（前k-1个组都只有一个元素，最后一个组有其他的数）
将长度n的数组划为为k个子序列(每个元素必须在某个子序列中，且只出现一次，子序列中可以有值一样的)，使得k个子序列的平均值的和最小
示例：
4 2
3 2 1 3
>> 划分 [3,1]和[2,3]，最小平均值的和为4.5
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 1;
int n, k;
int arr[N];

void quicksort(int a[], int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while(i<j){
        do ++i; while (a[i] < x);
        do --j; while (a[j] > x);
        if(i<j) swap(a[i], a[j]);
    }
    quicksort(a, l, j);
    quicksort(a, j + 1, r);
}

int main()
{
    scanf("%d %d", &n, &k);
    int tmp;
    for (int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    quicksort(arr, 0, n - 1);
    // sort(arr, arr+n);
    double res = 0;
    double sum = 0;
    for (int i = 0; i < k - 1; ++i){
        res += arr[i];
    }
    for (int i = k - 1; i < n; ++i){
        sum += arr[i];
    }
    res += sum / (n - k + 1);
    printf("%.5lf", res);
    return 0;
}