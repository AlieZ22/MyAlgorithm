#include <iostream>
#include <string>
using namespace std;

/*
* @method: char，int互转，进位记录，反转res
*/

class Solution_hot415 {
public:
    // 存到一个string里面，然后reverse
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int jin = 0;         // 进位
        while(i>=0 || j>=0){
            int tmp = jin;
            if(i>=0){ tmp += (num1[i--] - '0'); }
            if(j>=0){ tmp += (num2[j--] - '0'); }
            jin = tmp / 10;
            char c = char((tmp % 10) + '0');
            res += c;
        }
        if(jin != 0){
            res += char(jin + '0');
        }
        reverseStr(res);
        return res;
    }

    void reverseStr(string& s){
        int i=0; 
        int j=s.size()-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
};