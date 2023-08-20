#include<bits/stdc++.h>
using namespace std;

class Solution6450 {
public:
    bool visited[101] = {false};
    int minimumSum(int n, int k) {
        int sum = 0;
        int i = 1, cnt = 0;
        while(cnt != n){
            if(!visited[i]){
                sum+=i;
                ++cnt;
                if(i<=k) visited[k-i] = true;
            }
            ++i;
        }
        return sum;
    }
};