#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
* @method: 抽出一个单独的函数用于反转固定区间，然后遍历s，找每次需要反转的区间
* @evaluation: O(n)
*/

class Solution541 {
public:
    void reverseSubStr(string& s, int l, int r){
        while(l < r){
            swap(s[l++], s[r--]);
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0, j=0; i < n; i+=2*k){
            j = min(n-1, i+k-1);
            reverseSubStr(s,i,j);
        }
        return s;
    }
};