#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
* @method: 找字母异位词，用string做位标记索引到哈希表中；或者排序，记录之前的下标
* @evaluation: O(nk)   k为strs字符串中的最大长度
*/

class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string& s: strs){
            string temp(26, '0');
            for(char& c: s){
                ++temp[c-'a'];
            }
            umap[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& kv: umap){
            res.push_back(kv.second);
        }
        return res;
    }
};