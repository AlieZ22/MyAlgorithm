#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
* @solution: 本质上还是进制转换的模拟
*/

class Solution1017 {
public:
    string baseNeg2(int n) {
        if(n==0 || n==1){
            return to_string(n);
        }
        string s;
        while(n!=0){
            int remainder = n&1;    // 取最后一位
            s.push_back('0'+remainder);
            n -= remainder;
            n /= -2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};