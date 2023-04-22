#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
vector<vector<int>> policy;
map<vector<int>, int> mapvec;          // 注意要用map，因为unordered_map不能将vector作为key


// num:当前选择的个数
void dfs(vector<int>& choices, vector<int> selected){
    if(selected.size() == m){
        sort(selected.begin(), selected.end());
        if(mapvec[selected]==0){
            policy.push_back(selected);
            mapvec[selected]++;
        }
        return;
    }
    for(int i=0; i<choices.size(); ++i){
        selected.push_back(choices[i]);
        vector<int> new_choices(choices);
        new_choices.erase(new_choices.begin()+i);
        dfs(new_choices, selected);
        selected.pop_back();
    }
}

void echoPolicy(){
    for(int i=0; i<policy.size(); ++i){
        for(int j=0; j<policy[i].size(); ++j){
            cout<<policy[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    vector<int> choices_vec;
    for(int i=1;i<=n;++i){
        choices_vec.push_back(i);
    }
    vector<int> select_vec;
    dfs(choices_vec, select_vec);
    echoPolicy();
    return 0;
}