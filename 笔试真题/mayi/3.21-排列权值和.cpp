#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
const int M = 1e9+7;
int n;
long long res = 0;

void checkVec(vector<int>& vec){
    if(vec.size() <= 1) return;
    for(int i=1;i<vec.size();++i){
        if(vec[i]%2==1 && vec[i-1]%2==1){
            res = (res%M)+1;
            res = (res%M);
        }
    }
}

// 回溯
void backtracK(vector<int>& choices, vector<int> curr){
    if(curr.size() == n){
        checkVec(curr);
        return ;
    }
    for(int i=0; i<choices.size(); ++i){
        curr.push_back(choices[i]);
        vector<int> new_choices(choices);
        new_choices.erase(new_choices.begin()+i);
        backtracK(new_choices, curr);
        curr.pop_back();
    }
}

int main(){
    scanf("%d", &n);
    vector<int> vec;
    for(int i=1;i<=n;++i){
        vec.push_back(i);
    }
    vector<int> vv;
    backtracK(vec,vv);
    cout<<res<<endl;
    return 0;
}