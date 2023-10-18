#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1657 {
public:
    // 转化的条件：（1）字符集相同；（2）字符频次相同（字符出现次数排序，结果一致）
    bool closeStrings(string s1, string s2) {
        vector<int> c1(26, 0), c2(26, 0);
        for (char c : s1) c1[c - 'a']++;
        for (char c : s2) c2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (c1[i] + c2[i] == 0) continue;
            if (c1[i] == 0 || c2[i] == 0) return false;
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        for (int i = 0; i < 26; i++) {
            if (c1[i] != c2[i]) return false;
        }
        return true;
    }
};