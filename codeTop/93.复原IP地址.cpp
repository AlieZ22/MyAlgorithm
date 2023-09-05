#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 回溯，穷举所有ip地址
class Solution_hot93 {
public:
    const static int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;

    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }

    // 总共要得到四个段，segId为段ID，segStart为该段起始的下标
    void dfs(const string& s, int segId, int segStart){
        // 找到了4段IP地址，并且遍历完字符串（题目说恰好4个数字），就找到了答案
        if(segId == SEG_COUNT){
            if(segStart == s.size()){
                string ipAddr;
                for(int i=0; i<SEG_COUNT; ++i){
                    ipAddr += to_string(segments[i]);
                    if(i != SEG_COUNT - 1){
                        ipAddr += '.';
                    }
                }
                ans.emplace_back(ipAddr);
            }
            return ;
        }

        // 如果没找到4段就遍历完了字符串，结束
        if(segStart == s.size()){ return ; }

        // 如果当前数字为0，因为不能有前导0，所以直接生成一段
        if(s[segStart] == '0'){
            segments[segId] = 0;
            dfs(s, segId+1, segStart+1);
        }

        // 一般情况，枚举
        int addr = 0;
        for(int idx = segStart; idx < s.size(); ++idx){
            addr = addr * 10 + (s[idx] - '0');
            if(addr > 0 && addr <= 0xFF){
                segments[segId] = addr;
                dfs(s, segId+1, idx+1);
            }else{
                break;
            }
        }
    }
};