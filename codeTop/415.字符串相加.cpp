#include <iostream>
#include <string>
using namespace std;

/*
* @method: char，int互转，进位记录
*/

class Solution_hot415 {
public:
    int toNum(char c){
        return c-'0';
    }
    char toChar(int i){
        return i+'0';
    }
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()) return addStrings(num2, num1);
        // 保证num1的length更大
        int i = num1.size()-1, j = num2.size()-1;
        int up = 0;
        int tmp = 0;
        while(i>=0 && j>=0){
            tmp = (toNum(num1[i]) + toNum(num2[j]) + up);
            num1[i] = toChar(tmp % 10);
            up = tmp / 10;
            --i;
            --j;
        }
        // 取i剩下的
        while(i>=0){
            tmp = (toNum(num1[i]) + up);
            num1[i] = toChar(tmp % 10);
            up = tmp / 10;
            --i;
        }
        // 检查最后进位
        if(up!=0){
            num1.resize(num1.size()+1);
            for(int j = num1.size()-1; j>0; --j){
                int i = j-1;
                num1[j] = num1[i];
            }
            num1[0] = toChar(up);
        }
        return num1;
    }
};