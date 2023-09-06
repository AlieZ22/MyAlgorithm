#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

// 由C(0, n) + C(1,n) + C(2, n) + ... + C(n, n) = (2^n)
// 可得：C(1,n) + C(2, n) + ... + C(n, n) = (2^n) - 1

int main() {
    string s;
    cin >> s;
    unordered_set<char> uset;

    for(char c: s){
        uset.insert(c);
    }

    int ans = pow(2, uset.size()) -1;
    cout<<ans<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")