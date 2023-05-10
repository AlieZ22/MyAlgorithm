#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* @method: 遵循回溯三部曲，提前剪枝防止冗余的回溯
*/

class Solution131 {
public:
    vector<vector<string>> res;
    vector<string> path;
    // @function: 检查s是否为回文串
    bool checkStr(const string& s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    // @param: idx, 当前回溯的下标的值
    void backtrack(const string& s, int idx){
        if(idx == s.size()){
            res.push_back(path);
            return ;
        }
        // 检验满足再加入path，减少回溯
        for(int i=idx; i<s.size(); ++i){
            string subs = s.substr(idx, i-idx+1);
            if(checkStr(subs)){
                path.push_back(subs);
                backtrack(s,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
};
