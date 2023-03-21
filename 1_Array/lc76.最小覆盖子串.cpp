#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
* @method: 滑动窗口，end走的时候不满足条件，满足条件时缩小窗口
* @evaluation: O(m+n)
*/

class Solution76 {
public:
    unordered_map<char, int> ori, cnt;

    bool checkMap(){
        for(auto iter = ori.begin(); iter!=ori.end(); ++iter){
            if(cnt[iter->first] < iter->second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size() ) return "";
        for(char &c: t){
            ++ori[c];
        }
        int index=0;
        int start = 0, end = 0, minLen = INT_MAX;
        for(; end < s.size(); ++end){
            ++cnt[s[end]];
            while(checkMap()){
                if(minLen > end-start+1){
                    minLen = end-start+1;
                    index = start;
                }
                --cnt[s[start++]];
            }
        }
        return minLen==INT_MAX? "":s.substr(index, minLen);
    }
};