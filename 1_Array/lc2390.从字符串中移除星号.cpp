#include <iostream>
#include <string>
using namespace std;

// 输入："leet**cod*e"
// 输出："lecoe"
class Solution2390 {
public:
    // 不用栈，双指针解法
    string removeStars(string s) {
        int fast = 0, slow = 0;
        for(; fast<s.size(); ++fast){
            if(s[fast] == '*' && slow > 0){
                --slow;
            }
            if(s[fast] != '*'){
                s[slow++] = s[fast];
            }
        }
        return s.substr(0, slow);
    }
};