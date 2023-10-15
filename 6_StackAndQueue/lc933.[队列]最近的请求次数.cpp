#include <iostream>
#include <queue>
using namespace std;

// 写一个 RecentCounter 类来计算特定时间范围内最近的请求。
class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while(t - q.front() > 3000){
            q.pop();
        }
        return q.size();
    }
};