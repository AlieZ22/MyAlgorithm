#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10;

// 快速排序 练习
void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i<j){
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if(i<j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

// 归并排序 练习
int tmp[N];
void merge_sort(int q[], int l, int r)
{
    if(l >= r)
        return;

    int mid = (r - l) / 2 + l;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i<=mid && j<=r){
        if(q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while(i<=mid)
        tmp[k++] = q[i++];
    while(j<=r)
        tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    int arr[N] = {8, 1, 9, 10, 83, 234, 12, 12, 13, 15};
    merge_sort(arr, 0, N-1);
    cout << "after sort: ";
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}