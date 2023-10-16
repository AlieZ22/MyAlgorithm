#include <iostream>
#include <stack>
using namespace std;

// 当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
// 例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。
class StockSpanner {
private:
    stack<pair<int, int>> sp;
    int idx = -1;
public:
    StockSpanner() {
        sp.push({INT_MAX, -1});
    }
    
    int next(int price) {
        ++idx;
        while(price >= sp.top().first){
            sp.pop();
        }
        // 获得坐标差
        int ret = idx - sp.top().second;
        sp.push({price, idx});
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */