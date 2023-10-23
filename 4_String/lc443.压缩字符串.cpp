#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
* @method: 空间是够的，可以正向遍历。cnt直接用to_string转化为字符串
*/

class Solution443 {
public:
    int compress(vector<char>& chars) {
        int cnt= 0;
        int n = chars.size();
        // i：读指针；j：写指针
        int j=0;
        for(int i=0; i<n; ++i){
            cnt=1;
            char c = chars[i];
            chars[j++] = c;
            while(i<n-1 && chars[i+1]==c){
                ++i;
                ++cnt;
            }
            if(cnt > 1){
                string s = to_string(cnt);
                for(int k=0; k<s.size(); ++k){
                    chars[j++] = s[k];
                }
            }
        }
        return j;
    }
};