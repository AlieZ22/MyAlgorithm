#include <iostream>
#include <vector>
using namespace std;

class Solution216 {
public:
    vector<vector<int> > res;
    int k;
    int getSum(vector<int> &nums){
        int s = 0;
        for(auto& item: nums){
            s+=item;
        }
        return s;
    }
    // 从大于pre后面开始选择
    void backtrack(vector<int> path, int pre, int n){
        if(path.size() == k){
            if(getSum(path) == n){
                res.push_back(path);
            }
            return;
        }
        for(int i=pre+1; i<=9; ++i){
            path.push_back(i);
            backtrack(path, i, n);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        vector<int> path;
        backtrack(path, 0, n);
        return res;
    }
};