#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

class Solution_hot3 {
public:
    bool isRepeat(unordered_map<char,int>& umap){
        for(auto it=umap.begin(); it!=umap.end(); ++it){
            if(it->second > 1) return true;
        }
        return false;
    }
    // 滑动窗口，j一直增长，i在重复的时候缩小至不重复
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int maxLen = 0;
        int i=0, j=0;
        for(; j<s.size(); ++j){
            ++umap[s[j]];
            while(i<j && isRepeat(umap)){
                --umap[s[i++]];
            }
            maxLen = maxLen < (j-i+1)? (j-i+1):maxLen;
        }
        return maxLen;
    }
};