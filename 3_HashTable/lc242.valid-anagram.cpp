#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
* @method: 1， 哈希表统计单词，对比哈希表；2，快排，然后对比排序后的字符串
* @evaluation: 1, O(n)；2，O(logn)
*/

class Solution242 {
public:
    void quicksort(vector<char>& vec, int l, int r){
        if(l >= r) return;

        int i = l -1, j = r + 1, x = vec[(l+r) >> 1];
        while(i<j){
            do i++; while(vec[i] < x);
            do j--; while(vec[j] > x);
            if(i < j) swap(vec[i], vec[j]);
        }

        quicksort(vec, l, j);
        quicksort(vec, j+1, r);
    }

    bool isAnagram(string s, string t) {
        // 方式1：哈希表对比
        unordered_map<char, int> cnt_cs, cnt_ct;
        if(s.size() != t.size()) return false;
        int n = s.size();
        for(int i=0; i<n; ++i){
            ++cnt_cs[s[i]];
            ++cnt_ct[t[i]];
        }
        if(cnt_cs.size() != cnt_ct.size()) return false;
        for(auto& kv: cnt_cs){
            if(kv.second != cnt_ct[kv.first]) return false;
        }
        return true;

        // 方式2：快排，对比排序后的string
        // if(s.size() != t.size()) return false;
        // int n = s.size();
        // vector<char> vecS(n);
        // vector<char> vecT(n);
        // for(int i=0; i<n; ++i){
        //     vecS[i] = s[i];
        //     vecT[i] = t[i];
        // }
        // quicksort(vecS, 0, n-1);
        // quicksort(vecT, 0, n-1);
        // for(int i=0; i<n; ++i){
        //     if(vecS[i] != vecT[i]) return false;
        // }
        // return true;
    }
};