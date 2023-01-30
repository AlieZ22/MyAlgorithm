#include<iostream>
#include<unordered_set>
using namespace std;

class Solution202 {
public:
    int getSum(int m){
        int sum = 0;
        while(m){
            sum += (m%10)*(m%10);
            m /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // 主要是要防止无限循环，当循环到某一个数时就返回false
        unordered_set<int> visited;
        while(n!=1){
            visited.insert(n);
            n = getSum(n);
            if(visited.count(n)){
                return false;
            }
        }
        return true;
    }
};
