#include <bits/stdc++.h>
using namespace std;

class Word{
public:
    string str;
    int cnt;
    Word(string s, int c){
        this->str = s;
        this->cnt = c;
    }
};

bool cmp(Word w1, Word w2){
    if(w1.cnt != w2.cnt){
        return w1.cnt > w2.cnt;
    }
    if(strcmp(w1.str.c_str(), w2.str.c_str()) <= 0){
        return true;
    }else{
        return false;
    }
}

string s;
unordered_map<string, int> umap;
vector<Word> vec;

int main(){
    getline(std::cin, s);
    int n = s.size();
    int start = 0;
    // 拆分字符串
    for(int i=0; i<n; ++i){
        if(s[i] == ' '){
            string tmp = s.substr(start, i-start);
            start = i + 1;
            umap[tmp]++;
        }else if(i == n-1){
            string tmp = s.substr(start, i+1-start);
            umap[tmp]++;
        }
    }
    // 遍历umap
    for(auto kv: umap){
        if(kv.second >= 3){
            Word w(kv.first, kv.second);
            vec.push_back(w);
        }
    }
    // 排序
    sort(vec.begin(), vec.end(), cmp);
    // 输出
    for(Word w: vec){
        cout<< w.str << endl;
    }

    return 0;
}
