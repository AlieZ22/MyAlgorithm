#include <iostream>
#include <vector>
using namespace std;

class Solution77 {
public:
    vector<vector<int> > res;
    vector<int> path;
    int k;
    // 保证path中前一个数比后一个数小，这样就不会有重复
    void backtrack(vector<int> choices){
        if(path.size() == k){
            res.push_back(path);
            return ;
        }
        for(int i=0; i<choices.size(); ++i){
            if(path.size()==0 || choices[i] > path[path.size()-1]){       // 简单剪枝
                path.push_back(choices[i]);
                vector<int> new_choices(choices);
                new_choices.erase(new_choices.begin()+i);                 // 注意别删成choices.begin()+i了
                backtrack(new_choices);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        vector<int> nums(n);
        for(int i=1;i<=n;++i){
            nums[i-1]=i;
        }
        backtrack(nums);
        return res;
    }
};

int main(){
    Solution77 s;
    auto res = s.combine(4,2);
    return 0;
}