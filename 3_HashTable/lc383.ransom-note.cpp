#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
* @method: [简单] 用哈希表存一下Magazine的字符，检验赎金信的string
* @evaluation: O(n+m)
*/

class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cnt_umap;
        for(char& c: magazine){
            ++cnt_umap[c];
        }
        for(char& c: ransomNote){
            if(cnt_umap[c]<=0) return false;
            --cnt_umap[c];
        }
        return true;
    }
};