#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

class Solution_hot20 {
public:
    unordered_map<char, int> match;
    void initMatch(){
        match['('] = -3; match['{'] = -2; match['['] = -1;
        match[')'] = 3; match['}'] = 2; match[']'] = 1;
    }
    bool isValid(string s) {
        initMatch();
        stack<char> sc;
        for(int i=0; i<s.size(); ++i){
            if(match[s[i]] < 0){
                sc.push(s[i]);
            }else{
                if(sc.empty() || match[sc.top()] + match[s[i]] != 0){
                    return false;
                }else{
                    sc.pop();
                }
            }
        }
        return sc.empty()? true: false;
    }
};