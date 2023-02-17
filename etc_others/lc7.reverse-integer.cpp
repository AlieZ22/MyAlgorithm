#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
* @method: 取余存储，注意符号、溢出的处理，用long类型来存储
*/

class Solution7 {
public:
    int reverse(int x) {
        // 记录符号
        long tmpx = x;
        bool isNeg = false;
        if(tmpx < 0){
            isNeg = true;
            tmpx = - tmpx;
        }
        // 反转
        vector<int> ivec;
        while(tmpx != 0){
            ivec.push_back(tmpx%10);
            tmpx = tmpx/10;
        }
        long res = 0;
        for(int i=0; i<ivec.size(); ++i){
            res = res*10;
            res += ivec[i];
        }
        // 判断是否溢出
        if(isNeg){
            res = -res;
        }
        if(res < - pow(2,31) || res > pow(2,31)-1){
            res=0;
        }
        return res;
    }
};