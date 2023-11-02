#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution2103 {
public:
    int countPoints(string rings) {
        set<int> set_R;
        set<int> set_G;
        set<int> set_B;
        // 加入集合
        for(int i=0; i<rings.size(); i+=2){
            char color = rings[i];
            int idx = rings[i+1] - '0';
            if(color == 'R'){
                set_R.insert(idx);
            }else if(color == 'G'){
                set_G.insert(idx);
            }else{
                set_B.insert(idx);
            }
        }
        // 求三个集合的交集，右值引用消除拷贝开销
        set<int> insec = findInsection(move(findInsection(set_R, set_G)), set_B);
        return insec.size();
    }

    set<int> findInsection(const set<int>& s1, const set<int>& s2){
        set<int> res;
        for(int item: s1){
            if(s2.count(item)){
                res.insert(item);
            }
        }
        return res;
    }
};