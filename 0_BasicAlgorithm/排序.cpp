#include <bits/stdc++.h>
using namespace std;

// 各种排序：冒泡，归并，插入，选择，快排，堆排
/*
6
1 8 4 0 3 4
*/
const int N = 1e5+10;
int arr[N];
int n;

void bubblesort(int l, int r){
    for(int i=l; i<=r; ++i){
        for(int j=l; j<r-i; ++j){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

int tmp[N];
void mergesort(int l, int r){
    if(l>=r) return;
    int mid = (r-l)/2 + l;
    mergesort(l, mid);
    mergesort(mid+1, r);
    int i=l, j=mid+1, k=0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        tmp[k++] = arr[i++];
    }
    while(j<=r){
        tmp[k++] = arr[j++];
    }
    // 将tmp赋值回arr
    k=0;
    for(int i=l; i<=r; ++i){
        arr[i] = tmp[k++];
    }
}

void insertsort(int l, int r){
    int i, j;
    for(i=l+1; i<=r; ++i){
        j=i-1;
        int x = arr[i];
        while(j>=l && arr[j] > x){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

// 每次选择最大的放到最后
void selectsort(int l, int r){
    int i, j;
    for(j=r; j>l; --j){
        int maxIdx=0;
        for(i=l; i<=j; ++i){
            if(arr[maxIdx] < arr[i]){
                maxIdx = i;
            }
        }
        swap(arr[maxIdx], arr[j]);
    }
}


// 堆排序
void adjustNode(int k, int len){
    int left = 2*k+1, right = 2*k+2;
    int maxIdx = k;
    if(left < len && arr[left] > arr[maxIdx]){
        maxIdx=left;
    }
    if(right < len && arr[right] > arr[maxIdx]){
        maxIdx=right;
    }
    if(maxIdx != k){
        swap(arr[k], arr[maxIdx]);
        adjustNode(maxIdx, len);
    }
}

void buildMaxHeap(){
    for(int k=n/2; k>=0; --k){
        adjustNode(k, n);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", &arr[i]);
    }
    buildMaxHeap();
    // 每次把最大的放到末尾
    int len = n;
    for(int i=n-1;i>0;--i){
        swap(arr[0], arr[i]);
        len--;
        adjustNode(0,len);
    }
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}