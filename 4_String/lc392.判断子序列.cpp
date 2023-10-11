#include <iostream>
#include <string>
using namespace std;

class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for(; j<t.size(); ++j){
            if(s[i] == t[j]){
                ++i;
            }
            if(i == s.size()) break;
        }
        return i==s.size() ? true: false;
    }
};