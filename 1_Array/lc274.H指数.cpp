#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution274 {
public:
    int hIndex(vector<int>& citations) {
        // 排序citations数组
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size()-1;
        // 从后往前遍历，如果citations[i]>h说明找到了一篇被引用了至少h+1次的论文，增加h
        while(i>=0 && citations[i]>h){
            h++;
            i--;
        }
        return h;
    }
};