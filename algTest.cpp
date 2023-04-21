#include <bits/stdc++.h>
using namespace std;

const int M = 7;

// 尝试用delete释放malloc分配的内存
int main(){
    int *nums;
    nums = (int*)malloc(sizeof(int)*M);
    for(int i=0;i<M;++i){
        nums[i]=i;
    }
    delete [] nums;
    cout<< "end" << endl;
    return 0;
}