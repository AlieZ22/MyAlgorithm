#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
* @method: string做位标记，固定窗口滑动
* @evaluation: O(n+m)
*/

class Solution438 {
public:
    vector<int> findAnagrams(string s, string p) {
        // 异位词长度肯定是一样的，就用一个固定size的窗口滑过去就行
        // 用string做位标记，判断是否为异位词
        string signP(26, '0');
        string signTemp(26, '0');
        for(char& c: p){
            ++signP[c-'a'];
        }
        vector<int> res;
        int lenS=s.size(), lenP=p.size();
        if(lenS < lenP) return res;
        // 初始化窗口
        int i=0, j=lenP-1;
        for(int k=i;k<=j;++k){
            ++signTemp[s[k]-'a'];
        }
        // 滑动窗口
        if(signTemp == signP){
            res.push_back(i);
        }
        for(i=1, j=lenP; j<lenS; ++i, ++j){
            --signTemp[s[i-1]-'a'];      // 注意要减1，是之前的去掉
            ++signTemp[s[j]-'a'];
            if(signTemp == signP){
                res.push_back(i);
            }
        }
        return res;
    }
};