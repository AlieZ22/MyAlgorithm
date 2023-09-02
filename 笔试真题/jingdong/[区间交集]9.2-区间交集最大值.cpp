#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 通过：100%

typedef long long LL;
LL l1,l2,l3;
LL r1,r2,r3;
LL res = -1;

void insecVec(vector<LL>& v1, vector<LL>& v2){
    // 包含关系
    if(v1[1] >= v2[1]){
        res = max(res, v2[1]*2);
        return ;
    }
    // 交叉关系
    if(v1[1] >= v2[0] && v1[1] <= v2[1]){
        res = max(res, v1[1] * 2);
        return ;
    }
}

int main() {
    scanf("%lld %lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &l3, &r3);
    vector<vector<LL>> nums;
    nums.emplace_back(vector<LL>{l1, r1});
    nums.emplace_back(vector<LL>{l2, r2});
    nums.emplace_back(vector<LL>{l3, r3});
    sort(nums.begin(), nums.end());
    insecVec(nums[0], nums[1]);
    insecVec(nums[1], nums[2]);
    insecVec(nums[0], nums[2]);
    cout<<res<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")