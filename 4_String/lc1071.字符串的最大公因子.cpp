#include <iostream>
#include <string>
using namespace std;

class Solution1071 {
public:
    // 找到一个字符串的最小构成串
    string findComponent(string str){
        if(str.size() == 0) return "";
        int i=0, j=0;
        int n = str.size();
        for(int k=1; k<n; ++k){
            if(str[k] == str[i]){  // 启动验证
                int size = j - i + 1;
                if((n-size) % size != 0){
                    ++j;
                    continue;
                }
                int _j = i;
                int _k = k;
                while(str[_j] == str[_k]){
                    _j = (_j + 1) % size;
                    _k++;
                }
                if(_k == n){
                    return str.substr(i, j-i+1);
                }
            }
            j++;
        }
        return str.substr(i, j-i+1);
    }

    int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2) {
        // 得到最小构成子串
        string component1 = findComponent(str1);
        string component2 = findComponent(str2);

        if(component1 == component2){
            // 还需要判断最小构成子串是否能扩充
            int size = component1.size();
            int cnt1 = str1.size() / size;
            int cnt2 = str2.size() / size;
            // 取cnt1, cnt2 最大公约数，来做最小构成子串的扩充
            int g = gcd(cnt1, cnt2);
            string res;
            while(g--){
                res += component1;
            } 
            return res;
        }else{
            return "";
        }
    }
};