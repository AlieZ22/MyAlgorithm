#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
一个数组删除k个元素，使得剩余元素两两之间互为倍数关系，一共多少删除方案？
*/

// 通过：25%

const int N = 1e9 + 7;
int n, k;
int res = 0;

bool isBeiShu(int a, int b){
    int minV = a <= b? a: b;
    int maxV = a <= b? b: a;
    if(maxV % minV == 0){
        return true;
    } else{
        return false;
    }
}

bool checkArr(vector<int>& path){
    // 做一个新数组，检查两两元素是否为倍数
    for(int i=0; i<path.size(); ++i){
        for(int j=i+1; j<path.size(); ++j){
            if(!isBeiShu(path[i], path[j])){
                return false;
            }
        }
    }
    return true;
}

// 选择n-k个元素，他们互为倍数
void backtrack(vector<int>& arr, vector<int>& path, int idx){   // delNum 表示已经删除的元素个数
    if(path.size() == n-k){
        if(checkArr(path)){
            res = (res + 1) % N;
        }
        return ;
    }
    for(int i=idx; i<n; ++i){
        path.push_back(arr[i]);
        backtrack(arr, path, i+1);
        path.pop_back();
    }
}

int main() {
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    vector<int> path;
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }
    backtrack(arr, path, 0);
    cout<<res<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")