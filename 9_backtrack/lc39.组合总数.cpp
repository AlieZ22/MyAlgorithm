#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* @method: 回溯 + int单增剪枝
*/

class Solution39 {
public:
    int target;
    vector<vector<int>> res;
    vector<int> path;
    // idx保证取值顺序单增，剪枝
    void backtrack(vector<int>& candidates, int idx, int sum){
        if(sum==target){
            res.push_back(path);
            return ;
        }
        for(int i=idx; i<candidates.size(); ++i){
            if(sum+candidates[i] > target){
                break;
            }
            path.push_back(candidates[i]);
            backtrack(candidates, i, sum+candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 并没有说candidates是排好序的，sort为了更好的剪枝
        sort(candidates.begin(), candidates.end());
        this->target = target;
        backtrack(candidates, 0, 0);
        return res;
    }
};