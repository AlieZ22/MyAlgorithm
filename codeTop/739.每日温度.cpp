#include <bits/stdc++.h>
using namespace std;

/*
单调栈：存放下标，
[循环]当前温度与栈顶下标对应温度对比，如果更大则遇到更高温度，取 i-s.top()
*/

class Solution_hot739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i=0; i<n; ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};