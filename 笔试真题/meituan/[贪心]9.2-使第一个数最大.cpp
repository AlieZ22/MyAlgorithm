#include <iostream>
using namespace std;

/*
小美拿到一个数组，每次可以进行如下操作之一：
1, 选择一个元素，使其乘以2
2, 选择一个元素，使其除以2，向下取整
小美希望第一个元素变成所有元素的最大值，判断需要操作多少次？
*/

typedef long long LL;
const int N = 1e5 + 10;
LL arr[N];
int n;
LL maxV = 0;

// 通过：83%

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
        if(arr[i] > maxV){
            maxV = arr[i];
        }
    }
    int opts = 0;
    while(arr[0] < maxV){
        arr[0] = arr[0] * 2;
        ++opts;
    }
    cout<<opts<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")