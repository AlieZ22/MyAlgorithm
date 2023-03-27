#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

class Solution_hot3 {
public:
    // 滑动窗口，j一直增长，i在重复的时候缩小至不重复
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> umap;
        int maxLen = 0;
        int i=0, j;
        for(j=0; j<s.size(); ++j){
            ++umap[s[j]];
            while(i<j && umap[s[j]]>1){         // 只需要检查umap[s[j]]即可，因为之前的umap肯定都不大于1
                --umap[s[i]];
                ++i;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};