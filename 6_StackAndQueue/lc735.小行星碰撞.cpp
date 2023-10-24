#include <iostream>
#include <vector>
using namespace std;

class Solution735 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;       // 用vector模拟栈
        for (auto aster : asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !st.empty() && st.back() > 0) {
                alive = st.back() < -aster; // aster 是否存在
                if (st.back() <= -aster) {  // 栈顶行星爆炸
                    st.pop_back();
                }
            }
            if (alive) {
                st.push_back(aster);
            }
        }
        return st;
    }
};