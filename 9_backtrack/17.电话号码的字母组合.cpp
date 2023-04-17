#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* @method: 回溯的选择需要对应到电话号码的字符集，需要提前预定一下
*/

class Solution17 {
public:
    const string letterMap[10] = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs",// 7
        "tuv", // 8
        "wxyz",// 9
    };
    vector<string> res;
    string s;
    string digits;
    // idx 为遍历到digits的哪个位置
    void backtrack(int idx){           // 回溯参数能用简单的int就用简单的，减少拷贝代价
        if(s.size() == digits.size()){
            res.push_back(s);
            return ;
        }
        string choices = letterMap[digits[idx] - '0'];
        for(int i=0; i<choices.size(); ++i){
            s.push_back(choices[i]);
            backtrack(idx+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.size()!=0){
            backtrack(0);
        }
        return res;
    }
};