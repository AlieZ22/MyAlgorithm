#include <iostream>
#include <vector>
using namespace std;

/*
* @method:回溯，还是要记忆这种统一写法
*/

class Solution_hot46 {
public:
    vector<vector<int> > res;
    vector<int> path;
    void backtrack(vector<int>& choices){
        if(choices.size()==0){
            res.push_back(path);
        }
        for(int i=0;i<choices.size();++i){
            vector<int> newChoices(choices);
            newChoices.erase(newChoices.begin()+i);
            path.push_back(choices[i]);
            backtrack(newChoices);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return res;
    }
};